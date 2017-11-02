//
// Created by zwpdbh on 25/09/2017.
//

#ifndef COSC480_CAMERA_H
#define COSC480_CAMERA_H

#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <opencv2/core.hpp>
#include "MyPlane.h"

class Camera {
private:
    Eigen::Vector3d translation;
    Eigen::Matrix<double, 4, 4> transation_Matrix;

    Eigen::Matrix<double, 3, 3> rotation;
    Eigen::Matrix<double, 4, 4> rotation_H;

    Eigen::Matrix<double, 3, 4> extrinsics;

    Eigen::Matrix<double, 3, 3> intrinsics;
    // p = intrinsic * extrinsic = 3 by 3 : 3 by 4 = 3*4
    Eigen::Matrix<double, 3, 4> projective;
    Eigen::Matrix<double, 4, 3> pseudoInverse;

    Eigen::Vector3d cameraCenter;

    MyPlane pi = MyPlane(Eigen::Vector3d(0, 1, 0), Eigen::Vector3d(0,0,0));

    // these 3 variables represent the ground plane setting
    int gridRadius = 0;
    int gridStep = 0;
    int atHeight = 0;

    std::vector<cv::Point3_<int> > coordinates;
    std::vector<cv::Point_<double> > projectedCoordinates;

    std::vector<cv::Point_<double> > projectedLeftEdgePoints;
    std::vector<cv::Point_<double> > projectedRightEdgePoints;
    std::vector<cv::Point_<double> > projectedUpperEdgePoints;
    std::vector<cv::Point_<double> > projectedBottomEdgePoints;

    // helper methods
    Eigen::Vector3d updateCameraCenter();

public:
    Camera();

    void updateCameraSetting(double thetaX, double thetaY, double thetaZ, const Eigen::Vector3d &translation, double focalLength, double cu, double cv);
    cv::Point_<double> project3DPointOntoImage(const cv::Point3_<double>& p);
    void setReferencePlane();
    void setReferencePlaneParameters(int gridStep, int gridRadius, int atHeight);

    const Eigen::Vector3d getIntersectionInHomogeneousCoordinates(const cv::Point_<double>& imagePoint, const MyPlane& pi);
    const Eigen::Matrix<double, 3, 4>& getExtrinsics() const;
    const Eigen::Matrix<double, 3, 3>& getIntrinsics() const;
    const Eigen::Matrix<double, 3, 3>& getRotation() const;
    const Eigen::Vector3d &getTranslation() const;
    const Eigen::Matrix<double, 4, 3>& getPseudoInverse() const;
    const MyPlane& getGroundPlane() const;
    const Eigen::Vector3d &getCameraCenter() const;

    void drawReferencePlaneOnFrame(cv::Mat& frame);
    void drawOriginOnFrame(cv::Mat& frame);
};


#endif //COSC480_CAMERA_H
