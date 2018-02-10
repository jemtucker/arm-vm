cmake_minimum_required(VERSION 2.8.2)

project(ArmVm_Test)

include(CTest)

if (CMAKE_VERSION VERSION_LESS 3.2)
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "")
else()
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
endif()

include(DownloadProject.cmake)
download_project(
    PROJ                googletest
    GIT_REPOSITORY      https://github.com/google/googletest.git
    GIT_TAG             master
    ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

# When using CMake 2.8.11 or later, header path dependencies
# are automatically added to the gtest and gmock targets.
# For earlier CMake versions, we have to explicitly add the
# required directories to the header search path ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
                        "${gmock_SOURCE_DIR}/include")
endif()


# Get the source files (could use GLOB_RECURSE)
file(GLOB ArmVm_SOURCES "../src/*.cpp")
file(GLOB ArmVm_Test_SOURCES "*.cpp")
list(REMOVE_ITEM ArmVm_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/../src/main.cpp)

# Add includes
include_directories("../inc/")

# Compiler flags
if( CMAKE_CXX_COMPILER_ID MATCHES "Clang" )
    set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g -std=c++14 -stdlib=libstdc++" )
else()
    set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g -std=c++14" )
endif()
add_executable(armvm-test ${ArmVm_Test_SOURCES} ${ArmVm_SOURCES})
target_link_libraries(armvm-test gtest)
add_test(NAME armvm-test COMMAND armvm-test)
