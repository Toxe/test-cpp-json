cmake_minimum_required(VERSION 3.12)
project("JSON" LANGUAGES CXX)

# define default compiler options and warnings
include(cmake/DefaultCompilerOptionsAndWarnings.cmake)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

find_package(nlohmann_json CONFIG REQUIRED)

set(ALL_TARGETS
    prettify
    read_file
    read_file_into_object
)

foreach(target ${ALL_TARGETS})
    add_executable(${target} ${target}.cpp)
    target_compile_features(${target} PUBLIC cxx_std_17)
    target_compile_options(${target} PRIVATE ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
    target_link_libraries(${target} PRIVATE nlohmann_json::nlohmann_json)
    set_target_properties(${target} PROPERTIES CXX_EXTENSIONS OFF)
endforeach()
