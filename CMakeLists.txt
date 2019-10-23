#==============================================================================
#	Top-Level CoreZero.PDK CMakeLists
#
#	Jensen Miller
#	Copyright (C) 2019 LooUQ Incorporated.
#	Licensed under the GNU license.
#==============================================================================
cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME "CoreZero-PDK")
set(PROJECT_LIB_NAME "libczsystem")



#
#	Project Name Assignment
#
project ("${PROJECT_NAME}")



#
#	Build Options
#
option(BUILD_LIBRARY_AS_SHARED "Build this library as a shared object rather than the default static library." OFF)
option(BUILD_EXAMPLES "Build examples of this library." OFF)
option(BUILD_TESTS "Build the tests of this library" OFF)


if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	set(mcu CMAKE_HOST_SYSTEM_PROCESSOR)
endif()



#
#	Include all sub-projects
#

#	Examples
if (BUILD_EXAMPLES)
	add_subdirectory("${PROJECT_SOURCE_DIR}/examples")
endif()



#
#	Discover all library code
#
file(GLOB_RECURSE LIB_SOURCES FOLLOW_SYMLINKS "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE LIB_INCLUDES FOLLOW_SYMLINKS "${PROJECT_SOURCE_DIR}/include/*.hpp" "${PROJECT_SOURCE_DIR}/include/*.h")



#
#	Setup Library by root
#
if (BUILD_LIBRARY_AS_SHARED)
	add_library("${PROJECT_LIB_NAME}" SHARED "")
	set_target_properties("${PROJECT_LIB_NAME}" PROPERTIES SUFFIX ".so")
else()
	add_library("${PROJECT_LIB_NAME}" STATIC "")
	set_target_properties("${PROJECT_LIB_NAME}" PROPERTIES POSITION_INDEPENDENT_CODE ON)
endif()


target_include_directories("${PROJECT_LIB_NAME}" PRIVATE "${PROJECT_SOURCE_DIR}/include")

target_sources("${PROJECT_LIB_NAME}" PUBLIC "${LIB_INCLUDES}")	# include library headers
target_sources("${PROJECT_LIB_NAME}" PRIVATE "${LIB_SOURCES}")	# include library source code
target_compile_features("${PROJECT_LIB_NAME}" PUBLIC cxx_std_11)
