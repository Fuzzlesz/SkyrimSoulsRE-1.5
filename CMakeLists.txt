cmake_minimum_required(VERSION 3.31)

# Setup project
project(
	SkyrimSoulsRE
	VERSION 3.1.2
	LANGUAGES CXX
)
set(FORMATTED_NAME "Skyrim Souls RE")
set(LICENSE "MIT License")
set(AUTHOR "Vermunds")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

list(APPEND CMAKE_IGNORE_PATH "${PROJECT_BINARY_DIR}")
list(APPEND CMAKE_MODULE_PATH
	"${PROJECT_SOURCE_DIR}/tools/Modules"
)
include(SKSEPlugin)

set(SKSE_USE_XBYAK ON)

SKSEPlugin_Add(
	${PROJECT_NAME}
	INCLUDE_DIR include
	SOURCE_DIR src
	SOURCES
		.editorconfig
		README.md
		vcpkg.json
	PRECOMPILE_HEADERS
		include/PCH.h
)
