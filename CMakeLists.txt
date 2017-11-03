cmake_minimum_required(VERSION 3.8)
project(COSC480)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-I/usr/local/Cellar/eigen/3.3.4/include/eigen3/ \
    -I/usr/local/Cellar/opencv/3.3.0_3/include/opencv \
    -I/usr/local/Cellar/opencv/3.3.0_3/include \
    -L/usr/local/Cellar/opencv/3.3.0_3/lib \
    -lopencv_superres \
    -lopencv_videostab \
    -lopencv_photo \
    -lopencv_videoio \
    -lopencv_face \
    -lopencv_fuzzy \
    -lopencv_hdf \
    -lopencv_img_hash \
    -lopencv_line_descriptor \
    -lopencv_optflow \
    -lopencv_rgbd \
    -lopencv_tracking \
    -lopencv_datasets \
    -lopencv_text \
    -lopencv_plot \
    -lopencv_xfeatures2d  \
    -lopencv_video \
    -lopencv_calib3d \
    -lopencv_features2d \
    -lopencv_highgui \
    -lopencv_imgproc \
    -lopencv_core"
)

include_directories(
        /Users/zw/local/opengl_tutorial/external/AntTweakBar-1.16/include/
        /Users/zw/local/opengl_tutorial/external/glfw-3.1.2/include/GLFW/
        /Users/zw/local/opengl_tutorial/external/glm-0.9.7.1/
        /Users/zw/local/opengl_tutorial/external/glew-1.13.0/include/
        /Users/zw/local/opengl_tutorial/external/assimp-3.0.1270/include/
        /Users/zw/local/opengl_tutorial/external/bullet-2.81-rev2613/src/
        .
)

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glfw
        GLEW_1130
        )

set(SOURCE_FILES
        main.cpp
        MyLib.cpp
        MyLib.h
        MyPlane.cpp
        MyPlane.h
        Camera.cpp
        Camera.h
        Process.cpp Process.h Blob.cpp Blob.h)
add_executable(COSC480 ${SOURCE_FILES})

add_executable(playground
        playground.cpp
        MyLib.cpp
        MyLib.h
        MyPlane.h
        MyPlane.cpp
        Camera.h
        Camera.cpp
        Process.cpp Process.h Blob.cpp Blob.h)

add_executable(Learning_OpenGL01 Learning_OpenGL/tutorial01.cpp)