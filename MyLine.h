//
// Created by zwpdbh on 24/09/2017.
//

#ifndef COSC480_MYLINE_H
#define COSC480_MYLINE_H

#include <Eigen/Dense>

class MyLine {
private:
    Eigen::Vector4d hp1;
    Eigen::Vector4d hp2;
    Eigen::Vector3d p1;
    Eigen::Vector3d p2;

public:
    MyLine(const Eigen::Vector3d &p1, const Eigen::Vector3d &p2);
    MyLine(const Eigen::Vector4d &hp1, const Eigen::Vector4d &hp2);
    MyLine(const Eigen::Vector3d &lineDirection);

    const Eigen::Vector3d &getLineDirection() const;
    const Eigen::Vector3d &getP0() const;
};


#endif //COSC480_MYLINE_H
