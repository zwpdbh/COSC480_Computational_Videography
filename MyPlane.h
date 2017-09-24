//
// Created by zwpdbh on 24/09/2017.
//

#ifndef COSC480_MYPLANE_H
#define COSC480_MYPLANE_H

#include <Eigen/Dense>

class MyPlane {
public:
    Eigen::Vector3d p;
    Eigen::Vector3d normV;
    Eigen::Vector4d homoPi;
    Eigen::Vector3d p1;
    Eigen::Vector3d p2;
    Eigen::Vector3d p3;

    MyPlane(Eigen::Vector3d p1, Eigen::Vector3d p2, Eigen::Vector3d p3);

    double distanceFromPoint(Eigen::Vector3d q);
};


#endif //COSC480_MYPLANE_H
