#include "MCP.h"

namespace MCP {
	void Register() {
		logger::info("Registering MCP functionality");
		if (!SKSEMenuFramework::IsInstalled()) {
			return;
			logger::error("SKSEMenuFramework is not installed. MCP functionality cannot be registered.");
		}
		SKSEMenuFramework::SetSection("Distant Blur");
		SKSEMenuFramework::AddSectionItem("General Settings", General::Render);
		SKSEMenuFramework::AddSectionItem("Advanced/Legacy", Advanced::Legacy::Render);
		//SKSEMenuFramework::AddSectionItem("Advanced/Universal", Advanced::Universal::Render);
		SKSEMenuFramework::AddSectionItem("Maintenance Settings", Maintenance::Render);

	}

	namespace General {
		using namespace Settings::General;

		void __stdcall Render() {
			//if (ImGui::TreeNode("Querying Item Status (Edited/Active/Hovered etc.)"))
			//{
			/*const char* item_names[] =
			{
				"Text", "Button", "Button (w/ repeat)", "Checkbox", "SliderFloat", "InputText", "InputTextMultiline", "InputFloat",
				"InputFloat3", "ColorEdit4", "Selectable", "MenuItem", "TreeNode", "TreeNode (w/ double-click)", "Combo", "ListBox"
			};
			static int item_type = 4; // + 1 | starts at zero for "Text" | Sets default item type to "SliderFloat"
			static bool item_disabled = false; // Default item disabled state
			ImGui::Combo("Item Type", &item_type, item_names, IM_ARRAYSIZE(item_names), IM_ARRAYSIZE(item_names));
			ImGui::SameLine();
			ImGui::Checkbox("Item Disabled", &item_disabled);*/


			ImGui::Checkbox("Mod Toggle", &ModToggle);

			const char* blurNames[] = {
				"None", "Legacy", "Universal"
			};
			ImGui::Combo("Item Type", &BlurType, blurNames, IM_ARRAYSIZE(blurNames), IM_ARRAYSIZE(blurNames));
			//ImGui::SameLine();
			//}
		}
	}

	namespace Advanced {
		using namespace Settings::Advanced;
		void __stdcall Render() {
			/*if (ImGui::TreeNode("Advanced Settings")) {
				ImGui::Text("Blur Type: %s", General::BlurType == 0 ? "None" : (General::BlurType == 1 ? "Legacy" : "Universal"));
				if (General::BlurType == 1) {
					Legacy::Render();
				}
				else if (General::BlurType == 2) {
					Universal::Render();
				}
			}*/
		}
		void __stdcall Legacy::Render() {
			using namespace Settings::Advanced::Legacy;
			ImGui::Text("Legacy Blur Settings");
			ImGui::Checkbox("Weather Smoothing Toggle", &WeatherSmoothing);

			if (ImGui::CollapsingHeader("Interior Settings##header", ImGuiTreeNodeFlags_DefaultOpen)) {
				ImGui::Checkbox("Interior Blur Toggle", &InteriorBlurToggle);
				ImGui::SliderFloat("Interior Blur Strength", &InteriorBlurStrength, 0.0f, 1.0f, "%.2f");
				ImGui::SliderFloat("Interior Blur Distance", &InteriorBlurDistance, 0.0f, 100.0f, "%.2f");
				ImGui::Checkbox("Interior Preliminary Patch", &InteriorPreliminaryPatch);
			}
			if (ImGui::CollapsingHeader("Exterior Settings##header", ImGuiTreeNodeFlags_DefaultOpen)) {
				ImGui::Checkbox("Exterior Blur Toggle", &exteriorBlurToggle);
				ImGui::SliderFloat("Exterior Blur Strength", &exteriorBlurStrength, 0.0f, 1.0f, "%.2f");
				ImGui::SliderFloat("Exterior Blur Distance", &exteriorBlurDistance, 0.0f, 100.0f, "%.2f");
				ImGui::Checkbox("Exterior Preliminary Patch", &exteriorPreliminaryPatch);
			}
		}
	}

	void __stdcall Maintenance::Render() {
		if (ImGui::Button("Save Settings")) {
			Settings::SaveSettings();
		}

		if (ImGui::Button("Reset Settings")) {
			Settings::ResetSettings();
		}
	}
}