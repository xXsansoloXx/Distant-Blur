#pragma once

#include "PCH.h"  
#include "Settings.h"  
#include "Utils.h"

#include <xbyak/xbyak.h>  

namespace Hooks {
    void InstallHooks();

    struct TemplateStruct {
        static void Install();
        static void TemplateHook();
        static inline REL::Relocation<decltype(TemplateHook)> originalFunction;
    };
}