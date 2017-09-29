//
// Created by zwpdbh on 24/09/2017.
//

#include <Eigen/Dense>
#include <iostream>
#include "MyLib.h"
#include "MyPlane.h"

using Eigen::MatrixXd;
using Eigen::Vector3d;

using namespace std;

int main(int argc, char* argv[]) {
    Vector3d normV(1, 1, -1);
    Vector3d p(0, 0, -1);
    MyPlane pi(normV, p);

    Vector3d q(1, 0, 2);

    cout << pi.distanceFromPoint(q);
}