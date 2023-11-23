#pragma once
#include "opencv2/opencv.hpp"
#include <iostream>
#include <numbers>

//Linear Transformations

cv::Vec3b bilinearInterpolation(cv::Mat* source, double x, double y);
extern cv::Mat scale(cv::Mat* source, double sX, double sY, bool bilinearMethod = false);
cv::Mat translation(cv::Mat* source, int tX, int tY);
cv::Mat rotation(cv::Mat* source, double r);
extern cv::Mat bias(cv::Mat* source, double bX = 0.0, double bY = 0.0);

//Non Linear Transformations
extern cv::Mat allTransformations(cv::Mat* source, double sX = 1, double sY = 1, int tX = 0, int tY = 0, double r = 0, double bX = 0, double bY = 0);