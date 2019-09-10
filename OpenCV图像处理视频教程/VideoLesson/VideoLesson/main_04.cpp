#if 0
#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/*
int main(int argc, char* argv[])
{
	Mat src, dst;
	src = imread("E:/repo/opencv/OpenCV_Continue_Learning/OpenCV???????????/VideoLesson/VideoLesson/1.jpg");
	if (!src.data)
	{
		printf("Could not load image...\n");
		return -1;
	}
	namedWindow("Input Image", CV_WINDOW_AUTOSIZE);
	imshow("Input Image", src);

	waitKey(0)
	return 0;
}
*/


int main(int argc, char *argv[])
{
	//???????????
	Mat m = (Mat_<int>(3, 2) << 11, 12, 33, 43, 51, 16);
	//???for??????m?��??????
	for (int r = 0; r < m.rows; r++)
	{
		for (int c = 0; c < m.cols; c++)
		{
			cout << m.at<int>(r, c) << ","; //??r?��?c?��??
		}
		cout << endl;
	}

	for (int r = 0; r < m.rows; r++)
	{
		//得到矩阵m的第r行行首的地址
		const int *ptr = m.ptr<int>(r);
		//打印第r行的所有值
		for (int c = 0; c < m.cols; c++)
		{
			cout << ptr[c] << ",";
		}
		cout << endl;
	}

	if (m.isContinuous())
	{
		//得到矩阵m的第一个值的地址
		int *ptr = m.ptr<int>(0);
		//利用操作符“[]”取值
		for (int n = 0; n < m.rows * m.cols; n++)
		{
			cout << ptr[n] << ",";
		}
		cout << endl;
	}

	Vec<int, 3> vi(21, 32, 14);
	cout << "向量的行数：" << vi.rows << endl;
	cout << "向量的列数：" << vi.cols << endl;
	cout << "访问第0个元素:" << vi[0] << endl;
	cout << "访问第1个元素:" << vi(1) << endl;

	Mat mm = (Mat_<Vec3f>(2, 2) << Vec3f(1, 11, 21), Vec3f(2, 12, 32), Vec3f(3, 13, 23), Vec3f(4, 24, 34));
	for (int r = 0; r < mm.rows; r++)
	{
		for (int c = 0; c < mm.cols; c++)
		{
			//打印第r行第c列的元素值
			cout << mm.at<Vec3f>(r, c) << ",";
		}
		cout << endl;
	}

	Mat src1 = (Mat_<uchar>(2, 3) << 23, 123, 90, 100, 250, 0);
	Mat src2 = (Mat_<uchar>(2, 3) << 125, 150, 60, 100, 10, 40);
	Mat dst = src1 + src2;
	cout << dst << endl;

	float value = 100.0;
	Mat dst1 = src1 + value;
	cout << dst1 << endl;

	Mat src3 = (Mat_<uchar>(2, 3) << 23, 123, 90, 100, 250, 0);
	Mat src4 = (Mat_<uchar>(2, 3) << 125, 150, 60, 100, 10, 40);
	Mat dst2;
	add(src3, src4, dst2, Mat(), CV_64FC1);
	cout << dst2 << endl;

	Vec3f v1 = Vec3f(1, 2, 3);
	Vec3f v2 = Vec3f(10, 1, 12);
	Vec3f v = v1 + v2;
	cout << v << endl;
	waitKey(0);
	system("pause");
	return 0;
}
#endif

#if 0
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
	//输入图像矩阵
	Mat img = imread(argv[1], IMREAD_GRAYSCALE);
	if (img.empty())
		return -1;
	//定义显示原图的窗口
	string winname = "原图";
	namedWindow(winname, WINDOW_AUTOSIZE);
	//显示图像
	imshow(winname, img);
	waitKey(0);
	return 0;
}
#endif

#include <opencv2\core.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2\highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat I;  //原图
Mat pI;	//投影变换后的图
Point2f IPoint, pIPoint;
int i = 0, j = 0;
Point2f	src[4];		//存储原坐标
Point2f dst[4];		//存储对应变换的坐标
//通过以下鼠标事件，在原图中取四个坐标
void mouse_I(int event, int x, int y, int flags, void *param)
{
	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN:
		IPoint = Point2f(x, y);		//记录坐标
		break;
	case CV_EVENT_LBUTTONUP:
		src[i] = IPoint;
		circle(I, src[i], 7, Scalar(0), 3);		//标记
		i += 1;
		break;
	default:
		break;
	}
}

//通过以下鼠标事件，在要输出的画布上取四个对应的坐标
void mouse_pI(int event, int x, int y, int flags, void *param)
{
	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN:
		pIPoint = Point2f(x, y);		//记录坐标
		break;
	case CV_EVENT_LBUTTONUP:
		dst[j] = pIPoint;
		circle(pI, dst[j], 7, Scalar(0), 3);		//标记
		j += 1;
		break;
	default:
		break;
	}
}

int main(int argc, char *argv[])
{
	//输入原图
	I = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
	if (!I.data)
		return -1;
	//输出图像
	pI = 255 * Mat::ones(I.size(), CV_8UC1);
	//在原图窗口上，定义鼠标事件
	namedWindow("I", 1);
	setMouseCallback("I", mouse_I, NULL);
	//在输出窗口上，定义鼠标事件
	namedWindow("pI", 1);
	setMouseCallback("pI", mouse_pI, NULL);
	imshow("I", I);
	imshow("pI", pI);
	while (!(i == 4 && j == 4))
	{
		imshow("I", I);
		imshow("pI", pI);
		if (waitKey(50) == 'q')
			break;
	}
	imshow("I", I);
	imshow("pI", pI);
	//移除鼠标事件
	setMouseCallback("I", NULL, NULL);
	setMouseCallback("pI", NULL, NULL);
	//计算投影变换矩阵
	Mat p = getPerspectiveTransform(src, dst);
	//投影变换
	Mat result;
	warpPerspective(I, result, p, pI.size());
	imshow("投影变换后的效果", result);
	waitKey(0);
	return 0;
}