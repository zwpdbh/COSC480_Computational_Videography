//
// Created by zwpdbh on 24/09/2017.
//

#include <Eigen/Dense>
#include <iostream>
#include "MyLib.h"
#include "MyPlane.h"
#include "Camera.h"

using namespace std;

int main(int argc, char* argv[]) {
//    Eigen::Vector3d normV(10, 2, 1);
//    Eigen::Vector3d p(14, 5, 11);
//
//    MyPlane pi(normV, p);
//    cout << "p1 = " << endl << pi.getP1() << endl;
//    cout << "p2 = " << endl << pi.getP2() << endl;
//    cout << "p3 = " << endl << pi.getP3() << endl;
//
//    Eigen::Vector3d q(0, 0, 0);
//    cout << pi.distanceFromPoint(q) << endl;
//    cout << "normV is\n" << pi.getNormV();
//
//    Eigen::Vector3d p1(1, 1, 99);
//    Eigen::Vector3d p2(1, -1, 153);
//    Eigen::Vector3d p3(14, 5, 11);
//    MyPlane pi2(p1, p2, p3);
//
//    cout << endl <<  pi2.distanceFromPoint(q) << endl;
//    cout << endl << pi2.getNormV() << endl;

    Camera camera;
    Eigen::Vector3d translation(0, 1, 20);
    camera.updateCameraSetting(0, 0, 0, translation, 1200, 320, 240);

    cv::Point3_<double> p(1, 2, 3);
    cout << "the origin at image: \n" << camera.getPorjectedPointOnImageFrom(p) << endl;
}