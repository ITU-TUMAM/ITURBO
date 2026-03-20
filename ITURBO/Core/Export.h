// ------------------------------------------------------------------------------
// Project: ITURBO
// Copyright(c) 2026, Onur Tuncer, PhD, Istanbul Technical University
//
// SPDX - License - Identifier: LGPL-2.1-only
// License - Filename: LICENSE
// ------------------------------------------------------------------------------

#pragma once

#if defined(_WIN32) || defined(__CYGWIN__)
#if defined(ITURBO_CORE_BUILD)
#define ITURBO_CORE_API __declspec(dllexport)
#else
#define ITURBO_CORE_API __declspec(dllimport)
#endif
#else
#define ITURBO_CORE_API
#endif