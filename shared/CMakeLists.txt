cmake_minimum_required(VERSION 3.22)
project(roentgenium-shared)
set(CMAKE_CXX_STANDARD 23)
include(FetchContent)

FetchContent_Declare(freetype
        GIT_REPOSITORY https://git.savannah.gnu.org/git/freetype/freetype2.git
        GIT_TAG        VER-2-13-0)
FetchContent_MakeAvailable(freetype)