//
// Created by zwpdbh on 24/09/2017.
//

#ifndef COSC480_MYPLANE_H
#define COSC480_MYPLANE_H

#include <Eigen/Dense>

class MyPlane {
public:
    MyPlane(const Eigen::Vector3d &p1, const Eigen::Vector3d &p2, const Eigen::Vector3d &p3);
    MyPlane(const Eigen::Vector3d &normV, const Eigen::Vector3d &p);

    /*given a point in 3D, compute the plane's distance to that point*/
    double distanceFromPoint(const Eigen::Vector3d &q);

    /*getter and setters*/
    const Eigen::Vector3d &getP() const;

    const Eigen::Vector3d &getNormV() const;

    const Eigen::Vector4d &getHomoPi() const;

    const Eigen::Vector3d &getP1() const;

    const Eigen::Vector3d &getP2() const;

    const Eigen::Vector3d &getP3() const;

private:
    /*a plane is represented by a point on plane and the norm vector of plane*/
    Eigen::Vector3d p;
    Eigen::Vector3d normV;

    /*a plane's homogeneous representation is a 4 dimension vector*/
    Eigen::Vector4d homoPi;

    /*a plane can also be represented by 3 point in 3D*/
    Eigen::Vector3d p1;
    Eigen::Vector3d p2;
    Eigen::Vector3d p3;
};

#endif //COSC480_MYPLANE_H
