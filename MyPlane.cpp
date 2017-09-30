//
// Created by zwpdbh on 24/09/2017.
//

#include "MyPlane.h"
#include "MyLib.h"
#include <iostream>

using namespace std;



/**
 * a plane can be formed by three points
 */
MyPlane::MyPlane(const Eigen::Vector3d &p1, const Eigen::Vector3d &p2, const Eigen::Vector3d &p3) {
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;

    this->normV = (p1 - p3).cross(p2 - p3);
    this->normV.normalize();
    this->p = this->p3;

    this->homoPi << this->normV[0],
            this->normV[1],
            this->normV[2],
            -this->p3.dot(this->p1.cross(this->p2));
}


/**
 * a plane can be defined by a point on plane and a norm vector
 */
MyPlane::MyPlane(const Eigen::Vector3d &normV, const Eigen::Vector3d &p) {
    this->p = p;
    this->normV = normV;
    this->p3 = this->p;

    /*how to just arbitrary give two points on that plane*/
    double d = this->normV.dot(this->p);

    if (this->normV[2] != 0) {
        /*take x = 1, y =1, compute z*/
        double z1 = (d - (this->normV[0] + this->normV[1])) / this->normV[2];

        /*take x = 1, y = -1*/
        double z2 = (d - (this->normV[0] - this->normV[1])) / this->normV[2];

        Eigen::Vector3d p1(1, 1, z1);
        Eigen::Vector3d p2(1, -1, z2);

        this->p1 = p1;
        this->p2 = p2;
    } else {
        Eigen::Vector3d p1(1, 1, 0);
        Eigen::Vector3d p2(1, -1, 0);

        this->p1 = p1;
        this->p2 = p2;
    }

    this->homoPi << this->normV[0],
            this->normV[1],
            this->normV[2],
            -this->p3.dot(this->p1.cross(this->p2));
}


/**
 * given a point in 3D, compute the distance to this plane from that point
 */
double MyPlane::distanceFromPoint(const Eigen::Vector3d &q) {
    Eigen::Vector3d v = this->p - q;
    Eigen::Vector3d project_v_on_n = (this->normV.dot(v)) * this->normV;
    return project_v_on_n.norm();
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

const Eigen::Vector3d &MyPlane::getP1() const {
    return p1;
}

const Eigen::Vector3d &MyPlane::getP2() const {
    return p2;
}

const Eigen::Vector3d &MyPlane::getP3() const {
    return p3;
}
