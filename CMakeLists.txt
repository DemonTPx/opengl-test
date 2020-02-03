cmake_minimum_required(VERSION 2.6.2)
project(opengl-test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(yaml-cpp REQUIRED)

if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like bin_Visual2012_64bits/)" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
    message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
    message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}")

set(ALL_LIBS
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES}
        ${OPENGL_LIBRARY}
        ${YAML_CPP_LIBRARIES}
)

add_definitions(
        -std=c++0x
        -fpermissive
)
 
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/actor/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.hpp" "src/actor/*.hpp")

add_executable(opengl_test
        ${SOURCES})

target_link_libraries(opengl_test ${ALL_LIBS})
