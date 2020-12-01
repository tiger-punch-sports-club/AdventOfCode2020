cmake_minimum_required(VERSION 3.16)
project("AdventOfCode2020")
set(CMAKE_CXX_STANDARD 17)

set(APP_SOURCE "${PROJECT_SOURCE_DIR}/source/app")
set(MODULE_SOURCE "${PROJECT_SOURCE_DIR}/source/module")
set(EXTERNALS "${PROJECT_SOURCE_DIR}/externals")

# pybind11
add_subdirectory(${EXTERNALS}/pybind11)

# module
pybind11_add_module (
    python_module 
    ${MODULE_SOURCE}/module.cpp
)

target_include_directories (
    python_module 
    PRIVATE ${MODULE_SOURCE}
)

# app
add_executable (
    app
    ${APP_SOURCE}/app.cpp
)

target_include_directories (
    app 
    PRIVATE ${APP_SOURCE}
    PRIVATE ${MODULE_SOURCE}
)

target_link_libraries(
    app
    PRIVATE pybind11::embed
)

add_dependencies(
    app
    python_module
)