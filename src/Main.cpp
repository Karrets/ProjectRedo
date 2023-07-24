#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

#include "Engine.h"

int main(int argc, char *argv[]) {
    spdlog::set_default_logger(std::make_shared<spdlog::logger>(
            GameConf::NAME,
            std::initializer_list<spdlog::sink_ptr>{
                    std::make_shared<spdlog::sinks::basic_file_sink_mt>("log.txt", true), //File logger
                    std::make_shared<spdlog::sinks::stdout_color_sink_mt>()} //Console logger
    ));
    spdlog::set_level(GameConf::LOG_LEVEL);

    auto engine = Engine();

    spdlog::shutdown();
}