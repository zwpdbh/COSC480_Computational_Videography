//
// Created by zwpdbh on 2017/11/2.
//

#ifndef COSC480_BLOB_H
#define COSC480_BLOB_H

#include <iostream>
#include <opencv2/core/types.hpp>
#include "MyPlane.h"
#include "Camera.h"

class Blob {
private:
    std::vector<cv::Point_<double>> contour;
    std::vector<cv::Point3_<double>> pointsIn3d;

    cv::Point_<double> lowestPoint2d;
    Eigen::Vector3d footPoint;
    Camera camera;
    MyPlane wall;

    double minx;
    double maxx;
    double miny;
    double maxy;

    // helper method
    void updateMaximumAndMinimum(const double& x, const double& y);

public:
    Blob() = default;
    Blob(const std::vector<cv::Point_<double> >& contour, const Camera& camera);

    /**setters and getters*/
    void setPointsIn3d(const std::vector<Eigen::Vector3d>& pointsIn3d);
    const std::vector<cv::Point_<double>> &getContour() const;

    const MyPlane &getWall() const;

    double getMinx() const;

    double getMaxx() const;

    double getMiny() const;

    double getMaxy() const;
};


#endif //COSC480_BLOB_H
