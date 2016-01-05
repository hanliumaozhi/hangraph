cmake_minimum_required(VERSION 3.3)

project(hg)

FIND_PACKAGE(OpenGL REQUIRED)
IF(WIN32 OR WIN64)
    #TODO
ELSE(WIN32 OR WIN64)
    FIND_PACKAGE( GLEW REQUIRED)
    FIND_PACKAGE(PkgConfig REQUIRED)
    pkg_search_module(GLFW REQUIRED glfw3)
ENDIF(WIN32 OR WIN64)

INCLUDE_DIRECTORIES(${GLFW3_INCLUDE_DIR}
                    ${OPENGL_INCLUDE_DIRS}
                    ${CMAKE_CURRENT_SOURCE_DIR}
                    ${GLEW_INCLUDE_PATH})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

LINK_DIRECTORIES(
        ${PROJECT_SOURCE_DIR}
        ${GLFW3_LIBRARY_DIR}
)

set(SOURCE_FILES main.cpp hg-core/app/window.cpp hg-core/app/window.h)
add_executable(hg ${SOURCE_FILES})

TARGET_LINK_LIBRARIES( hg
                        ${OPENGL_LIBRARY}
                        ${GLEW_LIBRARY}
                        ${GLFW_LIBRARIES})