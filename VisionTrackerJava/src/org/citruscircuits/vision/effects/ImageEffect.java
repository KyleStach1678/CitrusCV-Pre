package org.citruscircuits.vision.effects;

import org.opencv.core.Mat;

public abstract class ImageEffect {
	public abstract Mat process(Mat original); // Alters Original
}
