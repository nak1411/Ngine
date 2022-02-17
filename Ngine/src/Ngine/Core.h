#pragma once

#ifdef NE_PLATFORM_WINDOWS
	#ifdef NE_BUILD_DLL
		#define NGINE_API __declspec(dllexport)
	#else
		#define NGINE_API __declspec(dllimport)
	#endif
#endif

