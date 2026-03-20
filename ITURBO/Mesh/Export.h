#pragma once

#if defined(_WIN32) || defined(__CYGWIN__)
#if defined(ITURBO_MESH_BUILD)
#define ITURBO_MESH_API __declspec(dllexport)
#else
#define ITURBO_MESH_API __declspec(dllimport)
#endif
#else
#define ITURBO_MESH_API
#endif