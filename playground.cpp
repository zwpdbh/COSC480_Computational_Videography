//
// Created by zwpdbh on 24/09/2017.
//

#include <Eigen/Dense>
#include <iostream>
#include "MyLib.h"
#include "MyPlane.h"

using namespace std;

int main(int argc, char* argv[]) {
    Eigen::Vector3d normV(1, 1, 1);
    Eigen::Vector3d p(0, 0, 1000);

    MyPlane pi(normV, p);

    Eigen::Vector3d q(0, 0, 0);

    cout << pi.distanceFromPoint(q) << endl;


    Eigen::Vector3d n(2, 2, 0);
    cout << "n's length is : " << n.norm();
}