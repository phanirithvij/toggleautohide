#pragma once
#include <windows.h>
#include <shellapi.h>

namespace TaskBarHelper {
	enum class AppBarMessages
	{
		New = 0x00,
		Remove = 0x01,
		QueryPos = 0x02,
		SetPos = 0x03,
		GetState = 0x04,
		GetTaskBarPos = 0x05,
		Activate = 0x06,
		GetAutoHideBar = 0x07,
		SetAutoHideBar = 0x08,
		WindowPosChanged = 0x09,
		SetState = 0x0a
	};

	enum class AppBarStates
	{
		AutoHide = 0x01,
		AlwaysOnTop = 0x02
	};

	void SetTaskbarState(AppBarStates option);
	AppBarStates GetTaskbarState();
}
