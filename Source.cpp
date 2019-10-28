#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <stdio.h>
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;
Vec3b Averager(Mat frame );

 int main()
{


	 //insert the movie name here 
	VideoCapture cap("Rick.and.Morty.S02E10.720p.x265.mkv");

	float frameNumbers = cap.get(CV_CAP_PROP_FRAME_COUNT);

	float L = frameNumbers / 1.5;

	cv:: Mat_<Vec3b> OutImage (frameNumbers, L);

	Mat img;

	int k = 0;

	Vec3b intensity3;

	while(1)
	{
		//cap.set(CV_CAP_PROP_POS_FRAMES, k);
		cap >> img;

		if (img.empty())
			break;

		intensity3 = Averager(img);
		for (int s = 0; s < L; ++s)
		{	
			OutImage.at<Vec3b>(k, s) = intensity3;
		}

		k++;

	}


	imwrite("colors.jpg", OutImage);
	
		cap.release();

		destroyAllWindows();

		return 0;
	}

Vec3b Averager(Mat img)

{

float BlueColor = 0;
float GreenColor = 0;
float RedColor = 0;
int IRows = img.rows;
int ICols = img.cols;
for (int i = 0; i < IRows; ++i)
{
for (int j = 0; j < ICols; ++j)
{
Vec3b intensity = img.at<Vec3b>(i, j);
int blue = intensity.val[0];
int green = intensity.val[1];
int red = intensity.val[2];
BlueColor = BlueColor + blue;
GreenColor = GreenColor + green;
RedColor = RedColor + red;
}
}

BlueColor = BlueColor / (3 * IRows*ICols);
GreenColor = GreenColor / (3 * IRows*ICols);
RedColor = RedColor / (3 * IRows*ICols);

Vec3b intensity2;

intensity2.val[0] = BlueColor;
intensity2.val[1] = GreenColor;
intensity2.val[2] = RedColor;

return intensity2;
}