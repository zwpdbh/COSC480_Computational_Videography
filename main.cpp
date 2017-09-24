//
// Created by zwpdbh on 20/06/2017.
//

#include <opencv2/video.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

#include "MyLib.h"

using namespace cv;
using namespace std;

// Global variables
Mat frame;
Mat fgMaskMOG2;
Ptr<BackgroundSubtractorMOG2> pMOG2;


char keyboard;

string videoFile = "/Users/zw/code/C++_Projects/COSC480/recourses/vtest.avi";

void processVideo(string videoFilename);

int main(int argc, char* argv[]) {

    namedWindow("Frame");
    namedWindow("FG Mask MOG 2");

    pMOG2 = createBackgroundSubtractorMOG2();
    processVideo(videoFile);

    destroyAllWindows();
    return EXIT_SUCCESS;
}

void processVideo(string videoFilename) {
    MyLib lib;
    VideoCapture capture(videoFilename);
    vector<KeyPoint> keyPoints;
    string savedFile1 = "/Users/zw/code/C++_Projects/Computer_Vision_with_OpenCV/test_data/tmp/fgMaskMOG2.jpg";
    string savedFile2 = "/Users/zw/code/C++_Projects/Computer_Vision_with_OpenCV/test_data/tmp/origin.jpg";

    if (!capture.isOpened()) {
        cerr << "Unable to open video file: " << videoFilename << endl;
        exit(EXIT_FAILURE);
    }

    keyboard = 0;
    while (keyboard != 'q' && keyboard != 27) {
        if (!capture.read(frame)) {
            cerr << "Unable to read next frame." << endl;
            cerr << "Exiting..." << endl;
            exit(EXIT_FAILURE);
        }

        pMOG2->apply(frame, fgMaskMOG2);

        // get the frame number and write it on the current frame
        stringstream ss;
        rectangle(frame, cv::Point(10, 2), cv::Point(100, 20), cv::Scalar(255, 255, 255), -1);
        ss << capture.get(CAP_PROP_POS_FRAMES);
        string frameNumberString = ss.str();
        putText(frame, frameNumberString.c_str(), cv::Point(15,15), FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));

        //show the current frame and the fg masks
        lib.erosion(&fgMaskMOG2, &fgMaskMOG2, 1, MORPH_ELLIPSE);
        threshold(fgMaskMOG2, fgMaskMOG2, 20, 255, 1);

        lib.getBlobs(&fgMaskMOG2, &keyPoints);
        drawKeypoints(fgMaskMOG2, keyPoints, fgMaskMOG2, Scalar_<int>(0,0,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

        // need some way to get the near by points

        imshow("Frame", frame);
        imshow("FG Mask MOG 2", fgMaskMOG2);

        //get the input from the keyboard
        keyboard = (char)waitKey(30);

    }
    //delete capture object
    capture.release();
}
