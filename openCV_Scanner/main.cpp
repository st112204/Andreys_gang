#include "DocScanner.h"

int main()
{
	std::string path = "Resources/paper.jpg";

	cv::Mat
		img = cv::imread(path),
		imgPreproc = preproc(img);
		
	float w = 420, h = 596;

	std::vector<cv::Point> docCont = reorderCont(getCont(imgPreproc));

	cv::Mat imgWarp = getWarp(img, docCont, w, h);

	cv::Rect roi(5, 5, w - 10, h - 10);
	cv::Mat imgCrop = imgWarp(roi);

	drawPoints(img, docCont, cv::Scalar(0, 0, 255));

	imshow("Warp & Crop", imgCrop);
	imshow("Warp", imgWarp);
	imshow("Preprocessed", imgPreproc);
	imshow("Original", img);

	cv::waitKey(0);

	return 0;
}