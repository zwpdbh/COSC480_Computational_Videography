#include <opencv2/video.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

#include "MyLib.h"

using namespace cv;
using namespace std;

char key;
string videoFile = "/Users/zw/code/C++_Projects/Computer_Vision_with_OpenCV/test_data/vtest.avi";
string windowName = "screen";

VideoCapture videoCapture(videoFile);
MyLib myLib;
vector<KeyPoint> keyPoints;
Ptr<BackgroundSubtractorMOG2> backgroundSubtractor;

Mat image;
Mat foregroundMask;


void processVideo(String);
void showFrameRate(Mat *);

int main(int argc, char *argv[]) {
    if (!videoCapture.isOpened()) {
        cerr << "Unable to open video file: " << videoFile << endl;
        exit(EXIT_FAILURE);
    }

    key = 0;

    namedWindow(windowName);
    processVideo(videoFile);

    destroyAllWindows();
    return EXIT_SUCCESS;
}

void processVideo(string videoFile) {
    while (key != 'q' && key != 27) {
        if (!videoCapture.read(image)) {
            cerr << "Unable to read next frame." << endl;
            cerr << "Exiting..." << endl;
            exit(EXIT_FAILURE);
        }
        showFrameRate(&image);

        backgroundSubtractor->apply(image, foregroundMask);

        myLib.erosion(&foregroundMask, &foregroundMask, 1, MORPH_ELLIPSE);
        threshold(foregroundMask, foregroundMask, 20, 255, 1);

        myLib.getBlobs(&foregroundMask, &keyPoints);
        drawKeypoints(foregroundMask, keyPoints, foregroundMask, Scalar_<int>(0,0,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

        imshow("Frame", image);
        imshow("foreground mask", foregroundMask);

        key = (char) waitKey(30);
    }
}

void showFrameRate(Mat *image) {
    stringstream ss;
    rectangle(*image, Point_(10, 2), Point_(100, 20), Scalar_(255, 255, 255), 1);
    ss << videoCapture.get(CAP_PROP_POS_FRAMES);
    string frameNumberString = ss.str();
    putText(*image, frameNumberString.c_str(), cv::Point_(15, 15), FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));
}