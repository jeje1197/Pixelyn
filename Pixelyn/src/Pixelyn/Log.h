#pragma once

#include <memory.h>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Pixelyn
{
	class PIXELYN_API Log
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
#define PX_CORE_TRACE(...) ::Pixelyn::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PX_CORE_INFO(...)  ::Pixelyn::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PX_CORE_WARN(...)  ::Pixelyn::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PX_CORE_ERROR(...) ::Pixelyn::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PX_CORE_FATAL(...) ::Pixelyn::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define PX_TRACE(...) ::Pixelyn::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PX_INFO(...)  ::Pixelyn::Log::GetClientLogger()->info(__VA_ARGS__)
#define PX_WARN(...)  ::Pixelyn::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PX_ERROR(...) ::Pixelyn::Log::GetClientLogger()->error(__VA_ARGS__)
#define PX_FATAL(...) ::Pixelyn::Log::GetClientLogger()->critical(__VA_ARGS__)




