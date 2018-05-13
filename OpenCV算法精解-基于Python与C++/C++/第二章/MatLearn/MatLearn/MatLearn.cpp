#include <opencv2/core/core.hpp>
#include <opencv2\highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
/* 2.2.2 */
	//构造2行3列的矩阵
	Mat m = Mat(2, 3, CV_32FC(1));
	Mat n = Mat(Size(3, 2), CV_32FC(1));
	Mat j;
	j.create(2, 3, CV_32FC1);

	//构造2行3列全1矩阵
	Mat o = Mat::ones(2, 3, CV_32FC1);

	//构造2行3列全0的float类型单通道矩阵
	Mat p = Mat::zeros(Size(3, 2), CV_32FC1);

	//初始化2行3列int类型的单通道矩阵
	//这种方法便于快速创建矩阵，测试一些函数的使用方法
	Mat q = (Mat_<int>(2, 3) << 1, 2, 3, 4, 5, 6);

/* 2.2.3 */
	//构建矩阵
	Mat r = (Mat_<int>(3, 2) << 11, 12, 33, 43, 51, 16);
	//矩阵的行数
	cout << "行数：" << r.rows << endl;
	//矩阵的列数
	cout << "列数：" << r.cols << endl;
	return 0;
}