//
// Created by zwpdbh on 24/09/2017.
//

#include "MyLine.h"
#include "MyLib.h"
#include <Eigen/Dense>

MyLine::MyLine(const Eigen::Vector3d &p1, const Eigen::Vector3d &p2) {
    this->p1 = p1;
    this->p2 = p2;

    this->hp1 = MyLib::getCorrespondingHomogeneousOneFrom(this->p1);
    this->hp2 = MyLib::getCorrespondingHomogeneousOneFrom(this->p2);
}

MyLine::MyLine(const Eigen::Vector4d &hp1, const Eigen::Vector4d &hp2) {
    this->hp1 = hp1;
    this->hp2 = hp2;

    this->p1 = MyLib::getCorrespondingEuclideanOneFrom(this->hp1);
    this->p2 = MyLib::getCorrespondingEuclideanOneFrom(this->hp2);
}

MyLine::MyLine(const Eigen::Vector3d &lineDirection) {
    Eigen::Vector3d origin(0, 0, 0);
    this->p1 = origin;
    this->p2 = lineDirection;

    this->hp1 = MyLib::getCorrespondingHomogeneousOneFrom(this->p1);
    this->hp2 = MyLib::getCorrespondingHomogeneousOneFrom(this->p2);
}


const Eigen::Vector3d &MyLine::getLineDirection() const {
    return this->p2 - this->p1;
}

const Eigen::Vector3d &MyLine::getP0() const {
    return this->p1;
}
