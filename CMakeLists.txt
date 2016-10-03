cmake_minimum_required(VERSION 2.6.2)
project(opengl-test)

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

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
        ${OPENGL_LIBRARY}
)

add_definitions(
        -std=c++0x
        -fpermissive
)
 
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.hpp")

add_executable(opengl_test
        ${SOURCES}
        )

target_link_libraries(opengl_test ${ALL_LIBS})
