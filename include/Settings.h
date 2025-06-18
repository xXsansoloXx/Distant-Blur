#pragma once

#include "PCH.h"

namespace Settings {
	inline const char* setting_path{"Data/SKSE/Plugins/MODNAME.ini"};  // Remember to change this

	void LoadSettings();
	void ResetSettings();

	namespace General {
		inline bool ModToggle = true;
	}
	namespace Maintenance {

	}

}