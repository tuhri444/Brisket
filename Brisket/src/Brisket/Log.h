#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"


namespace Brisket {
	class  BRISKET_API Log
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

//core log macros
#define BK_CORE_ERROR(...) :: Brisket::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BK_CORE_WARN(...)  :: Brisket::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BK_CORE_INFO(...)  :: Brisket::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BK_CORE_TRACE(...) :: Brisket::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BK_CORE_CRITICAL(...) :: Brisket::Log::GetCoreLogger()->critical(__VA_ARGS__)


//client log macros
#define BK_ERROR(...) :: Brisket::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BK_WARN(...)  :: Brisket::Log::GetClientLogger()->error(__VA_ARGS__)
#define BK_INFO(...)  :: Brisket::Log::GetClientLogger()->info(__VA_ARGS__)
#define BK_TRACE(...) :: Brisket::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BK_CRITICAL(...) :: Brisket::Log::GetClientLogger()->critical(__VA_ARGS__)

