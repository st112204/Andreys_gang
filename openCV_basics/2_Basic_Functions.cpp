#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

///////////////////////////////////////////////////////
///                Basic functions:                 ///
///////////////////////////////////////////////////////

int main()
{
	std::string path = "Resources/krotek.jpg";
	cv::Mat img = cv::imread(path);
	cv::Mat imgGray, imgRGB, imgBlur, imgCanny, imgDilate, imgErode;

	cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY); // Grey
	cv::cvtColor(img, imgRGB, cv::COLOR_BGR2RGB); // BGR -> RGB

	cv::GaussianBlur(img, imgBlur, cv::Size(7, 7), 5, 0); // Blur
	cv::Canny(imgBlur, imgCanny, 25, 75); // Canny

	// Just a kernel for dilation and erotion:
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2, 2));

	erode(imgCanny, imgErode, kernel); // More thin lines
	dilate(imgCanny, imgDilate, kernel); // More bold lines

	imshow("Original (BGR)", img);
	imshow("Grey", imgGray);
	imshow("BGR -> RGB", imgRGB);

	imshow("Blur", imgBlur);

	imshow("Blur & Canny", imgCanny);

	imshow("Blur & Canny & Erode", imgErode);
	imshow("Blur & Canny & Dilate", imgDilate);

	cv::waitKey(0);

	return 0;
}