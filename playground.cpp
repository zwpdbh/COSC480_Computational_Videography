//
// Created by zwpdbh on 24/09/2017.
//


#include <iostream>
#include "Camera.h"
#include "MyLib.h"

using namespace std;

int main(int argc, char* argv[]) {
    double thetaX = 0;
    double thetaY = 0;
    double thetaZ = 0;

    double windowWidth = 640;
    double windowHeight = 480;
    double focalLength = 1200;

    Eigen::Vector3d translationVector(0, 1, 20);

    int gridStep = 1;
    int gridRadius = 4;
    int atHeight = 0;

    double cu = windowWidth / 2;
    double cv = windowHeight / 2;

    Camera myCamera;
    myCamera.setReferencePlaneParameters(gridStep, gridRadius, atHeight);
    myCamera.updateCameraSetting(thetaX, thetaY, thetaZ, translationVector, focalLength, cu, cv);

    cout << "intrinsics: \n" << myCamera.getIntrinsics() << endl;
    cout << "extrinsics: \n" << myCamera.getExtrinsics() << endl;

//    MyLib::comparePosition(myCamera, cv::Point3_<double>(0, 0, 0));
//    MyLib::comparePosition(myCamera, cv::Point3_<double>(0, 0, 1));
//    MyLib::comparePosition(myCamera, cv::Point3_<double>(0, 0, -1));
//    MyLib::comparePosition(myCamera, cv::Point3_<double>(5, 0, -2));
//    MyLib::comparePosition(myCamera, cv::Point3_<double>(-5, 0, 2));
//    MyLib::comparePosition(myCamera, cv::Point3_<double>(-5, 0, 11));
//    MyLib::comparePosition(myCamera, cv::Point3_<double>(7, 0, -1.3));
    cout << "camera center : \n" << myCamera.getCameraCenter() << endl;

    Eigen::Vector4d cameraCenter(0, 1, 20, 1);
    cout << "camera center after rotation and translation is: \n"
         << myCamera.getExtrinsics() * cameraCenter << endl;

    return 0;
}

