//
// Created by zwpdbh on 2017/11/2.
//

#include "Process.h"
#include "Blob.h"

/**Constructor
 @param camera is a camera model which includes settings and operations included in camera*/
Process::Process(const Camera &camera) {
    this->camera = camera;
    this->pMOG2 = cv::createBackgroundSubtractorMOG2();
}


/**return the find contours from image*/
void Process::findContours(cv::Mat& image) {
//    std::vector<std::vector<cv::Point_<double>>> test;
//    std::vector<cv::Vec4i> hierarchy;
//    cv::findContours(image, test, hierarchy, 1, 1);
    std::cout << image.size << std::endl;
    cv::findContours(image, this->contours, cv::RETR_LIST, cv::CHAIN_APPROX_NONE);
    std::cout << "anything" << std::endl;
//    if (this->contours.empty()) {
//        std::cerr << "found error" << std::endl;
//    } else {
//        cv::findContours(image, this->contours, this->hierarchy, 1, 1);
//    }

}

/**create Blobs from contours
 @param contours are array of contours*/
void Process::getBlobsFromContours() {
    Blob::setCamera(this->camera);
    for (const std::vector<cv::Point>& each: contours) {
        Blob blob(each);
        if (blob.getMaxy() - blob.getMiny() > 20) {
            this->blobs.push_back(blob);
        }
    }

}


void Process::dilation(cv::Mat &frame, int dilation_size, int dilation_type) {
    cv::Mat kernel = cv::getStructuringElement(
            dilation_type,
            cv::Size_<int>(2 * dilation_size + 1, 2 * dilation_size + 1),
            cv::Point_<int>(dilation_size, dilation_size)
    );

    dilate(frame, frame, kernel);
}

void Process::erosion(cv::Mat &frame, int erosion_size, int erosion_type) {
    cv::Mat kernel = cv::getStructuringElement(
            erosion_type,
            cv::Size_<int>(2 * erosion_size + 1, 2*erosion_size + 1),
            cv::Point_<int>(erosion_size, erosion_size)
    );

    erode(frame, frame, kernel);
}

void Process::toBinaryFrame(cv::Mat &frame) {
    frame.convertTo(frame, CV_8UC1);
}

void Process::applyBackgroundForegroundSubtraction(cv::Mat &frame) {
    this->pMOG2->apply(frame, frame);
}

void Process::computeBlobsCorresponding3dPoints() {
    for (auto& blob: blobs) {
        std::vector<Eigen::Vector3d> pointsIn3d;
        for(auto& eachPoint: blob.getContour()) {
            pointsIn3d.push_back(this->camera.getIntersectionInHomogeneousCoordinates(eachPoint, blob.getWall()));
        }
        blob.setPointsIn3d(pointsIn3d);
    }
}

const std::vector<Blob> &Process::getBlobs() const {
    return blobs;
}
