cmake_minimum_required(VERSION 3.27)
project(
        lunari
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# SDL3
FetchContent_Declare(
        SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-3.2.24
)

# SDL3_ttf
FetchContent_Declare(
        SDL3_ttf
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf.git
        GIT_TAG release-3.2.2
)

# Boost
FetchContent_Declare(
        boost
        GIT_REPOSITORY https://github.com/boostorg/boost.git
        GIT_TAG boost-1.89.0
        GIT_SHALLOW TRUE
        GIT_SUBMODULES_RECURSE TRUE
)

set(SDLTTF_VENDORED ON CACHE BOOL "" FORCE)
set(SDLTTF_SAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(SDL3 SDL3_ttf boost)

file(GLOB_RECURSE SOURCES
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(lunari ${SOURCES})

target_include_directories(lunari PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(lunari PRIVATE
        SDL3::SDL3
        SDL3_ttf::SDL3_ttf
        Boost::signals2
)
