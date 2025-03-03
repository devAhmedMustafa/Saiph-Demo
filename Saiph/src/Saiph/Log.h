#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Saiph {

	class SAIPH_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	};

}

#define SP_CORE_TRACE(...) ::Saiph::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SP_CORE_INFO(...)  ::Saiph::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SP_CORE_WARN(...)  ::Saiph::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SP_CORE_ERROR(...) ::Saiph::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SP_CORE_FATAL(...) ::Saiph::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define SP_TRACE(...)	   ::Saiph::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SP_INFO(...)       ::Saiph::Log::GetClientLogger()->info(__VA_ARGS__)
#define SP_WARN(...)       ::Saiph::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SP_ERROR(...)      ::Saiph::Log::GetClientLogger()->error(__VA_ARGS__)
#define SP_FATAL(...)      ::Saiph::Log::GetClientLogger()->fatal(__VA_ARGS__)