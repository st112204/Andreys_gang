#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


///////////////////////////////////////////////////////
///                Importing images:                ///
///////////////////////////////////////////////////////

void main_importing_images()
{
	std::string path = "Resources/krotek.jpg";
	cv::Mat img = cv::imread(path); // Matrix datatype
	imshow("Window title", img); // Close automatically
	cv::waitKey(0); // 0 is infinity

	return;
}


///////////////////////////////////////////////////////
///                Importing video:                 ///
///////////////////////////////////////////////////////

void main_importing_video()
{
	std::string path = "Resources/baptism.mp4";
	cv::VideoCapture cap(path); // Image sequences from file by path
	cv::Mat img;

	while (true)
	{
		cap.read(img); // cap -> img
		// Next frame in cap

		imshow("Window title", img);
		cv::waitKey(27); // Wait 27 miliseconds
		// Close automatically
	}
	// End with memory access error

	return;
}


///////////////////////////////////////////////////////
///                    Webcam:                      ///
///////////////////////////////////////////////////////

void main_webcam()
{
	cv::VideoCapture cap(0); // Webcam id
	cv::Mat img;

	while (true)
	{
		cap.read(img);

		imshow("Window title", img);
		cv::waitKey(1);
	}
} // Fix: slow webcam (id = 1) capture


///////////////////////////////////////////////////////
///                    main():                      ///
///////////////////////////////////////////////////////

int main()
{
	// main_importing_images();
	// main_importing_video();
	main_webcam();

	return 0;
}