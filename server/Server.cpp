#include "Server.h"

DDNetServer::~DDNetServer()
{
    if (m_IsRunning) {
        stopServer();
    }
}

bool DDNetServer::startServer() {
    if (m_IsRunning) {
        return false;
    }

    try {
        std::ios::openmode mode = std::ios::out | std::ios::app;
        if (m_ResetLog)
            mode ^= std::ios::app;

        m_LogFile.open(m_LogFilePath, mode);
        if (!m_LogFile.is_open()) {
            return false;
        }

        m_Process = std::make_unique<subprocess::Popen>(std::vector<std::string>{m_ExecutablePath}, subprocess::output{ subprocess::PIPE }, subprocess::error{ subprocess::PIPE });
        m_LogThread = std::thread(&DDNetServer::logOutput, this);
        m_IsRunning = true;
        return true;
    }
    catch (const std::exception& e) {
        std::cout << "Error starting server: " << e.what() << std::endl;
        return false;
    }
}

bool DDNetServer::stopServer() {
    if (!m_IsRunning) {
        return false;
    }

    try {
        m_Process->kill();
        std::cout << "Exit with code " << m_Process->poll() << std::endl;

        m_LogThread.join();
        m_LogFile.close();
        m_IsRunning = false;
        return true;
    }
    catch (const std::exception& e) {
        std::cout << "Error stopping server: " << e.what() << std::endl;
        return false;
    }
}

bool DDNetServer::isRunning() const {
    return m_IsRunning;
}

std::string DDNetServer::getLogs() const {
    std::ifstream logFile(m_LogFilePath);
    std::string logs((std::istreambuf_iterator<char>(logFile)), std::istreambuf_iterator<char>());
    return logs;
}

void DDNetServer::logOutput() {
    std::string line;
    while (m_IsRunning) {
        try {
            auto result = m_Process->communicate();
            std::cout << result.first.buf.data() << std::endl;
            m_LogFile.flush();
        }
        catch (const std::exception& e) {
            std::cout << "Error while logging: " << e.what() << std::endl;
        }
    }
}