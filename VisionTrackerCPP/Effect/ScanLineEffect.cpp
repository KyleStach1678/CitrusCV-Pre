/*
 * ScanLineEffect.cpp
 *
 *  Created on: Dec 15, 2014
 *      Author: Kyle
 */

#include "ScanLineEffect.h"

ScanLineEffect::ScanLineEffect() {
	// TODO Auto-generated constructor stub

}

ScanLineEffect::~ScanLineEffect() {
	// TODO Auto-generated destructor stub
}

cv::Vec3b ScanLineEffect::processPixel(cv::Vec3b pixel, int row, int col) {
	if (row % 3 == 0) {
		return cv::Vec3b(0, 0, 0);
	}
	return pixel;
}
