//
// Created by zwpdbh on 24/09/2017.
//

#ifndef COSC480_MYLINE_H
#define COSC480_MYLINE_H

#include <Eigen/Dense>

class MyLine {
private:
    Eigen::Vector4d p1;
    Eigen::Vector4d p2;
    Eigen::Vector3d lineDirection;
    Eigen::Vector3d p3d1;
    Eigen::Vector3d p3d2;

public:
    MyLine(Eigen::Vector4d p1, Eigen::Vector4d p2);
    MyLine(Eigen::Vector3d p1, Eigen::Vector3d p2);
    MyLine(Eigen::Vector3d lineDirection);

    Eigen::Vector3d getP0();
    Eigen::Vector3d getLineDirection();
};


#endif //COSC480_MYLINE_H