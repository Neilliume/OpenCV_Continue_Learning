#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	Mat src, dst;
	src = imread("E:/repo/opencv/OpenCV_Continue_Learning/OpenCV图像处理视频教程/VideoLesson/VideoLesson/1.jpg");
	if (!src.data)
	{
		printf("Could not load image...\n");
		return -1;
	}
	namedWindow("Input Image", CV_WINDOW_AUTOSIZE);
	imshow("Input Image", src);
/*
	int cols = (src.cols - 1) * src.channels();
	int offsetx = src.channels();
	int rows = src.rows;
	dst = Mat::zeros(src.size(), src.type());
	for (int row = 1; row < rows - 1; row++)
	{
		const uchar* current = src.ptr<uchar>(row);
		const uchar* previous = src.ptr<uchar>(row - 1);
		const uchar* next = src.ptr<uchar>(row + 1);
		uchar* output = dst.ptr<uchar>(row);
		for (int col = offsetx; col < cols; col++)
		{
			output[col] = saturate_cast<uchar>(5 * current[col] - (current[col - offsetx] + current[col + offsetx] + previous[col] + next[col]));
		}
	}
*/

	double start = getTickCount();
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(src, dst, src.depth(), kernel);
	double end = (getTickCount() - start) / getTickFrequency();
	printf("Time Consume:%.2fs\n", end);
	namedWindow("contrast image demo", CV_WINDOW_AUTOSIZE);
	imshow("contrast image demo", dst);

	waitKey(0);
	return 0;
}