cmake_minimum_required(VERSION 3.3)
project(GDV)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#########################################################
# FIND GLUT
#########################################################
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)
#########################################################
# FIND OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

set(SOURCE_FILES teil_1.cpp teil_2.cpp Cube.cpp Cube.h Cube.h Cube.cpp teil_3.cpp teil_4.cpp ballet.cpp)

#########################################################
# Remove (done) Files
#########################################################
list(REMOVE_ITEM SOURCE_FILES teil_1.cpp teil_2.cpp teil_3.cpp teil_4.cpp)

add_executable(GDV ${SOURCE_FILES})


########################################################
# Linking & stuff
#########################################################

# create the program "test"
target_link_libraries(GDV ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
