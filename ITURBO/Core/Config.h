// ------------------------------------------------------------------------------
// Project: ITURBO
// Copyright(c) 2026, Onur Tuncer, PhD, Istanbul Technical University
//
// SPDX - License - Identifier: LGPL-2.1-only
// License - Filename: LICENSE
// ------------------------------------------------------------------------------

#pragma once

#include <string>
#include <string_view>

#include "ITURBO/Core/Enums.h"
#include "ITURBO/Core/Export.h"

namespace ITURBO::Core {

    class ITURBO_CORE_API Config final {
    public:
        [[nodiscard]] static std::string ProjectName();
        [[nodiscard]] static std::string VersionString();
        [[nodiscard]] static BuildType CurrentBuildType() noexcept;
        [[nodiscard]] static ExecutionSpace CurrentExecutionSpace() noexcept;
        [[nodiscard]] static FloatingPointPrecision DefaultPrecision() noexcept;

        [[nodiscard]] static bool HasMPI() noexcept;
        [[nodiscard]] static bool HasOpenMP() noexcept;
        [[nodiscard]] static bool HasPETSc() noexcept;
        [[nodiscard]] static bool HasCGNS() noexcept;
    };

} // namespace TurboCFD::Core