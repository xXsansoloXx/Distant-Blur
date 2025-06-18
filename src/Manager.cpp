#include "Manager.h"

namespace Manager {
	/**
	* @brief The main initialization function for the mod logic.
	* Called from the SKSE plugin entry point after game data is loaded.
	*/
	void Initialize() {
		logger::info("Manager: JumpingMod Initializing, Entering and Allocating trampoline.");

		// Allocate trampoline space early. Commonlib handles getting the SKSE trampoline.
		// Requesting reasonable sizes for branch and local (code generation) trampolines.
		// Combined size might need adjustment based on total hooks from all mods.
		SKSE::AllocTrampoline(1 << 10);  // 2^10 = 1024 bytes for branch trampoline
		logger::info("Manager: Trampoline allocated, now Calling ResolveAddresses");

		// Resolve necessary game addresses using Address Library.
		Serialization::ResolveAddresses();

		// Install memory hooks and patches.
		Hooks::InstallHooks();
		
		logger::info("Manager: Exiting, InstallHooks finished and jumpingmod Initialization finished.");
		return;
	}

}