#include <opencv2/opencv.hpp>
#include <iostream>


///////////////////////////////////////////////////////
///                Color detection:                 ///
///////////////////////////////////////////////////////

int main()
{
	// std::string path = "Resources/HSV.png";
	// std::string path = "Resources/equation.jpg";
	std::string path = "Resources/Bogdan.jpg";
	cv::Mat img = cv::imread(path);

	// cv::resize(img, img, cv::Size(), 0.6, 0.6, cv::INTER_LANCZOS4);

	cv::Mat imgHSV, mask;
	cvtColor(img, imgHSV, cv::COLOR_BGR2HSV);

	int h_min = 7, h_max = 12;
	int s_min = 87, s_max = 141;
	int v_min = 49, v_max = 229;

	cv::namedWindow("Trackbars", (900, 300));

	cv::createTrackbar("Цвет h_min", "Trackbars", &h_min, 179);
	cv::createTrackbar("Цвет h_max", "Trackbars", &h_max, 179);
	cv::createTrackbar("Насыщенность s_min", "Trackbars", &s_min, 255);
	cv::createTrackbar("Насыщенность s_max", "Trackbars", &s_max, 255);
	cv::createTrackbar("Яркость v_min", "Trackbars", &v_min, 255);
	cv::createTrackbar("Яркость v_max", "Trackbars", &v_max, 255);

	while (true)
	{
		cv::Scalar lower(h_min, s_min, v_min);
		cv::Scalar upper(h_max, s_max, v_max);

		inRange(imgHSV, lower, upper, mask);

		imshow("Image BGR", img);
		// imshow("Image HSV", imgHSV);
		imshow("Image mask", mask);

		// cv::imwrite("Resources/Bogdan_mask.jpg", mask);

		cv::waitKey(1);
	}
	 
	return 0;
}