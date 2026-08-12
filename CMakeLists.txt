cmake_minimum_required(VERSION 4.4)
project(scripple LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -O3")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(STATIK OFF CACHE BOOL "Make a statically linked executable")
if(STATIK)
	set(BUILD_SHARED_LIBS OFF)
	set(SDLTTF_VENDORED ON)
endif()

# Dependencies
add_subdirectory("vendor/SDL_ttf" SDL_ttf)
add_subdirectory("vendor/Think" Think)
add_subdirectory("vendor/Inputs" Inputs)

set(executable "walk")
add_executable( "${executable}"
	src/main.cpp
	src/load.cpp
	src/fonts.cpp
	src/grid.cpp
	src/init.cpp
	src/machine.cpp
	src/update.cpp
)

target_include_directories("${executable}"
	PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(NOT STATIK)
	target_link_libraries("${executable}"
		PRIVATE
		SDL3::SDL3
		SDL3_ttf::SDL3_ttf
	)
else()
	if(NOT LINUX)
		target_link_options("${executable}" PRIVATE -static -mwindows)
	endif()
	target_link_libraries("${executable}"
		PRIVATE
		SDL3::SDL3-static
		SDL3_ttf::SDL3_ttf-static
	)
endif()

target_link_libraries("${executable}"
	PRIVATE
	Inputs::Inputs
	Think::Think
	Matrix::Matrix
)

