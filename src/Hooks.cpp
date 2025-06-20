#include "Hooks.h"

namespace Hooks {
	void InstallHooks() {
		logger::info("InstallHooks: Entering. Applying hooks and patches.");

		// Hook 1: Install hook for jump state checking.
		logger::info("InstallHooks: Calling InstallJumpStateCheckHook.");
		TemplateStruct::Install();

		logger::info("InstallHooks: Exiting, All hooks and patches applied successfully. ");
		return;
	}

	void TemplateStruct::Install() {
		auto& trampoline = SKSE::GetTrampoline();
		//originalFunction = trampoline.write_call<5>(REL::RelocationID(0, 0).address() + REL::Relocate(0x0, 0x0)), TemplateStruct::TemplateHook);
		logger::info("Installed jump state hook");
	}

	void TemplateStruct::TemplateHook() {
		if (!Settings::General::ModToggle) {
			logger::info("TemplateHook: Mod is disabled, skipping hook execution.");
			return;
		}
		return;
	}
}