//
// Created by zwpdbh on 21/09/2017.
//

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include "MyLib.h"

#include <iostream>

using namespace std;
using namespace cv;

/**
 * default constructor
 * */
MyLib::MyLib() {}

/**
 * static method which show the optical flow result
 */
void MyLib::displayOpticalFlow(cv::Mat& flow, std::string windowName) {
    //extraxt x and y channels
    cv::Mat xy[2]; //X,Y
    cv::split(flow, xy);

    //calculate angle and magnitude
    cv::Mat magnitude, angle;
    cv::cartToPolar(xy[0], xy[1], magnitude, angle, true);

    //translate magnitude to range [0;1]
    double mag_max;
    cv::minMaxLoc(magnitude, 0, &mag_max);
    magnitude.convertTo(magnitude, -1, 1.0 / mag_max);

    //build hsv image
    cv::Mat _hsv[3], hsv;
    _hsv[0] = angle;
    _hsv[1] = cv::Mat::ones(angle.size(), CV_32F);
    _hsv[2] = magnitude;
    cv::merge(_hsv, 3, hsv);

    //convert to BGR and show
    cv::Mat bgr;//CV_32FC3 matrix
    cv::cvtColor(hsv, bgr, cv::COLOR_HSV2BGR);
    cv::imshow(windowName, bgr);
}


/**
 * helper method for screenshot which get called when slide the trackbar to a new position
 */
void onTrackbarSlide(int pos, void* userdata) {
    cvSetCaptureProperty(
            (CvCapture*) userdata,
            CV_CAP_PROP_POS_FRAMES,
            pos
    );
}

/**
 * static methed which display a video and can use trackbar to go to specified frame
 */
void MyLib::screenshotFromVideo(const char *fileName, std::string savedPath) {
    int slider_position = 0;
    CvCapture* capture = NULL;
    const char* windowName = "Output";
    const char* trackbarName = "Position";
    void* data;

    cvNamedWindow(windowName, CV_WINDOW_AUTOSIZE);
    capture = cvCreateFileCapture(fileName);

    int numOfFrames = (int) cvGetCaptureProperty(
            capture,
            CV_CAP_PROP_FRAME_COUNT
    );

    if (numOfFrames != 0) {
        cvCreateTrackbar2(
                trackbarName,
                windowName,
                &slider_position,
                numOfFrames,
                onTrackbarSlide,
                capture
        );

    }

    IplImage* frame;
    string savedFile;


    for (int i = 0; i < numOfFrames; ++i) {
        frame = cvQueryFrame(capture);
        savedFile = savedPath + "/" + to_string(i + 1) + ".jpg";
        if (!frame) break;
        cvShowImage(windowName, frame);
        cout<< savedFile << endl;
        char c = (char)cvWaitKey(30);
        if (c == 27) break;
    }

    cvReleaseCapture(&capture);
    cvDestroyWindow(windowName);
}



/**
 * dilation
 */
void MyLib::dilation(cv::Mat& src, cv::Mat& dst, int dilation_size, int dilation_type) {
    Mat kernel = getStructuringElement(
            dilation_type,
            Size_<int>(2 * dilation_size + 1, 2 * dilation_size + 1),
            Point_<int>(dilation_size, dilation_size)
    );

    dilate(src, dst, kernel);
}

/**
 * erosion
 */
void MyLib::erosion(cv::Mat& src, cv::Mat& dst, int erosion_size = 0, int erosion_type = MORPH_RECT) {
    Mat kernel = getStructuringElement(
            erosion_type,
            Size_<int>(2 * erosion_size + 1, 2*erosion_size + 1),
            Point_<int>(erosion_size, erosion_size)
    );

    erode(src, dst, kernel);
}


/**
 * get blobs
 */
void MyLib::getBlobs(cv::Mat& src, std::vector<cv::KeyPoint>& keyPoints) {
    SimpleBlobDetector::Params params;

    // Change thresholds
    params.minThreshold = 100;
    params.maxThreshold = 200;

    // Filter by Area.
    params.filterByArea = true;
    params.minArea = 200;

    // Filter by Circularity
    params.filterByCircularity = true;
    params.minCircularity = 0.01;

    // Filter by Convexity
    params.filterByConvexity = true;
    params.minConvexity = 0.5;

    // Filter by Inertia
    params.filterByInertia = true;
    params.minInertiaRatio = 0.01;

    Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);

    //    Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create();
    detector->detect(src, keyPoints);
}

/**
 * Given two point in 3D, compute their Euclidean distance
 */
double MyLib::distanceBetween(const Eigen::Vector3d &p1, const Eigen::Vector3d &p2) {
    return sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2) + pow(p1[2] - p2[2], 2));
}

/*transform a Euclidean vector into Homogeneous one*/
Eigen::Vector4d MyLib::getCorrespondingHomogeneousOneFrom(const Eigen::Vector3d &v) {
    return Eigen::Vector4d(v[0], v[1], v[2], 1);
}

/*transform a Homogeneous vector into Euclidean one*/
Eigen::Vector3d MyLib::getCorrespondingEuclideanOneFrom(const Eigen::Vector4d &v) {
    if (v[3] != 0) {
        return Eigen::Vector3d(v[0] / v[3], v[1] / v[3], v[2] / v[3]);
    } else {
        return (Eigen::Vector3d)nullptr;
    }
}

/**
 * helper function which get radian from degree
 */
double MyLib::getRadian(double degree) {
    return degree * 3.14159265 / 180.0;
}


/**
 * try to get OpenCV Mat from Eigen Matrix.
 */
cv::Mat MyLib::getRoationMat(const Eigen::Matrix<double, 3, 3> &rotation) {
    double m[3][3] = {
            {rotation(0, 0), rotation(0, 1), rotation(0, 2)},
            {rotation(1, 0), rotation(1, 1), rotation(1, 2)},
            {rotation(2, 0), rotation(2, 1), rotation(2, 2)}
    };
    cv::Mat mat(3, 3, CV_32F, m);
    return mat;
}
