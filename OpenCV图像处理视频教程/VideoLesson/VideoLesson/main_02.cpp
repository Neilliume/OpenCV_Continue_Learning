#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	Mat src = imread("E:/repo/opencv/OpenCV_Continue_Learning/OpenCV图像处理视频教程/VideoLesson/VideoLesson/1.jpg");
	if (src.empty())
	{
		printf("Could not load image...\n");
	}

	namedWindow("test opencv setup", CV_WINDOW_AUTOSIZE);
	imshow("test opencv setup", src);

	namedWindow("output window", CV_WINDOW_AUTOSIZE);
	Mat output_image;
	cvtColor(src, output_image, CV_BGR2GRAY);
	//cvtColor(src, output_image, CV_BGR2HSV);
	imshow("output window", output_image);

	imwrite("E:/repo/opencv/OpenCV_Continue_Learning/OpenCV图像处理视频教程/VideoLesson/VideoLesson/1_gray.jpg", output_image);

	waitKey(0);
	return 0;
}