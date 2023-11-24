#include "Transformations.h"
// Linear Transformations

cv::Vec3b bilinearInterpolation(cv::Mat* source, double x, double y) {
	int y1 = static_cast<int>(floor(y));
	int y2 = std::min(static_cast<int>(ceil(y)), source->rows - 1);
	int x1 = static_cast<int>(floor(x));
	int x2 = std::min(static_cast<int>(ceil(x)), source->cols - 1);

	cv::Vec3b Q11 = source->at<cv::Vec3b>(y1, x1);
	cv::Vec3b Q12 = source->at<cv::Vec3b>(y1, x2);
	cv::Vec3b Q21 = source->at<cv::Vec3b>(y2, x1);
	cv::Vec3b Q22 = source->at<cv::Vec3b>(y2, x2);

	cv::Vec3b R1 = ((Q12 - Q11) / (x2 - x1)) * (x - x1) + Q11;
	cv::Vec3b R2 = ((Q22 - Q21) / (x2 - x1)) * (x - x1) + Q21;
	cv::Vec3b P = ((R2 - R1) / (y2 - y1)) * (y - y1) + R1;

	return P;
}

cv::Mat warping(cv::Mat* source, int amplitude, int frequency) {
	cv::Mat output(source->rows, source->cols, CV_8UC3);

	for (int j = 0; j < output.rows; j++) {
		for (int i = 0; i < output.cols; i++) {
			int u, v;
			if (frequency == 0 || amplitude == 0 || (sin((2 * 3.1416 * j) / frequency))) {
				output.at<cv::Vec3b>(j, i) = 0;
			}

			u = j + amplitude * sin((2 * 3.1416 * j) / frequency);
			v = i;
			if (u >= 0 && u <= output.rows && v >= 0 && v <= output.cols)
			{
				output.at<cv::Vec3b>(j, i) = source->at<cv::Vec3b>(u, v);
			}
			else {
				output.at<cv::Vec3b>(j, i) = 0;
			}
		}
	}

return output;
}

cv::Mat allTransformations(cv::Mat* source, double sX, double sY, int bX, int bY, double tX, double tY, double r, int amplitude, int frequency)
{
	cv::Mat output(static_cast<int>(source->rows * sY), static_cast<int>(source->cols * sX), CV_8UC3);
	cv::Mat mS = (cv::Mat_<double>(3, 3) <<
		sX, 0, 0,
		0, sY, 0,
		0, 0, 1);
	double theta = r * std::numbers::pi * 1 / 180;
	cv::Mat mR = (cv::Mat_<double>(3, 3) <<
		cos(theta), sin(theta), (1 - cos(theta)) * (output.cols * 0.5) - sin(theta) * (output.rows * 0.5),
		-sin(theta), cos(theta), sin(theta) * (output.cols * 0.5) + (1 - cos(theta)) * (output.rows * 0.5),
		0, 0, 1);
	cv::Mat mT = (cv::Mat_<double>(3, 3) <<
		1, 0, tX,
		0, 1, tY,
		0, 0, 1);
	cv::Mat mB = (cv::Mat_<double>(3, 3) <<
		1 + bX * bY, bX, 0,
		bY, 1, 0,
		0, 0, 1);

	cv::Mat transformations = mS * mR * mT * mB;

	for (int y = 0; y < output.rows; y++)
	{
		for (int x = 0; x < output.cols; x++)
		{
			cv::Mat V = (cv::Mat_<double>(3, 1) << x, y, 1);

			cv::Mat res = transformations * V;
			double w = res.at<double>(2, 0);
			double v = res.at<double>(1, 0);
			double u = res.at<double>(0, 0);

			if (v >= 0 && v < source->rows && u >= 0 && u < source->cols)
				output.at<cv::Vec3b>(y, x) = bilinearInterpolation(source, u, v);
			else
				output.at<cv::Vec3b>(y, x) = cv::Vec3b(0, 0, 0);
		}
	}
	
	return warping(&output, amplitude, frequency);
}
