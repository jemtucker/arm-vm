cmake_minimum_required(VERSION 2.8.2)

project(ArmVm)

# Main project
add_subdirectory(src)

# Test project
enable_testing()
add_subdirectory(test)
