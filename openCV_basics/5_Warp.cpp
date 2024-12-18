#include <opencv2/opencv.hpp>
#include <iostream>


///////////////////////////////////////////////////////
///                      Warp:                      ///
///////////////////////////////////////////////////////

int main()
{
	// Destination image size:
	float w = 250, h = 350;

	std::string path = "Resources/cards.jpg";
	cv::Mat img = cv::imread(path);

	cv::Mat matrix_king, matrix_queen;
	cv::Mat imgKing, imgQueen;

	// 4 float-type 2D points:
	cv::Point2f points_king[4] =
	{
		{529, 142}, {771, 190},
		{405, 395}, {674, 457}
	};

	cv::Point2f points_queen[4] =
	{
		{64, 324}, {336, 278},
		{90, 633}, {400, 573}
	};

	cv::Point2f points[4] =
	{
		{0, 0}, {w, 0},
		{0, h}, {w, h}
	};

	matrix_king = cv::getPerspectiveTransform(points_king, points);
	matrix_queen = cv::getPerspectiveTransform(points_queen, points);

	cv::warpPerspective(img, imgKing, matrix_king, cv::Point(w, h));
	cv::warpPerspective(img, imgQueen, matrix_queen, cv::Point(w, h));

	for (int i = 0; i < 4; ++i)
	{
		cv::circle(img, points_king[i], 27, cv::Scalar(0, 0, 255), 2);
		cv::circle(img, points_queen[i], 27, cv::Scalar(0, 0, 255), 2);

		cv::circle(img, points_king[i], 6, cv::Scalar(0, 0, 255), cv::FILLED);
		cv::circle(img, points_queen[i], 6, cv::Scalar(0, 0, 255), cv::FILLED);
	}

	imshow("Image", img);
	imshow("King", imgKing);
	imshow("Queen", imgQueen);

	cv::waitKey(0);

	return 0;
}