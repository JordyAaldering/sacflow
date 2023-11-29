cmake_minimum_required(VERSION 3.19)

project(Tests C)

# TODO: surely there is a better way to do this
add_library(steps examplesteps.h examplesteps.c)

enable_testing()

file(GLOB tests tests/*.c)
set(SEAFLOW_TESTS ${tests})

# Note that in a normal folder structure these would just be:
include_directories(sacflow/src PUBLIC)
add_subdirectory(sacflow/src)
