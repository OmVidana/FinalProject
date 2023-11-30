#include "Trackbars.h"

static void on_trackbar(int, void*)
{
	sX = vars[0]==0?0.1:((double)vars[0]) / 20.0;
	sY = vars[1] == 0 ? 0.1 : ((double)vars[1]) / 20.0;
	bX = (double)vars[2]/100.0;
	bY = (double)vars[3] / 100.0;
	tX = (double)vars[4];
	tY = (double)vars[5];
	r = (double)vars[6];
	wrp1 = (double)vars[7];
	wrp2 = (double)vars[8];
		/*
	for (int i = 0; i < 9; i++)
		std:: cout << vars[i] << " ";*/
	// std::cout <<"SX"<<sX <<" SY "<<sY << std::endl;
}

void make_trackbar_windows(void)
{

	const std::vector<int> tMaxValues = {100, 100,  200, 200, 50, 50,359, 50, 50};
	const std::vector<int> tMinValues = {1, 1, 0, 0, 0, 0, 0, 1, 1};

	cv::namedWindow("Linear Blend", cv::WINDOW_NORMAL); // Create Window
	char TrackbarName[9][50] = { "Escala X" ,"Escala Y" ,"Sesgo X" ,"Sesgo Y" ,"Traslacion X" ,"Traslacion Y" ,"Rotacion" ,"Amplitude" ,"Frequency" };
	for (int i = 0; i < 9; i++) {
		vars[i] = 1;
		// printf(TrackbarName[i], "Alpha x %", alpha_slider_max);
		cv::createTrackbar(TrackbarName[i], "Linear Blend", &vars[i], tMaxValues.at(i), on_trackbar);
		cv::setTrackbarMin(TrackbarName[i], "Linear Blend", tMinValues.at(i));
	}
	sX = vars[0]==0?0.1:((double)vars[0]) / 20.0;
	sY = vars[1] == 0 ? 0.1 : ((double)vars[1]) / 20.0;
	bX = (double)vars[2]/100.0;
	bY = (double)vars[3] / 100.0;
	tX = (double)vars[4];
	tY = (double)vars[5];
	r = (double)vars[6];
	wrp1 = (double)vars[7];
	wrp2 = (double)vars[8];
	return;
}