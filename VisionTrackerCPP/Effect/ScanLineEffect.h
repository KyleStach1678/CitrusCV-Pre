/*
 * ScanLineEffect.h
 *
 *  Created on: Dec 15, 2014
 *      Author: Kyle
 */

#ifndef EFFECT_SCANLINEEFFECT_H_
#define EFFECT_SCANLINEEFFECT_H_

#include "IteratePixelEffect.h"

class ScanLineEffect: public IteratePixelEffect {
public:
	cv::Vec3b processPixel(cv::Vec3b pixel, int row, int col);
	ScanLineEffect();
	virtual ~ScanLineEffect();
};

#endif /* EFFECT_SCANLINEEFFECT_H_ */
