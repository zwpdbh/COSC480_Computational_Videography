//
// Created by zwpdbh on 2017/11/2.
//

#include "Blob.h"
Blob::Blob(const std::vector<cv::Point_<double>>& contour, const Camera& camera) {
    this->contour = contour;
    this->camera = camera;

    this->minx = this->contour.at(0).x;
    this->maxx = this->contour.at(0).x;
    this->miny = this->contour.at(0).y;
    this->maxy = this->contour.at(0).y;

    for (const cv::Point_<double>& each: contour) {
        updateMaximumAndMinimum(each.x, each.y);
    }

    this->lowestPoint2d = cv::Point_<double>((this->minx + this->maxx) / 2, this->maxy);
    this->footPoint = this->camera.getIntersectionInHomogeneousCoordinates(lowestPoint2d, this->camera.getGroundPlane());

//    MyPlane pi(Eigen::Vector3d(0, 0, 1), footPoint);
//    this->wall = pi;

    // I have to give MyPlane a default constructor to do this, otherwise it has error and I have ot use above method.
    this->wall = MyPlane(Eigen::Vector3d(0, 0, 1), footPoint);
}

void Blob::updateMaximumAndMinimum(const double& x, const double& y) {
    this->minx = std::min(this->minx, x);
    this->miny = std::min(this->miny, y);
    this->maxx = std::max(this->maxx, x);
    this->maxy = std::max(this->maxy, y);
}

double Blob::getMinx() const {
    return minx;
}

double Blob::getMaxx() const {
    return maxx;
}

double Blob::getMiny() const {
    return miny;
}

double Blob::getMaxy() const {
    return maxy;
}

void Blob::setPointsIn3d(const std::vector<Eigen::Vector3d>& pointsIn3d) {
    for (auto each: pointsIn3d) {
        this->pointsIn3d.push_back(cv::Point3_<double>(each[0], each[1], each[2]));
    }
}

const std::vector<cv::Point_<double>> &Blob::getContour() const {
    return contour;
}

const MyPlane &Blob::getWall() const {
    return wall;
}
