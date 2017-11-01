//
// Created by zwpdbh on 24/09/2017.
//

#include "MyPlane.h"
#include "MyLib.h"
#include <iostream>

using namespace std;


/**
 * a plane can be defined by a point on plane and a norm vector
 */
MyPlane::MyPlane(const Eigen::Vector3d &normV, const Eigen::Vector3d &p) {
    this->normV = normV;
    this->normV.normalize();
    this->p = p;

    double d = -this->normV.dot(this->p);

    this->homoPi[0] = this->normV[0];
    this->homoPi[1] = this->normV[1];
    this->homoPi[2] = this->normV[2];
    this->homoPi[3] = d;

}


const Eigen::Vector3d &MyPlane::getP() const {
    return p;
}

const Eigen::Vector3d &MyPlane::getNormV() const {
    return normV;
}

const Eigen::Vector4d &MyPlane::getHomoPi() const {
    return homoPi;
}
