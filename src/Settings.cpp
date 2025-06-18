#include "Settings.h"

namespace Settings {
    void LoadSettings() {
        CSimpleIniW ini;
        ini.SetUnicode();

        if (!std::filesystem::exists(setting_path)) {
            logger::info("No {} file found, creating new with default values", setting_path);
            ResetSettings();
        } else {
            ini.LoadFile(setting_path);

            General::ModToggle = ini.GetBoolValue(L"General", L"ModToggle", General::ModToggle);
            ini.SetBoolValue(L"General", L"ModToggle", General::ModToggle, L"; Main Mod Toggle");


            ini.SaveFile(setting_path);
            logger::info("Settings Loaded");
        }
    }

    void ResetSettings() {
		CSimpleIniW ini;
		ini.SetUnicode();
		ini.Reset();

        General::ModToggle = true;
        logger::info("Settings Reset");
    }
}