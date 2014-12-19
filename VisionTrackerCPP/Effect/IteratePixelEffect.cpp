/*
 * IteratePixelEffect.cpp
 *
 *  Created on: Dec 15, 2014
 *      Author: Kyle
 */

#include "IteratePixelEffect.h"
#include <iostream>

IteratePixelEffect::IteratePixelEffect() {
	// TODO Auto-generated constructor stub

}

IteratePixelEffect::~IteratePixelEffect() {
	// TODO Auto-generated destructor stub
}

cv::Mat IteratePixelEffect::process(cv::Mat in) {
	cv::Mat altered = in.clone();
	for (int row = 0; row < in.rows; row++ ) {
		for(int col = 0; col < in.cols; col++ ) {
			altered.at<cv::Vec3b>(row, col) = processPixel(in.at<cv::Vec3b>(row, col), row, col);
		}
	}
	return altered;
}
