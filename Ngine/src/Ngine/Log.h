#pragma once

#include "Core.h"
#include"spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Ngine {

	class NGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define NE_CORE_TRACE(...)    ::Ngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NE_CORE_INFO(...)     ::Ngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NE_CORE_WARN(...)     ::Ngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NE_CORE_ERROR(...)    ::Ngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NE_CORE_CRITICAL(...) ::Ngine::Log::GetCoreLogger()->critical(__VA_ARGS__)
							
#define NE_TRACE(...)         ::Ngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NE_INFO(...)          ::Ngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define NE_WARN(...)          ::Ngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NE_ERROR(...)         ::Ngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define NE_CRITICAL(...)      ::Ngine::Log::GetClientLogger()->critical(__VA_ARGS__)