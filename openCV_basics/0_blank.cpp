#include <opencv2/opencv.hpp>
#include <iostream>


///////////////////////////////////////////////////////
///                      title                      ///
///////////////////////////////////////////////////////

int main()
{
	std::string path = "Resources/krotek.jpg";
	cv::Mat img = cv::imread(path);

	imshow("Image", img);

	cv::waitKey(0);

	return 0;
}