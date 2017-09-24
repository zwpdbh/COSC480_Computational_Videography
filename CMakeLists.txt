cmake_minimum_required(VERSION 3.8)
project(COSC480)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-I/usr/local/Cellar/eigen/3.3.4/include/eigen3/ -I/usr/local/Cellar/opencv/3.3.0_3/include/opencv -I/usr/local/Cellar/opencv/3.3.0_3/include -L/usr/local/Cellar/opencv/3.3.0_3/lib -lopencv_stitching -lopencv_superres -lopencv_videostab -lopencv_photo -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dpm -lopencv_face -lopencv_fuzzy -lopencv_hdf -lopencv_img_hash -lopencv_line_descriptor -lopencv_optflow -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_sfm -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_text -lopencv_dnn -lopencv_plot -lopencv_ml -lopencv_xfeatures2d -lopencv_shape -lopencv_video -lopencv_ximgproc -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_flann -lopencv_xobjdetect -lopencv_imgcodecs -lopencv_objdetect -lopencv_xphoto -lopencv_imgproc -lopencv_core")


set(SOURCE_FILES main.cpp MyLib.cpp MyLib.h MyLine.cpp MyLine.h MyPlane.cpp MyPlane.h)

add_executable(COSC480 ${SOURCE_FILES})
add_executable(playground playground.cpp MyLib.cpp MyLib.h)