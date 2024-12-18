#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

///////////////////////////////////////////////////////
///                    Resize:                      ///
///////////////////////////////////////////////////////

void main_resize()
{
	std::string path = "Resources/krotek.jpg";
	cv::Mat img = cv::imread(path);
	cv::Mat imgResize;

	std::cout << img.size() << std::endl;
	
	// resize(img, imgResize, cv::Size(), 1.8, 0.6);

	resize(img, imgResize, cv::Size(1920, 768), 0.0, 0.0);

	// cv::imwrite("Resources/krotek_resize.jpg", imgResize);

	imshow("Image", img);
	imshow("Resize", imgResize);

	cv::waitKey(0);

	return;
}

///////////////////////////////////////////////////////
///                      Crop:                      ///
///////////////////////////////////////////////////////

void main_crop()
{
	std::string path = "Resources/krotek.jpg";
	cv::Mat img = cv::imread(path);
	cv::Mat imgCrop;

	// ROI = Region Of Interest
	// cv::Rect roi(x_left, y_top, width, height):
	cv::Rect roi(10, 10, 300, 50);
	imgCrop = img(roi); // Crop by rectangle

	imshow("Image", img);
	imshow("Crop", imgCrop);

	cv::waitKey(0);

	return;
}

///////////////////////////////////////////////////////
///                     main():                     ///
///////////////////////////////////////////////////////

int main()
{
	// main_resize();
	main_crop();

	return 0;
}