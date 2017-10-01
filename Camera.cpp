//
// Created by zwpdbh on 25/09/2017.
//

#include "Camera.h"
#include <math.h>
#include "MyLib.h"
#include <opencv2/core/eigen.hpp>

using namespace std;

const void Camera::updateCameraSetting(double thetaX, double thetaY, double thetaZ, const Eigen::Vector3d &translation,
                                       double focalLength, double cu, double cv) {
    this->translation = translation;

    double rX = MyLib::getRadian(thetaX);
    double rY = MyLib::getRadian(thetaY);
    double rZ = MyLib::getRadian(thetaZ);

    Eigen::Matrix<double, 3, 3> rotationX;
    rotationX << 1, 0, 0,
                 0, cos(rX), -sin(rX),
                 0, sin(rX), cos(rX);

    cout << "roationX = \n" << rotationX << endl;

    Eigen::Matrix<double, 3, 3> rotationY;
    rotationY << cos(rY), 0, sin(rY),
                 0, 1, 0,
                 -sin(rY), 0, cos(rY);

    cout << "roationY = \n" << rotationY << endl;

    Eigen::Matrix<double, 3, 3> rotationZ;
    rotationZ << cos(rZ), -sin(rZ), 0,
                 sin(rZ), cos(rZ), 0,
                 0, 0, 1;
    cout << "roationZ = \n" << rotationZ << endl;

    this->rotation =  rotationX * rotationY * rotationZ;
    cout << "roation = \n" << this->rotation << endl;

    this->extrinsics << rotation(0, 0), rotation(0, 1), rotation(0, 2), translation[0],
            rotation(1, 0), rotation(1, 1), rotation(1, 2), translation[1],
            rotation(2, 0), rotation(2, 1), rotation(2, 2), translation[2];
}

cv::Point Camera::getPorjectedPointOnImageFrom(const cv::Point3d &p) {
    cout << "computing the projected point on image..." << endl;
//    cv::Mat point_in_3D(1, 1, CV_32FC3);
    cv::Mat point_in_3D(3, 1, CV_32FC1);
    point_in_3D.at<double>(0, 0) = p.x;
    point_in_3D.at<double>(1, 0) = p.y;
    point_in_3D.at<double>(2, 0) = p.z;
    cout << point_in_3D << endl;

//    // from eigen matrix get opencv mat
//    cv::Mat rotationMat(3, 3, CV_32FC1);
//    cv::eigen2cv(this->rotation, rotationMat);
//    cv::Mat rotationVector(3, 1, CV_32FC1);
//    cv::Rodrigues(rotationMat, rotationVector);
//
//    cv::Mat translationVector(3, 1, CV_32FC1);
//    cv::eigen2cv(this->translation, translationVector);
//    cout << translationVector << endl;
//
//    cv::Mat intrinsicMat(3, 3, CV_32FC1);
//    cv::eigen2cv(this->intrinsics, intrinsicMat);
//
//    cv::Mat distCoeffs(8, 1, CV_32FC1, cv::Scalar_<int>(0));
//
//    // the projected point
//    cv::Mat point_on_image(1, 1, CV_32FC2);
//
//    cv::projectPoints(point_in_3D, rotationVector, translationVector, intrinsicMat, distCoeffs, point_on_image);
//    return cv::Point_<double>(point_on_image.at<double>(0, 0), point_on_image.at<double>(0, 1));

    return cv::Point();
}








const Eigen::Matrix<double, 3, 4> &Camera::getExtrinsics() const {
    return extrinsics;
}

const Eigen::Matrix<double, 3, 3> &Camera::getIntrinsics() const {
    return intrinsics;
}

const Eigen::Matrix<double, 3, 3> &Camera::getRotation() const {
    return rotation;
}

const Eigen::Vector3d &Camera::getTranslation() const {
    return translation;
}

