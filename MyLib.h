//
// Created by zwpdbh on 21/09/2017.
//

#ifndef COSC480_MYLIB_H
#define COSC480_MYLIB_H

#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>
#include <Eigen/Dense>
#include "MyLine.h"
#include "MyPlane.h"
#include "Camera.h"

class MyLib {
public:
    MyLib();

    static void displayOpticalFlow(cv::Mat&, std::string windowName);
    static void screenshotFromVideo(const char *fileName, std::string savedPath);
    static void dilation(cv::Mat& src, cv::Mat& dst, int dilation_size, int dilation_type);
    static void erosion(cv::Mat& src, cv::Mat& dst, int erosion_size, int erosion_type);
    static void getBlobs(cv::Mat& src, std::vector<cv::KeyPoint>& keyPoints);

    /*compute distance between two point*/
    static double distanceBetween(const Eigen::Vector3d &p1, const Eigen::Vector3d &p2);

    /*transform a Euclidean vector into Homogeneous one*/
    static Eigen::Vector4d getCorrespondingHomogeneousOneFrom(const Eigen::Vector3d &v);

    static Eigen::Vector3d getCorrespondingEuclideanOneFrom(const Eigen::Vector4d &v);
};


#endif //COSC480_MYLIB_H
