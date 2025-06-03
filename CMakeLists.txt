cmake_minimum_required(VERSION 3.10)
project(dvd_logo)


set(SOURCES
	src/main.cpp
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC /opt/homebrew/Cellar/sdl2/2.32.4/include)

find_library(SDL2
	NAMES sdl2
	PATHS /opt/homebrew/Cellar/sdl2/2.32.4/lib
)

target_link_libraries(${PROJECT_NAME} ${SDL2})
