//
// Created by zwpdbh on 25/09/2017.
//

#include "Camera.h"
#include <math.h>
#include "MyLib.h"
#include <opencv2/core/eigen.hpp>

using namespace std;
using namespace Eigen;

Camera::Camera() {
//    pi = MyPlane(Vector3d(0,0,0), Vector3d(0, 1, 0));
    this->coordinates.push_back(cv::Point3_<int>(0, 0, 0));
    this->coordinates.push_back(cv::Point3_<int>(1, 0, 0));
    this->coordinates.push_back(cv::Point3_<int>(0, 1, 0));
    this->coordinates.push_back(cv::Point3_<int>(0, 0, 1));
}

void Camera::updateCameraSetting(double thetaX, double thetaY, double thetaZ, const Eigen::Vector3d &translation,
                                       double focalLength, double cu, double cv) {
    this->translation = translation;

    double rX = MyLib::getRadian(thetaX);
    double rY = MyLib::getRadian(thetaY);
    double rZ = MyLib::getRadian(thetaZ);

    this->translation << -translation[0], -translation[1], -translation[2];
    this->transation_Matrix << 1, 0, 0, translation[0, 0],
            0, 1, 0, translation[1, 0],
            0, 0, 1, translation[2, 0],
            0, 0, 0, 1;

    Eigen::Matrix<double, 4, 4> rotationX;
    rotationX << 1, 0, 0, 0,
            0, cos(rX), -sin(rX), 0,
            0, sin(rX), cos(rX), 0,
            0, 0, 0, 1;


    Eigen::Matrix<double, 4, 4> rotationY;
    rotationY << cos(rY), 0, sin(rY), 0,
            0, 1, 0, 0,
            -sin(rY), 0, cos(rY), 0,
            0, 0, 0, 1;


    Eigen::Matrix<double, 4, 4> rotationZ;
    rotationZ << cos(rZ), -sin(rZ), 0, 0,
            sin(rZ), cos(rZ), 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1;

    this->rotation_H = rotationX * rotationY * rotationZ;
    this->rotation << rotation_H[0, 0], rotation_H[0, 1], rotation_H[0, 2],
            rotation_H[1, 0], rotation_H[1, 1], rotation_H[1, 2],
            rotation_H[2, 0], rotation_H[2, 1], rotation_H[2, 2];


    this->extrinsics << rotation(0, 0), rotation(0, 1), rotation(0, 2), translation[0],
            rotation(1, 0), rotation(1, 1), rotation(1, 2), translation[1],
            rotation(2, 0), rotation(2, 1), rotation(2, 2), translation[2];

    this->intrinsics << focalLength, 0, cu,
        0, focalLength, cv,
        0, 0 ,1;

    this->projective = this->intrinsics * this->extrinsics;

    // compute pseudo inverse of p which is a 4 * 3 matrix
    this->pseudoInverse = this->projective.transpose() * ((this->projective * this->projective.transpose()).inverse());

    // compute the real camera center in 3D world
    this->cameraCenter = updateCameraCenter();
}

/**use method from paper single view metrology to compute the camera center in the world coordinate*/
Eigen::Vector3d Camera::updateCameraCenter() {
    Eigen::Matrix<double, 3, 3> p2p3p4;
    p2p3p4 <<   projective[0, 1], projective[0, 2], projective[0, 3],
                projective[1, 1], projective[1, 2], projective[1, 3],
                projective[2, 1], projective[2, 2], projective[2, 3];

    double x = -p2p3p4.determinant();

    Eigen::Matrix<double, 3, 3> p1p3p4;
    p1p3p4 <<   projective[0, 0], projective[0, 2], projective[0, 3],
                projective[1, 0], projective[1, 2], projective[1, 3],
                projective[2, 0], projective[2, 2], projective[2, 3];
    double y = p1p3p4.determinant();

    Eigen::Matrix<double, 3, 3> p1p2p4;
    p1p2p4 <<   projective[0, 0], projective[0, 1], projective[0, 3],
                projective[1, 0], projective[1, 1], projective[1, 3],
                projective[2, 0], projective[2, 1], projective[2, 3];
    double z = -p1p2p4.determinant();

    Eigen::Matrix<double, 3, 3> p1p2p3;
    p1p2p3 <<   projective[0, 0], projective[0, 1], projective[0, 2],
                projective[1, 0], projective[1, 1], projective[1, 2],
                projective[2, 0], projective[2, 1], projective[2, 2];
    double w = p1p2p3.determinant();

    return MyLib::getVector3dFromVector4d(Eigen::Vector4d(x, y, z, w));
}

cv::Point_<double> Camera::project3DPointOntoImage(const cv::Point3_<double> &p) {
    Eigen::Vector4d point3_H;
    point3_H << p.x, p.y, p.z, 1;

    Eigen::Vector2d point = MyLib::getVector2dFromVector3d(this->projective * point3_H);

    cv::Point pointOnImage(point[0], point[1]);
    return pointOnImage;
}


void Camera::setReferencePlane() {
    for (int z = -gridRadius; z <= gridRadius ; z+= gridStep) {
        this->projectedLeftEdgePoints.push_back(this->project3DPointOntoImage(cv::Point3_<double>(-gridRadius, atHeight, z)));
        this->projectedRightEdgePoints.push_back(this->project3DPointOntoImage(cv::Point3_<double>(gridRadius, atHeight, z)));
    }

    for (int x = -gridRadius; x <= gridRadius; x += gridStep) {
        this->projectedUpperEdgePoints.push_back(this->project3DPointOntoImage(cv::Point3_<double>(x, atHeight, -gridRadius)));
        this->projectedBottomEdgePoints.push_back(this->project3DPointOntoImage(cv::Point3_<double>(x, atHeight, gridRadius)));
    }

    for (cv::Point3_<double> each: this->coordinates) {
        this->projectedCoordinates.push_back(this->project3DPointOntoImage(each));
    }
}

void Camera::setReferencePlaneParameters(int gridStep, int gridRadius, int atHeight) {
    this->gridStep = gridStep;
    this->gridRadius = gridRadius;
    this->atHeight = atHeight;
}


Eigen::Vector3d Camera::getIntersectionInHomogeneousCoordinates(const cv::Point_<double>& imagePoint, const MyPlane& pi) {
    // step 1. get one Point on the ray by using pseudo inverse
    Eigen::Vector4d pointOnRay = this->getPseudoInverse() * MyLib::getVector3dFromPoint2d(imagePoint);
    Eigen::Vector4d c = MyLib::getVector4dFromVector3d(this->cameraCenter);

    // step 2. get the line as Plücker matrices which is 4×4 skew-symmetric homogeneous matrix.
    Eigen::Matrix<double, 4, 4> l = pointOnRay * (c.transpose()) - (c * pointOnRay.transpose());

    // step 3. compute intersection
    Eigen::Matrix<double, 4, 1> X = l * pi.getHomoPi();

    // step 4. transofrm it back to Euclidean one
    return MyLib::getVector3dFromVector4d(X);
}

Eigen::Matrix<double, 3, 4> &Camera::getExtrinsics() const {
    return extrinsics;
}

Eigen::Matrix<double, 3, 3> &Camera::getIntrinsics() const {
    return intrinsics;
}

Eigen::Matrix<double, 3, 3> &Camera::getRotation() const {
    return rotation;
}

Eigen::Vector3d &Camera::getTranslation() const {
    return translation;
}

Matrix<double, 4, 3> &Camera::getPseudoInverse() const {
    return pseudoInverse;
}

