//
// Created by zwpdbh on 24/09/2017.
//

#include <Eigen/Dense>
#include <iostream>
#include "MyLib.h"

using Eigen::MatrixXd;
using namespace std;

int main(int argc, char* argv[]) {

    Eigen::Vector3d v1(10, 20, 30);
    Eigen::Vector3d v2(1, 2, 3);

    std::cout << v1 - v2 << endl;
    v1.normalize();
    std:cout << v1 << endl;
    return 0;

}