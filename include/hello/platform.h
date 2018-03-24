#ifndef _HELLO_PLATFORM_H_
#define _HELLO_PLATFORM_H_

#ifndef linux
//////////////////////////////////////////////////
// WINDOWS
//////////////////////////////////////////////////
#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0501
#include <Windows.h>
#include <cstdio>
#define snprintf _snprintf
#ifndef WIN32
#define WIN32
#endif
#include <stdint.h>

#else
//////////////////////////////////////////////////
// LINUX
//////////////////////////////////////////////////
#include <stdint.h>
#include <errno.h>
#include <dlfcn.h>
#endif

//////////////////////////////////////////////////
// HELLO Shared Library Export
//////////////////////////////////////////////////
#ifndef HELLO_SHARED_LIBRARY_EXPORT
#ifdef linux
#define HELLO_SHARED_LIBRARY_EXPORT
#define HELLO_SHARED_LOADADDRESS dlsym
#define HELLO_SHARED_LIBRARY_HANDLE void*
#else
#define HELLO_SHARED_LIBRARY_EXPORT __declspec(dllexport)
#define HELLO_SHARED_LIBRARY_IMPORT __declspec(dllimport)
#define HELLO_SHARED_LIBRARY_HANDLE HINSTANCE
#endif
#endif

//////////////////////////////////////////////////
// HELLO MSG
//////////////////////////////////////////////////
#ifdef linux
#ifndef HELLO_MSG_DEFINED
#define HELLO_MSG_DEFINED
typedef unsigned long WPARAM;
typedef intptr_t LPARAM;
typedef struct{int message;WPARAM wParam;LPARAM lParam;}TMSG;
typedef TMSG MSG;


//////////////////////////////////////////////////
// HELLO HANDLE
//////////////////////////////////////////////////
typedef int HANDLE;
#define INVALID_HANDLE_VALUE    -1
#endif
#endif

//////////////////////////////////////////////////
// wide char define
//////////////////////////////////////////////////
#if _UNICODE
#define char_t wchar_t
#if linux
#define _TEXT(X) L##X
#endif
#else
#define char_t char
#if linux
#define _TEXT(X) X
#endif
#endif

#endif // _HELLO_PLATFORM_H_
