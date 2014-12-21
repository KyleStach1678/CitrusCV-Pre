package org.citruscircuits.vision.effects;

import org.opencv.core.Mat;

public abstract class IteratePixelEffect extends ImageEffect {
	@Override
	public Mat process(Mat original) {
		for (int row = 0; row < original.rows(); row++ ) {
	        for(int col = 0; col < original.cols(); col++ ) {
	            original.put(row, col, processPixel(original.get(row, col), row, col, original.depth()));
	        }
	    }
		return original;
	}
	
	public abstract double[] processPixel(double[] in, int row, int col, int depth); // Called once for every pixel
}
