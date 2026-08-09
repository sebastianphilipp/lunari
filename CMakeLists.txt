cmake_minimum_required(VERSION 3.27)
project(
        pacman
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-3.2.24
)

FetchContent_Declare(
        boost
        GIT_REPOSITORY https://github.com/boostorg/boost.git
        GIT_TAG boost-1.89.0
        GIT_SHALLOW TRUE
        GIT_SUBMODULES_RECURSE TRUE
)

FetchContent_MakeAvailable(SDL3 boost)

file(GLOB_RECURSE SOURCES
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(pacman ${SOURCES})

target_link_libraries(pacman PRIVATE
        SDL3::SDL3
        Boost::signals2
)
