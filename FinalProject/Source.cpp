#include "opencv2/opencv.hpp"
#include <iostream>
#include "Transformations.h"

int main() {

	std::string winName = "Final Project";	
	cv::Mat source = cv::imread("test.jpg", cv::IMREAD_COLOR);

	make_trackbar_windows();
	while(true){
	cv::Mat output = allTransformations(&source, sX, sY, bX, bY, tX, tY, r, wrp1, wrp2);
	cv::imshow(winName, output);
	cv::waitKey(50);
	}
	return 0;
}