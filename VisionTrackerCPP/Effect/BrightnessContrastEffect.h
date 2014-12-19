/*
 * BrightnessContrastEffect.h
 *
 *  Created on: Dec 15, 2014
 *      Author: Kyle
 */

#ifndef EFFECT_BRIGHTNESSCONTRASTEFFECT_H_
#define EFFECT_BRIGHTNESSCONTRASTEFFECT_H_

#include "IteratePixelEffect.h"

class BrightnessContrastEffect : public IteratePixelEffect {
	float contrast;
	int brightness;
public:
	cv::Vec3b processPixel(cv::Vec3b pixel, int row, int col);
	BrightnessContrastEffect(float alpha = 1, int beta = 0);
	virtual ~BrightnessContrastEffect();
};

#endif /* EFFECT_BRIGHTNESSCONTRASTEFFECT_H_ */
