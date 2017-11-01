//
// Created by zwpdbh on 24/09/2017.
//

#ifndef COSC480_MYPLANE_H
#define COSC480_MYPLANE_H

#include <Eigen/Dense>

class MyPlane {
private:
    /*a plane is represented by a point on plane and the norm vector of plane*/
    Eigen::Vector3d p;
    Eigen::Vector3d normV;

    /*a plane's homogeneous representation is a 4 dimension vector*/
    Eigen::Vector4d homoPi;


public:
    // plane is created by a point on the plane and the norm vector goes through it
    MyPlane(const Eigen::Vector3d& normV, const Eigen::Vector3d& p);

    /*getter and setters*/
    const Eigen::Vector3d &getP() const;

    const Eigen::Vector3d &getNormV() const;

    const Eigen::Vector4d &getHomoPi() const;


};

#endif //COSC480_MYPLANE_H
