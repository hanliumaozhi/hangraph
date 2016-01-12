cmake_minimum_required(VERSION 3.3)

project(hg)

FIND_PACKAGE(OpenGL REQUIRED)
IF(WIN32 OR WIN64)
    #TODO
ELSE(WIN32 OR WIN64)
    #add glew lib
    FIND_PACKAGE( GLEW REQUIRED)
    #add glfw lib
    FIND_PACKAGE(PkgConfig REQUIRED)
    pkg_search_module(GLFW REQUIRED glfw3)
    #add boost lib
    FIND_PACKAGE(Boost COMPONENTS system filesystem REQUIRED)
ENDIF(WIN32 OR WIN64)

INCLUDE_DIRECTORIES(${GLFW3_INCLUDE_DIR}
                    ${OPENGL_INCLUDE_DIRS}
                    ${CMAKE_CURRENT_SOURCE_DIR}
                    ${GLEW_INCLUDE_PATH}
                    ${PROJECT_SOURCE_DIR}/hg-core/ext
                    ${Boost_INCLUDE_DIRS})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

LINK_DIRECTORIES(
        ${PROJECT_SOURCE_DIR}
        ${GLFW3_LIBRARY_DIR}
)

set(SOURCE_FILES main.cpp hg-core/app/window.cpp hg-core/app/window.h hg-core/graphics/shader/GLSLShader.cpp hg-core/graphics/shader/GLSLShader.h hg-core/maths/maths.cpp hg-core/maths/maths.h hg-core/graphics/shader/shader_str.cpp hg-core/graphics/shader/shader_str.h hg-core/utils/timer/timer.cpp hg-core/utils/timer/timer.h hg-core/graphics/buffers/buffer.cpp hg-core/graphics/buffers/buffer.h hg-core/graphics/buffers/vertex.h hg-core/Common.h hg-core/graphics/buffers/vertexArray.cpp hg-core/graphics/buffers/vertexArray.h hg-core/graphics/renderer.cpp hg-core/graphics/renderer.h)
add_executable(hg ${SOURCE_FILES})

TARGET_LINK_LIBRARIES( hg
                        ${OPENGL_LIBRARY}
                        ${GLEW_LIBRARY}
                        ${GLFW_LIBRARIES}
                        ${Boost_LIBRARIES})