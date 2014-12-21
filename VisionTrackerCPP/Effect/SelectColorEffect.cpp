/*
 * SelectColorEffect.cpp
 *
 *  Created on: Dec 21, 2014
 *      Author: Citrus Circuits
 */

#include "SelectColorEffect.h"

SelectColorEffect::SelectColorEffect() {
	dilateErodeElement = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5));
}

SelectColorEffect::~SelectColorEffect() {
	// TODO Auto-generated destructor stub
}

cv::Mat SelectColorEffect::process(cv::Mat in)
{
	switch(type) {
	case RGB:
		cv::inRange(in, targetL, targetH, in);
		break;
	case YUV:
		cv::cvtColor(in, in, cv::COLOR_BGR2YUV);
		cv::inRange(in, targetL, targetH, in);
		break;
	case HSV:
		cv::cvtColor(in, in, cv::COLOR_BGR2HSV);
		cv::inRange(in, targetL, targetH, in);
		break;
	default:
		break;
	}
	cv::blur(in, in, cv::Size(20, 20));
	cv::erode(in, in, dilateErodeElement);
	cv::erode(in, in, dilateErodeElement);
	cv::dilate(in, in, dilateErodeElement);
	cv::dilate(in, in, dilateErodeElement);
	cv::threshold(in, in, 32, 255, in.type());
	return in;
}

void SelectColorEffect::setTargetColor(int typen, cv::Scalar low, cv::Scalar high)
{
	targetL = low;
	targetH = high;
	type = typen;
}
