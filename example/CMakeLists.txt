cmake_minimum_required(VERSION 3.19)

project(Tests C)

# Make steps available in tests
include_directories(steps)
file(GLOB steps CONFIGURE_DEPENDS steps/*.c)
add_library(steps ${steps})

enable_testing()

file(GLOB tests CONFIGURE_DEPENDS tests/*.c)
set(SEAFLOW_TESTS ${tests})

# Make seaflow headers available in tests
include_directories(seaflow/src)
# Include seaflow project
add_subdirectory(seaflow)
