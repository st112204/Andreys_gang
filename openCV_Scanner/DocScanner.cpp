#include "DocScanner.h"

cv::Mat preproc(cv::Mat& img)
{
	if (img.empty())
	{
		std::cerr << "Error: empty img for preproc()" << std::endl;
		return img;
	}

	cv::Mat imgPreproc;

	cv::cvtColor(img, imgPreproc, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(imgPreproc, imgPreproc, cv::Size(3, 3), 3, 0);
	cv::Canny(imgPreproc, imgPreproc, 25, 75);
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	cv::dilate(imgPreproc, imgPreproc, kernel);

	float scale = 0.5;
	cv::resize(img, img, cv::Size(), scale, scale);
	cv::resize(imgPreproc, imgPreproc, cv::Size(), scale, scale);

	return imgPreproc;
}


std::vector<cv::Point> getCont(const cv::Mat& imgPreproc)
{

	std::vector <std::vector <cv::Point>> contours;
	std::vector <cv::Vec4i> hierarchy;
		cv::findContours(imgPreproc, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	std::vector <std::vector <cv::Point>> conPoly(contours.size());
	std::vector<cv::Point> biggestRect = conPoly[0];
	int maxArea = 0;

	for (int i = 0; i < contours.size(); ++i)
	{
		int area = cv::contourArea(contours[i]);			

		float peri = cv::arcLength(contours[i], true);
		cv::approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

		if (area > maxArea && conPoly[i].size() == 4)
		{
			// drawContours(img, conPoly, i, cv::Scalar(255, 0, 255), 2);
			biggestRect = { conPoly[i][0], conPoly[i][1], conPoly[i][2], conPoly[i][3] };
			maxArea = area;
		}
	}

	if (maxArea == 0)
		std::cerr << "Error: can't see any rectangle" << std::endl;

	return biggestRect;
}


std::vector<cv::Point> reorderCont(std::vector<cv::Point> cont)
{
	cv::Point 
		tl, tr,
		bl, br;

	int y1 = INT_MAX; int y1_id = 0;
	int y2 = INT_MAX; int y2_id = 0;

	for (size_t i = 0; i < 4; ++i)
	{
		if (cont[i].y <= y1)
		{
			y2 = y1;
			y2_id = y1_id;
			y1 = cont[i].y;
			y1_id = i;
		}
		else if (cont[i].y < y2)
		{
			y2 = cont[i].y;
			y2_id = i;
		}
	}

	tl = cont[y1_id];
	tr = cont[y2_id];
	if (tl.x > tr.x)
		std::swap(tl, tr);

	int y3_id = 0;
	int y4_id = 0;

	for (size_t i = 0; i < 4; ++i)
		if (i != y1_id && i != y2_id)
			y3_id = i;

	y4_id = 6 - y1_id - y2_id - y3_id;

	bl = cont[y3_id];
	br = cont[y4_id];
	if (bl.x > br.x)
		std::swap(bl, br);

	std::vector<cv::Point> ordered_points = { tl, tr, bl, br };

	return ordered_points;
}


cv::Mat getWarp(const cv::Mat img, const std::vector<cv::Point> docCont, float w, float h)
{
	cv::Point2f src[4] = { docCont[0], docCont[1], docCont[2], docCont[3] };

	cv::Point2f dst[4] =
	{
		{0, 0}, {w, 0},
		{0, h}, {w, h}
	};

	cv::Mat matrix = cv::getPerspectiveTransform(src, dst);

	cv::Mat imgWarp;
	cv::warpPerspective(img, imgWarp, matrix, cv::Point(w, h));

	return imgWarp;
}


void drawPoints(const cv::Mat img, const std::vector<cv::Point> cont, const cv::Scalar color)
{
	for (int i = 0; i < cont.size(); ++i)
	{
		cv::circle(img, cont[i], 10, color, cv::FILLED);
		cv::putText(img, std::to_string(i), cont[i], cv::FONT_HERSHEY_DUPLEX, 3, color, 2);
	}
}