/*
 * ObjectTracker.cpp
 *
 *  Created on: Dec 15, 2014
 *      Author: Kyle
 */

#include "ObjectTracker.h"
#include "Effect/BrightnessContrastEffect.h"
#include "Effect/ScanLineEffect.h"
#include "Effect/SelectColorEffect.h"
#include <windows.h>
#include <iostream>
#include <cstdio>
#include <ctime>

ObjectTracker::ObjectTracker() {

}

ObjectTracker::~ObjectTracker() {
	// TODO Auto-generated destructor stub
}

cv::Scalar min, max;
int y_min_slider = 0, y_max_slider = 0, u_min_slider = 0, u_max_slider = 0, v_min_slider = 0, v_max_slider = 0;

void on_trackbar( int, void* )
{
	min = cv::Scalar(y_min_slider, u_min_slider, v_min_slider);
	max = cv::Scalar(y_max_slider, u_max_slider, v_max_slider);
}

int main() {
	ScanLineEffect e;
	BrightnessContrastEffect e2(1, 0);
	cv::VideoCapture cap("http://10.16.78.11/mjpg/video.mjpg"); // open the default camera
	if(!cap.isOpened())  // check if we succeeded
		return -1;
	cv::Mat dilateErodeElement = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(1, 1));
	cv::namedWindow("edges", 0);
	cv::namedWindow("bars", 0);
	SelectColorEffect effect1;
	effect1.setTargetColor(YUV, cv::Scalar(0, 0, 0), cv::Scalar(255, 255, 255));
	min = cv::Scalar(0, 0, 0);
	max = cv::Scalar(255, 255, 255);
	cv::createTrackbar("Yv", "bars", &y_min_slider, 255, on_trackbar );
	cv::createTrackbar("Y^", "bars", &y_max_slider, 255, on_trackbar );
	cv::createTrackbar("Uv", "bars", &u_min_slider, 255, on_trackbar );
	cv::createTrackbar("U^", "bars", &u_max_slider, 255, on_trackbar );
	cv::createTrackbar("Vv", "bars", &v_min_slider, 255, on_trackbar );
	cv::createTrackbar("V^", "bars", &v_max_slider, 255, on_trackbar );
	for(;;)
	{
		cv::Mat edges;
		cv::Mat frame;
		cap >> frame; // get a new frame from camera
		//cv::cvtColor(frame, edges, CV_BGR2GRAY);
		edges = frame;
		effect1.setTargetColor(YUV, min, max);
		edges = effect1.process(edges);
		imshow("edges", edges);
		if(cv::waitKey(30) >= 0) break;
	}

	return 0;
}
