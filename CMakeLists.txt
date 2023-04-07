cmake_minimum_required(VERSION 3.22)
project(roentgenium-cs2)
set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE SRC
        # source
        "src/*.c" ,
        "src/*.cpp" ,
        "src/**/*.c" ,
        "src/**/*.cpp" ,
        "src/*.cpp"

        # dependencies
        "dependencies/*.c" ,
        "dependencies/*.cpp" ,
        "dependencies/**/*.c" ,
        "dependencies/**/*.cpp" ,
        "dependencies/*.cpp"
        )

add_library(${PROJECT_NAME} MODULE ${SRC})
find_library(SPDLOG_LIBRARY spdlog.lib PATHS "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/spdlog")

include(FetchContent)

FetchContent_Declare(freetype
        GIT_REPOSITORY https://git.savannah.gnu.org/git/freetype/freetype2.git
        GIT_TAG        VER-2-13-0)
FetchContent_MakeAvailable(freetype)

target_link_libraries(${PROJECT_NAME} d3d11 dxgi ${SPDLOG_LIBRARY} freetype)
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/dependencies")