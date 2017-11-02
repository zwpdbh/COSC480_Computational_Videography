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


set(SOURCE_FILES
        main.cpp
        MyLib.cpp
        MyLib.h
        MyPlane.cpp
        MyPlane.h
        Camera.cpp
        Camera.h
        )
add_executable(COSC480 ${SOURCE_FILES})

add_executable(playground
        playground.cpp
        MyLib.cpp
        MyLib.h
        MyPlane.h
        MyPlane.cpp
        Camera.h
        Camera.cpp
        )