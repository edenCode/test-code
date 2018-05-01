#include <opencv2\opencv.hpp>
#include <random>

using namespace cv;
using namespace std;

// ��ӽ�������
void addSaltNoise(Mat &m, int num)
{
	// �����������
	std::random_device rd; //����
	std::mt19937 gen(rd()); // ���������

	auto cols = m.cols * m.channels();

	for (int i = 0; i < num; i++)
	{
		auto row = static_cast<int>(gen() % m.rows);
		auto col = static_cast<int>(gen() % cols);

		auto p = m.ptr<uchar>(row);
		p[col++] = 255;
		p[col++] = 255;
		p[col] = 255;
	}
}

// ���Gussia����
// ʹ��ָ�����
void addGaussianNoise(Mat &m, int mu, int sigma)
{
	// ������˹�ֲ������������
	std::random_device rd;
	std::mt19937 gen(rd());

	std::normal_distribution<> d(mu, sigma);

	auto rows = m.rows; // ����
	auto cols = m.cols * m.channels(); // ����

	for (int i = 0; i < rows; i++)
	{
		auto p = m.ptr<uchar>(i); // ȡ������ָ��
		for (int j = 0; j < cols; j++)
		{
			auto tmp = p[j] + d(gen);
			tmp = tmp > 255 ? 255 : tmp;
			tmp = tmp < 0 ? 0 : tmp;
			p[j] = tmp;
		}
	}
}

int main()
{
	Mat I = imread("D:\\Lena.jpg");

	if (I.empty())
	{
		cout << "error Load image \n";
		waitKeyEx(0);
	}
	
	namedWindow("src");

	imshow("src",I);

	Mat I_a = I.clone();

	addSaltNoise(I_a,I.rows);
	namedWindow("salt");
	imshow("salt",I_a);

	Mat I_b = I.clone();

	addGaussianNoise(I_b,0,1);
	namedWindow("GaussianNoise");
	imshow("GaussianNoise", I_b);

	waitKey(0);
}
