#include <ShlObj.h>    // Shell API
#include <atlcomcli.h> // CComPtr & Co.
#include <string>
#include <iostream>
#include <system_error>
#include "Header.h"
#include <cstdio>

// And need to also use WinMain instead of wmain or main for gui apps (which we are setting by /subsystem:windows)
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	using namespace TaskBarHelper;

	if (GetTaskbarState() != AppBarStates::AutoHide) {
		SetTaskbarState(AppBarStates::AutoHide);
	}
	else {
		SetTaskbarState(AppBarStates::AlwaysOnTop);
	}
	return 0;
}

