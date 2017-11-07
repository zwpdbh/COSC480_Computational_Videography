//
// Created by zwpdbh on 2017/11/2.
//

#ifndef COSC480_VIDEOPROCESS_H
#define COSC480_VIDEOPROCESS_H

#include "Camera.h"
#include <opencv2/video.hpp>
#include <opencv2/opencv.hpp>
#include "MyPlane.h"
#include "Blob.h"

class Process {
private:
    Camera camera;
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    cv::Ptr<cv::BackgroundSubtractorMOG2> pMOG2;
    std::vector<Blob> blobs;

public:
    /**constructors*/
//    Process() = default;
    explicit Process(const Camera&);

    /**different method to process image frame*/
    void applyBackgroundForegroundSubtraction(cv::Mat& frame);
    void findContours(cv::Mat& image);
    void toBinaryFrame(cv::Mat& frame);
    void dilation(cv::Mat& frame, int dilation_size, int dilation_type);
    void erosion(cv::Mat& frame, int erosion_size, int erosion_type);

    void getBlobsFromContours();
    void computeBlobsCorresponding3dPoints();

    const std::vector<Blob> &getBlobs() const;
};


#endif //COSC480_VIDEOPROCESS_H
