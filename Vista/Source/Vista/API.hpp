#pragma once

#ifdef __VISTA__

#if !defined(_WIN32)
#error Unsupported Platform
#endif

#if !defined(_MSC_VER)
#error Unsupported Compiler
#endif

#ifdef __VISTA_DYNAMIC_LIBRARY__

#ifdef __VISTA_EXPORT_SYMBOLS__

#ifdef _WIN32
#define __VISTA_API__ __declspec(dllexport)
#endif

#endif

#ifdef __VISTA_IMPORT_SYMBOLS__

#ifdef _WIN32
#define __VISTA_API__ __declspec(dllimport)
#endif

#endif

#endif

#endif