#include "Header.h"

namespace TaskBarHelper {
	// https://stackoverflow.com/a/13685121/8608146
	// backup https://github.com/phanirithvij/taskbarstate
	void SetTaskbarState(AppBarStates option)
	{
		APPBARDATA msgData;
		msgData.cbSize = sizeof(msgData);
		// https://stackoverflow.com/a/53562094/8608146
		msgData.hWnd = FindWindowEx(NULL, NULL, TEXT("System_TrayWnd"), NULL);
		if (msgData.hWnd == NULL) {
			msgData.hWnd = FindWindowEx(NULL, NULL, TEXT("Shell_TrayWnd"), NULL);
		}
		msgData.lParam = (int)(option);
		SHAppBarMessage((DWORD)AppBarMessages::SetState, &msgData);
	}

	AppBarStates GetTaskbarState()
	{
		APPBARDATA msgData;
		msgData.cbSize = sizeof(msgData);
		// https://stackoverflow.com/a/53562094/8608146
		msgData.hWnd = FindWindowEx(NULL, NULL, TEXT("System_TrayWnd"), NULL);
		if (msgData.hWnd == NULL) {
			msgData.hWnd = FindWindowEx(NULL, NULL, TEXT("Shell_TrayWnd"), NULL);
		}
		return (AppBarStates)SHAppBarMessage((DWORD)AppBarMessages::GetState, &msgData);
	}
}