#include "Settings.h"

namespace Settings {
    void LoadSettings() {
        CSimpleIniW ini;
        ini.SetUnicode();

        if (!std::filesystem::exists(setting_path)) {
            logger::info("No {} file found, creating new with default values", setting_path);
            
            ResetSettings();
            SaveSettings();
        } else {
            ini.LoadFile(setting_path);

            General::ModToggle = ini.GetBoolValue(L"General", L"ModToggle", General::ModToggle);
            //ini.SetBoolValue(L"General", L"ModToggle", General::ModToggle, L"; Main Mod Toggle");

			General::BlurType = ini.GetLongValue(L"General", L"BlurType", General::BlurType); // add string conversion to int for enhanced readability
			//ini.SetLongValue(L"General", L"BlurType", General::BlurType, L"; Blur Type (0: None, 1: Legacy, 2: Universal)");

            //ini.SaveFile(setting_path);
            logger::info("Settings Loaded");
        }
    }

    void SaveSettings() {
        CSimpleIniW ini;
        ini.SetUnicode();
        ini.LoadFile(setting_path);
        ini.Reset();

        ini.SetBoolValue(L"General", L"ModToggle", General::ModToggle, L"; Main Mod Toggle");
        ini.SetLongValue(L"General", L"BlurType", General::BlurType, L"; Blur Type (0: None, 1: Legacy, 2: Universal)");

        ini.SaveFile(setting_path);
        logger::info("Settings Saved");
	}

    void ResetSettings() {
        General::ModToggle = true;
		General::BlurType = 2;
        
        SaveSettings();
        logger::info("Settings Reset");
    }
}