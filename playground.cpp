//
// Created by zwpdbh on 24/09/2017.
//

#include <Eigen/Dense>
#include <iostream>
#include "MyLib.h"
#include "MyPlane.h"

using namespace std;

int main(int argc, char* argv[]) {
    Eigen::Vector3d normV(10, 2, 1);
    Eigen::Vector3d p(14, 5, 11);

    MyPlane pi(normV, p);
    cout << "p1 = " << endl << pi.getP1() << endl;
    cout << "p2 = " << endl << pi.getP2() << endl;
    cout << "p3 = " << endl << pi.getP3() << endl;

    Eigen::Vector3d q(0, 0, 0);
    cout << pi.distanceFromPoint(q) << endl;
    cout << "normV is\n" << pi.getNormV();
}