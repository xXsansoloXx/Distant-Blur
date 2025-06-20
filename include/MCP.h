#pragma once

#include "PCH.h"
#include "Settings.h"
#include <SKSEMCP/SKSEMenuFramework.hpp>

// Taken from ImGui.h
#define IM_ARRAYSIZE(_ARR)          ((int)(sizeof(_ARR) / sizeof(*(_ARR))))     // Size of a static C-style array. Don't use on pointers!

namespace MCP {
	void Register();

	namespace General {
		void Render();
	}

	namespace Advanced {
		namespace Legacy {
			void Render();
		}
		namespace Universal {
			void Render();
		}
	}

	namespace Maintenance {
		void Render();
	}
}