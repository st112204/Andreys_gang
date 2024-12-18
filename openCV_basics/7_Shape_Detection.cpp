#include <opencv2/opencv.hpp>
#include <iostream>


///////////////////////////////////////////////////////
///                Shape detection:                 ///
///////////////////////////////////////////////////////


void prepareImage(cv::Mat& img, cv::Mat& imgPrepared)
{
	cv::Mat
		imgGray,
		imgBlur,
		imgCanny,
		imgDilate;

	cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);

	cv::GaussianBlur(imgGray, imgBlur, cv::Size(3, 3), 3, 0);

	cv::Canny(imgBlur, imgCanny, 25, 75);

	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	cv::dilate(imgCanny, imgDilate, kernel);

	imgPrepared = imgDilate;
}


void getContours(cv::Mat& img, cv::Mat& imgContoured)
{

	std::vector <std::vector <cv::Point>> contours;
	std::vector <cv::Vec4i> hierarchy;

	cv::findContours(img, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

	std::vector <std::vector <cv::Point>> conPoly(contours.size());
	std::vector <cv::Rect> boundRect(contours.size());

	std::string polygonType = "";

	for (int i = 0; i < contours.size(); ++i)
	{
		int area = cv::contourArea(contours[i]);
		// std::cout << area << std::endl;

		if (area > 1000)
		{
			float peri = cv::arcLength(contours[i], true);

			cv::approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			cv::drawContours(imgContoured, conPoly, i, cv::Scalar(0, 150, 0), 2);
			
			boundRect[i] = cv::boundingRect(conPoly[i]);

			cv::rectangle(imgContoured, boundRect[i].tl(), boundRect[i].br(), cv::Scalar(255, 255, 0), 2);

			int sides = (int)conPoly[i].size();

			if (sides == 3)
				polygonType = "Triangle";
			else if (sides == 4)
				polygonType = "Rectangle";
			else if (sides > 4)
				polygonType = "Circle";
			else
				polygonType = "Undefined";

			cv::putText
			(
				imgContoured, 
				polygonType, 
				{ boundRect[i].x, boundRect[i].y - 5 },
				cv::FONT_HERSHEY_DUPLEX,
				0.6,
				cv::Scalar(0, 0, 0),
				1
			);

		}
	}
}


int main()
{
	std::string path = "Resources/shapes.png";

	cv::Mat img = cv::imread(path);

	cv::Mat imgPrepared;
	prepareImage(img, imgPrepared);

	cv::Mat imgContoured = img.clone();
	getContours(imgPrepared, imgContoured);

	imshow("Contoured image", imgContoured);

	cv::waitKey(0);

	return 0;
}