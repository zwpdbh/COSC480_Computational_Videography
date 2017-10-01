//
// Created by zwpdbh on 25/09/2017.
//

#ifndef COSC480_CAMERA_H
#define COSC480_CAMERA_H

#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <opencv2/core.hpp>

class Camera {
private:
    Eigen::Matrix<double, 3, 4> extrinsics;
    Eigen::Matrix<double, 3, 3> intrinsics;
    Eigen::Matrix<double, 3, 3> rotation;
    Eigen::Vector3d translation;

public:
    const void updateCameraSetting(double thetaX, double thetaY, double thetaZ, const Eigen::Vector3d &translation, double focalLength, double cu, double cv);
    cv::Point getPorjectedPointOnImageFrom(const cv::Point3d &x);

    const Eigen::Matrix<double, 3, 4> &getExtrinsics() const;

    const Eigen::Matrix<double, 3, 3> &getIntrinsics() const;

    const Eigen::Matrix<double, 3, 3> &getRotation() const;

    const Eigen::Vector3d &getTranslation() const;
};


#endif //COSC480_CAMERA_H
