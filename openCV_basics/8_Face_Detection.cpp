#include <opencv2/opencv.hpp>
#include <iostream>


///////////////////////////////////////////////////////
///                      title                      ///
///////////////////////////////////////////////////////

int main()
{
	std::string path = "Resources/face.png";
	cv::Mat img = cv::imread(path);
	cv::resize(img, img, cv::Size(), 0.7, 0.7);

	cv::CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");

	if (faceCascade.empty())
	{
		std::cout << "XML file not loaded";
		return 0;
	}

	std::vector <cv::Rect> rects;
	faceCascade.detectMultiScale(img, rects, 1.1, 10);

	for (int i = 0; i < rects.size(); ++i)
	{
		cv::rectangle(img, rects[i].tl(), rects[i].br(), cv::Scalar(255, 255, 0), 2);
	}

	imshow("Image", img);
	cv::waitKey(0);

	return 0;
}