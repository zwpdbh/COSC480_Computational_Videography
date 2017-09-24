//
// Created by zwpdbh on 24/09/2017.
//

#include "MyPlane.h"


MyPlane::MyPlane(Eigen::Vector3d p1, Eigen::Vector3d p2, Eigen::Vector3d p3) {
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;

    this->normV = (p1 - p3).cross(p2);
    this->normV.normalize();
    this->p = this->p3;

    this->homoPi << this.no
}

double MyPlane::distanceFromPoint(Eigen::Vector3d q) {
    return 0;
}
