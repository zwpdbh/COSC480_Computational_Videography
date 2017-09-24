//
// Created by zwpdbh on 24/09/2017.
//

#include "MyLine.h"
#include "MyLib.h"
#include <Eigen/Dense>

MyLine::MyLine(Eigen::Vector4d p1, Eigen::Vector4d p2) {
    this->p1 = p1;
    this->p2 = p2;

    this->p3d1 = MyLib::getEuclideanFromHomogeneous(p1);
    this->p3d2 = MyLib::getEuclideanFromHomogeneous(p2);

    this->lineDirection = this->p3d1 - this->p3d2;
}

MyLine::MyLine(Eigen::Vector3d p1, Eigen::Vector3d p2) {
    this->p1 = MyLib::getHomogeneousFromEuclidean(p1);
    this->p2 = MyLib::getHomogeneousFromEuclidean(p2);

    this->p3d1 = p1;
    this->p3d2 = p2;

    this->lineDirection = this->p3d1 - this->p3d2;
}

MyLine::MyLine(Eigen::Vector3d lineDirection) {
    this->lineDirection = lineDirection;
    Eigen::Vector3d v0(0, 0, 0);
    this->p3d1 = v0;
}

Eigen::Vector3d MyLine::getP0() {
    return Eigen::Vector3d();
}

Eigen::Vector3d MyLine::getLineDirection() {
    return Eigen::Vector3d();
}
