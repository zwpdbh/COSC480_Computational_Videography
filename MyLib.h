//
// Created by zwpdbh on 21/09/2017.
//

#ifndef COSC480_MYLIB_H
#define COSC480_MYLIB_H

#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>
#include <Eigen/Dense>
#include "MyPlane.h"
#include "Camera.h"

class MyLib {
public:
    MyLib() = default;

    static void displayOpticalFlow(cv::Mat&, std::string windowName);
    static void screenshotFromVideo(const char *fileName, std::string savedPath);
    static void getBlobs(cv::Mat& src, std::vector<cv::KeyPoint>& keyPoints);

    /*compute distance between two point*/
    static double distanceBetween(const Eigen::Vector3d &p1, const Eigen::Vector3d &p2);

    /*transform a Euclidean vector into Homogeneous one*/
    static Eigen::Vector4d getCorrespondingHomogeneousOneFrom(const Eigen::Vector3d &v);

    static Eigen::Vector3d getVector3dFromVector4d(const Eigen::Vector4d& v);
    static Eigen::Vector2d getVector2dFromVector3d(const Eigen::Vector3d& v);
    static Eigen::Vector3d getVector3dFromPoint2d(const cv::Point_<double>& point);
    static Eigen::Vector4d getVector4dFromVector3d(const Eigen::Vector3d& v);
    static double getRadian(double degree);
    static cv::Mat getRoationMat(const Eigen::Matrix<double, 3, 3> &rotation);

    // test function
    static void comparePosition(Camera& myCamera, const cv::Point3_<double>& foot);
};


#endif //COSC480_MYLIB_H
