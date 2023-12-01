#include "opencv2/opencv.hpp"
#include <iostream>
#include "Transformations.h"

int main() {

	std::string winName = "Final Project";	
	cv::Mat source = cv::imread("test.jpg", cv::IMREAD_COLOR);

	cv::VideoCapture capture; //Open Default Camera in this Object
	capture.open(0);
	if (!capture.isOpened())
	{
		//std::cerr << "Camera is not conected to th Object, check the Value or Active Cameras." << std::endl;
		std::cout << "Camera is not conected to th Object, check the Value or Active Cameras." << std::endl;
		return -1;
	}
	cv::namedWindow(winName);
	cv::namedWindow("original");
	make_trackbar_windows();
	while (true)
	{
		cv::Mat frames;

		capture >> frames; //Obtain next frame from camera.
		cv::Mat output = allTransformations(&frames, wrp1, wrp2);

		cv::imshow(winName, output);
		cv::imshow("original", frames);
		//std::cout << frames.cols << frames.rows << std::endl;
		if (cv::waitKey(3) >= 0)
			break;;
	}

	return 0;
}