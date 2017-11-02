//
// Created by zwpdbh on 20/06/2017.
//

#include <opencv2/video.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

#include "MyLib.h"
#include "Process.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
    Mat originalFrame;
    Mat frame;

    Ptr<BackgroundSubtractorMOG2> pMOG2;
    char keyboard;

    string videoFile = "/Users/zw/code/C++_Projects/COSC480/recourses/vtest.avi";

    namedWindow("Frame");
    namedWindow("FG Mask MOG 2");

    VideoCapture capture(videoFile);
    if (!capture.isOpened()) {
        cerr << "Unable to open video file: " << videoFile << endl;
        exit(EXIT_FAILURE);
    }

    // prepare camera model
    double thetaX = 30;
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

    // prepare processing
    Process process(myCamera);

    keyboard = 0;
    while (keyboard != 'q' && keyboard != 27) {
        if (!capture.read(frame)) {
            cerr << "Unable to read next frame." << endl;
            cerr << "Exiting..." << endl;
            exit(EXIT_FAILURE);
        }

        originalFrame = frame.clone();
        /**process each video frame*/
        process.toBinaryFrame(frame);
        process.applyBackgroundForegroundSubtraction(frame);
        process.erosion(frame, 2, MORPH_ELLIPSE);
        process.dilation(frame, 2, MORPH_ELLIPSE);
        process.findContours(frame);
        process.getBlobsFromContours();
        cout << "There are total " << process.getBlobs().size() << "blobs. \n" << endl;
        process.computeBlobsCorresponding3dPoints();
        // for each blob's points in 3d, do texture mapping

        imshow("Frame", frame);
        keyboard = (char)waitKey(30);
    }

    capture.release();
    destroyAllWindows();

    return EXIT_SUCCESS;
}