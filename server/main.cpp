#include "Server.h"
#include <bitset>

int main()
{
	DDNetServer mySrv("D:\\DDNet-18.2-win64\\DDNet-Server.exe", "log_dd.log", true);

	std::cout << "Starting server..." << std::endl;
	mySrv.startServer();

	int i = 0;

	while (true)
	{
		std::cin >> i;

		if (i == 1) {
			std::cout << "Trying to exit..." << std::endl;
			mySrv.startServer();
		}
	}

	std::cout << "I'm alive!" << std::endl;

	//std::ios::openmode modeApp = std::ios::out | std::ios::app;
	//std::ios::openmode modeTrunc = std::ios::out | std::ios::trunc;

	//std::ios::openmode modeNewTrunc = std::ios::out | std::ios::app;
	//modeNewTrunc = modeNewTrunc ^ std::ios::app | std::ios::trunc;


	//std::bitset<sizeof(int) * 8> modeApp_bits(modeApp);
	//std::bitset<sizeof(int) * 8> modeTrunc_bits(modeTrunc);
	//std::bitset<sizeof(int) * 8> modeNewTrunc_bits(modeNewTrunc);

	//std::cout << modeApp_bits << std::endl;
	//std::cout << modeTrunc_bits << std::endl;
	//std::cout << modeNewTrunc_bits << std::endl;

	return 0;
}
