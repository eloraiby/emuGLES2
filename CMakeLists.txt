project(emuGLES2 C)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)

set(HEADER_FILES emuGLES2.h)

if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
      set (CMAKE_C_FLAGS "--std=c99 ${CMAKE_C_FLAGS}")
    endif ()
else ()
    set (CMAKE_C_STANDARD 99)
endif ()

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

add_library(${PROJECT_NAME} SHARED ${SRC_LIST} ${HEADER_FILES})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})

add_library(${PROJECT_NAME}s STATIC ${SRC_LIST} ${HEADER_FILES})
target_link_libraries(${PROJECT_NAME}s ${OPENGL_LIBRARIES})
