#pragma once
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

inline const int alpha_slider_max = 100;
inline int vars[9];
inline double sX, sY, bX, bY, tX, tY, r, wrp1, wrp2;
inline cv::Mat src1;
inline cv::Mat src2;
inline cv::Mat dst;

static void on_trackbar(int, void*);
void make_trackbar_windows(void);