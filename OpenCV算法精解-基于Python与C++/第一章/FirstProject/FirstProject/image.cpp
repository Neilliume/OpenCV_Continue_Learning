#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>

using namespace cv;
int main(int argc, char *argv[])
{
	//����ͼ��
	Mat img = imread(argv[1], IMREAD_ANYCOLOR);
	if (!img.data)
		return -1;
	//��ʾͼ��
	imshow("ԭͼ", img);
	waitKey(0);
	return 0;
}