//
// Created by zwpdbh on 21/09/2017.
//

#ifndef COSC480_MYLIB_H
#define COSC480_MYLIB_H

#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>
class MyLib {
public:
    static void displayOpticalFlow(cv::Mat *, std::string windowName);
    static void screenshotFromVideo(const char *fileName, std::string savedPath);
    static void dilation(cv::Mat *src, cv::Mat *dst, int dilation_size, int dilation_type);
    static void erosion(cv::Mat *src, cv::Mat *dst, int erosion_size, int erosion_type);
    static void getBlobs(cv::Mat *src, std::vector<cv::KeyPoint> *keyPoints);
};


#endif //COSC480_MYLIB_H
