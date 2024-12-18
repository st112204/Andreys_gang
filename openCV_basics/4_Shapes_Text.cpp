#include <opencv2/opencv.hpp>
#include <iostream>

///////////////////////////////////////////////////////
///                 Shapes & Text:                  ///
///////////////////////////////////////////////////////

int main()
{
	// Blank image:
	cv::Mat img(512, 512, CV_8UC3, cv::Scalar(255, 255, 255));
	// CV_ 
	// 8 (bits by pixel: 0..255) 
	// U (unsigned)
	// C3 (3 channels: BGR)

	circle(
		img, 
		cv::Point(256, 256), 
		250, 
		cv::Scalar(0, 0, 0), 
		cv::FILLED
	);

	rectangle(
		img, 
		cv::Point(130, 226), 
		cv::Point(382, 266), 
		cv::Scalar(255, 255, 255), 
		3
	);

	line(
		img, 
		cv::Point(130, 296), 
		cv::Point(382, 296), 
		cv::Scalar(255, 255, 0)
	);

	putText(
		img, 
		"Techno Music", 
		cv::Point(120, 200), 
		cv::FONT_HERSHEY_PLAIN, 
		2.4, // Font scale
		cv::Scalar(255, 0, 255),
		1.5  // Font thickness
	);

	imshow("Image", img);
	cv::waitKey(0);

	return 0;
}