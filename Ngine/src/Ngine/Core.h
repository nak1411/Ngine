#pragma once

#ifdef NG_PLATFORM_WINDOWS
	#ifdef NG_BUILD_DLL
		#define NGINE_API __declspec(dllexport)
	#else
		#define NGINE_API __declspec(dllexport)
	#endif
#else
	#error Ngine only supports Windows
#endif