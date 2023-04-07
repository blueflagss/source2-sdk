cmake_minimum_required(VERSION 3.22)
project(roentgenium-gui)
set(CMAKE_CXX_STANDARD 23)
set(DEPENDENCY_PATH "../shared")

file(GLOB_RECURSE SRC
        "src/*.c" ,
        "src/*.cpp" ,
        "src/**/*.c" ,
        "src/**/*.cpp" ,
        "src/*.cpp"
        "${DEPENDENCY_PATH}/*.c" ,
        "${DEPENDENCY_PATH}/*.cpp" ,
        "${DEPENDENCY_PATH}/**/*.c" ,
        "${DEPENDENCY_PATH}/**/*.cpp" ,
        "${DEPENDENCY_PATH}/*.cpp"
        )

add_executable(${PROJECT_NAME} ${SRC})
find_library(SPDLOG_LIBRARY spdlog.lib PATHS ${DEPENDENCY_PATH}/spdlog)
target_link_libraries(${PROJECT_NAME} PRIVATE renderer dwmapi d3d11 dxgi ${SPDLOG_LIBRARY})
target_include_directories(${PROJECT_NAME} PUBLIC src)
target_include_directories(${PROJECT_NAME} PUBLIC ${DEPENDENCY_PATH})