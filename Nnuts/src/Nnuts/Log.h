#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Nnuts {
	class NNUTS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr< spdlog::logger >& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr< spdlog::logger >& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr< spdlog::logger > s_CoreLogger;
		static std::shared_ptr< spdlog::logger > s_ClientLogger;
	};
}

//Core logging macros:
#define NN_CORE_TRACE(...)  ::Nnuts::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NN_CORE_INFO(...)   ::Nnuts::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NN_CORE_WARN(...)   ::Nnuts::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NN_CORE_ERROR(...)  ::Nnuts::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NN_CORE_FATAL(...)  ::Nnuts::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client logging macros:
#define NN_TRACE(...)       ::Nnuts::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NN_INFO(...)        ::Nnuts::Log::GetClientLogger()->info(__VA_ARGS__)
#define NN_WARN(...)        ::Nnuts::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NN_ERROR(...)       ::Nnuts::Log::GetClientLogger()->error(__VA_ARGS__)
#define NN_FATAL(...)       ::Nnuts::Log::GetClientLogger()->fatal(__VA_ARGS__)