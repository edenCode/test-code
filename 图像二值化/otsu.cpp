#include <opencv/cv.h>
#include <opencv2/opencv.hpp>
#include <iostream>
/*
	���ǰ�ͼ��ĻҶ�����,��ͼ��ֳɱ�����Ŀ��2���֡�������Ŀ��֮�����䷽��Խ��,
	˵������ͼ���2���ֵĲ��Խ��,������Ŀ����Ϊ�����򲿷ֱ������ΪĿ�궼�ᵼ��2���ֲ���С��
	���,ʹ��䷽�����ķָ���ζ�Ŵ�ָ�����С��

	����ͼ��I(x,y),ǰ��(��Ŀ��)�ͱ����ķָ���ֵ����T,����ǰ�������ص���ռ����ͼ��ı�
	����Ϊ��0,��ƽ���ҶȦ�0;�������ص���ռ����ͼ��ı���Ϊ��1,��ƽ���Ҷ�Ϊ��1��ͼ�����ƽ��
	�Ҷȼ�Ϊ��,��䷽���Ϊg��
	����ͼ��ı����ϰ�,����ͼ��Ĵ�СΪM��N,
	ͼ�������صĻҶ�ֵС����ֵT�����ظ�������N0,���ػҶȴ�����ֵT�����ظ�������N1,����:
	��������������0=N0/ M��N (1)
		  ��������1=N1/ M��N (2)
				N0+N1=M��N (3)
				��0+��1=1 (4)
				��=��0*��0+��1*��1 (5)
				g=��0(��0-��)^2+��1(��1-��)^2 (6)
				��ʽ(5)����ʽ(6),�õ��ȼ۹�ʽ: g=��0��1(��0-��1)^2 (7)
				���ñ����ķ����õ�ʹ��䷽��������ֵT,��Ϊ����
*/
double otus(IplImage * src)
{
	// src Ϊ �Ҷ�ͼƬ
	int width = src->width;
	int height = src->height;

	int hist[256];

	/*
		�Ҷ�ͼƬ�ĻҶ�ֵ�� 0��256
	*/
	for (int i = 0; i < height; i++)
	{
		unsigned char * p = (unsigned char *)src->imageData + src->widthStep * i;
		for (int j = 0; j <= 256; j++)
		{
			hist[*p++]++; // ͳ��ÿ���Ҷȼ���ĸ�����
		}
	}

	float average;// ����ͼƬ�ĻҶ�ƽ��ֵ��
	float u = 0;
	for (int i = 0; i <= 256; i++)
	{
		u += hist[i]*i;
	}

	average = u / width * height;

	int size = width * height;
	float T;
	float w0 = 0;
	float w1;
	float average_f = 0;
	float average_b = 0;
	float maxvalu = 0, value = 0;
	for (int i = 0; i <= 256; i++)
	{
		w0 += hist[i];// i Ϊ
		average_f += i*hist[i];
	
		float t = average_f / w0 - average;

		value = (w0/size )*(1 - w0/size)*t*t;

		if (value > maxvalu)
		{
			maxvalu = value;
			T = i;
		}
	}
	return T;
}
int main()
{
	
	cv::Mat mat,gray_img;
	mat = cv::imread("D:/Alistar.jpg",cv::IMREAD_COLOR);

	cv::imshow("image",mat);
	cv::cvtColor(mat,gray_img,cv::COLOR_BGR2GRAY);

	cv::imshow("gray",gray_img);
	IplImage  img(gray_img);
	int t = otus(&img);
	std::cout << "��ֵ �� " << t << std::endl;
	cv::Mat img2;
	cv::Mat img1(gray_img);
	cv::threshold(img1,img2,t,0,cv::THRESH_BINARY| cv::THRESH_OTSU);

	cv::imshow("img2",img2);
	cv::waitKey(-1);
	
}