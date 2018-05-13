#include <opencv2/core/core.hpp>
#include <opencv2\highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
/* 2.2.2 */
	//����2��3�еľ���
	Mat m = Mat(2, 3, CV_32FC(1));
	Mat n = Mat(Size(3, 2), CV_32FC(1));
	Mat j;
	j.create(2, 3, CV_32FC1);

	//����2��3��ȫ1����
	Mat o = Mat::ones(2, 3, CV_32FC1);

	//����2��3��ȫ0��float���͵�ͨ������
	Mat p = Mat::zeros(Size(3, 2), CV_32FC1);

	//��ʼ��2��3��int���͵ĵ�ͨ������
	//���ַ������ڿ��ٴ������󣬲���һЩ������ʹ�÷���
	Mat q = (Mat_<int>(2, 3) << 1, 2, 3, 4, 5, 6);

/* 2.2.3 */
	//��������
	Mat r = (Mat_<int>(3, 2) << 11, 12, 33, 43, 51, 16);
	//���������
	cout << "������" << r.rows << endl;
	//���������
	cout << "������" << r.cols << endl;
	return 0;
}