#include "windows.h"
#include <iostream>

static UINT const  broadcastTimeout = 100; // in milliseconds

int main() 
{
	DWORD_PTR result;

	// Broadcast WM_SETTINGCHANGE
	SendMessageTimeout(HWND_BROADCAST,
		WM_SETTINGCHANGE,
		NULL,
		reinterpret_cast<LPARAM>("Environment"),
		SMTO_NORMAL,
		broadcastTimeout,
		&result);
	if (result == 0)
	{
		std::cout << "Environment was successfully refreshed\n";
	}
	else
	{
		std::cerr << "Environment failed to refresh. Error Code: " << result << std::endl;
	}

	return static_cast<int>(result);
}
