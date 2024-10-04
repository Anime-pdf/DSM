#pragma once

#include <string>
#include <memory>
#include <fstream>
#include <subprocess.hpp>
#undef open
#undef close
#undef fileno

class DDNetServer {
public:
    DDNetServer(const std::string& executablePath, const std::string& logFilePath, bool resetLog = false)
        : m_ExecutablePath(executablePath), m_LogFilePath(logFilePath), m_IsRunning(false), m_ResetLog(resetLog) {}

    virtual ~DDNetServer();

    bool startServer();
    bool stopServer();

    bool isRunning() const;

    std::string getLogs() const;

private:
    bool m_IsRunning;

    std::string m_ExecutablePath;
    std::unique_ptr<subprocess::Popen> m_Process;

    std::string m_LogFilePath;
    std::ofstream m_LogFile;
    std::thread m_LogThread;
    bool m_ResetLog;

    void logOutput();
};
