#pragma once

#include "PCH.h"

namespace Settings {
	inline const char* setting_path{"Data/SKSE/Plugins/Distant-Blur.ini"};  // Remember to change this
	//constexpr auto path = L"Data/SKSE/Plugins/CrashLogger.ini";

	void LoadSettings();
	void SaveSettings();
	void ResetSettings();

	namespace General {
		inline bool ModToggle = true;
		
		inline int BlurType = 2; // Default to Universal Blur Type

	}
	namespace Advanced {
		namespace Legacy {
			inline bool WeatherSmoothing = true;

			inline bool InteriorBlurToggle = false;
			inline float InteriorBlurStrength = 0.5f;
			inline float InteriorBlurDistance = 10.0f;
			inline bool InteriorPreliminaryPatch = false;

			inline bool exteriorBlurToggle = true;
			inline float exteriorBlurStrength = 0.5f;
			inline float exteriorBlurDistance = 10.0f;
			inline bool exteriorPreliminaryPatch = false;

		}

		namespace Universal {
			inline float Strength = 0.5f;       // Default strength
			inline float Distance = 10.0f;      // Default distance
		}
	}
	namespace Maintenance {

	}

}