#pragma once
#include "opencv2/opencv.hpp"
#include <iostream>
#include <numbers>
#include "Trackbars.h"

cv::Vec3b bilinearInterpolation(cv::Mat* source, double x, double y);
cv::Mat warping(cv::Mat* source, int amplitude, int frequency);
cv::Mat allTransformations(cv::Mat* source, int amplitude, int frequency);