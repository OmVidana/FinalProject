#include "opencv2/opencv.hpp"
#include <iostream>
#include "Transformations.h"

int main() {

	std::string winName = "Test";
	cv::Mat source = cv::imread("test.jpg", cv::IMREAD_COLOR);

	cv::Mat output = allTransformations(&source, 1, 1, 0, 0 , 90, 0, 0.5);

	cv::imshow(winName, source);
	cv::waitKey(0);

	cv::imshow(winName, output);
	cv::waitKey(0);

	return 0;
}