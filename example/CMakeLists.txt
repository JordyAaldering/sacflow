cmake_minimum_required(VERSION 3.19)

project(Tests C)

# TODO: surely there is a better way to do this
add_library(steps steps/examplesteps.h steps/examplesteps.c)

enable_testing()

file(GLOB tests tests/*.c)
set(SEAFLOW_TESTS ${tests})

# Make seaflow headers available in tests
include_directories(seaflow/src PUBLIC)
# Include seaflow project
add_subdirectory(seaflow)
