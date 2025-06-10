cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
project(dvd_logo)

set(SOURCES
	src/main.cpp
	src/game.cpp
	src/dvd.cpp
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} ${SOURCES})
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

target_include_directories(${PROJECT_NAME} PUBLIC /opt/homebrew/Cellar/sdl2/2.32.4/include)
target_include_directories(${PROJECT_NAME} PUBLIC /opt/homebrew/Cellar/sdl2_image/2.8.8/include)

find_library(SDL2
	NAMES sdl2
	PATHS /opt/homebrew/Cellar/sdl2/2.32.4/lib
)

find_library(SDL2_IMAGE
	NAMES sdl2_image
	PATHS /opt/homebrew/Cellar/sdl2_image/2.8.8/lib
)

target_link_libraries(${PROJECT_NAME} ${SDL2})
target_link_libraries(${PROJECT_NAME} ${SDL2_IMAGE})

