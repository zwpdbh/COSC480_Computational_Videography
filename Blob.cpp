//
// Created by zwpdbh on 2017/11/2.
//

#include "Blob.h"

/**Initialize the static member independently, with a separate state- ment outside the class declaration
 * This initialization goes in the methods file, not in the class declaration file.
 * That’s because the class declaration is in a header file, and a program may include a header file in
 * several other files.That would result in multiple copies of the initialization statement, which is an error.*/
Camera Blob::camera;
// or
//Camera Blob::camera = Camera();

Blob::Blob(const std::vector<cv::Point>& contour) {
    this->contour = contour;

    this->minx = this->contour.at(0).x;
    this->maxx = this->contour.at(0).x;
    this->miny = this->contour.at(0).y;
    this->maxy = this->contour.at(0).y;

    for (const cv::Point& each: contour) {
        updateMaximumAndMinimum(each.x, each.y);
    }

    this->lowestPoint2d = cv::Point_<double>((this->minx + this->maxx) / 2, this->maxy);
    this->footPoint = Blob::getCamera().getIntersectionInHomogeneousCoordinates(lowestPoint2d, Blob::getCamera().getGroundPlane());

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

const std::vector<cv::Point> &Blob::getContour() const {
    return contour;
}

const MyPlane &Blob::getWall() const {
    return wall;
}

void Blob::setCamera(const Camera &camera) {
    Blob::camera = camera;
}

const Camera &Blob::getCamera() {
    return camera;
}
