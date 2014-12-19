package org.citruscircuits.vision.effects;

import org.opencv.core.Core;
import org.opencv.core.Mat;
import org.opencv.core.Scalar;
import org.opencv.core.Size;
import org.opencv.imgproc.Imgproc;

public class SelectColorEffect extends ImageEffect {
	float[][] HSV = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
	public static Mat dilateErodeElement = Imgproc.getStructuringElement(Imgproc.MORPH_ELLIPSE, new Size(5, 5));
	public static Scalar lrange1, lrange2, hrange1, hrange2;
	public static Mat addMats(Mat a, Mat b) {
		if (!(a.rows() == b.rows() && a.cols() == b.cols()))
			return null;
		Mat c = Mat.zeros(a.rows(), a.cols(), a.type());
		for (int row = 0; row < a.rows(); row++ ) {
	        for(int col = 0; col < a.cols(); col++ ) {
	        	double[] pix = a.get(row, col);
	        	for (int i = 0; i < a.channels(); i++) {
		        	pix[i] += b.get(row, col)[i];
	        	}
	            c.put(row, col, pix);
	        }
	    }
		return c;
	}
	
	public SelectColorEffect(float lowH1, float highH1, float lowS, float highS, float lowV, float highV, float lowH2, float highH2) {
		HSV[0][0] = lowH1;
		HSV[0][1] = highH1;
		HSV[1][0] = lowS;
		HSV[1][1] = highS;
		HSV[2][0] = lowV;
		HSV[2][1] = highV;
		HSV[3][0] = lowH2;
		HSV[3][1] = highH2;
	}
	public SelectColorEffect(float lowH1, float highH1, float lowS, float highS, float lowV, float highV) {
		this(lowH1, highH1, lowS, highS, lowV, highV, 0, 0);
	}
	
	@Override
	public Mat process(Mat original) {
		// TODO Use LAB colorspace
		Imgproc.cvtColor(original, original, Imgproc.COLOR_BGR2HSV);
		Mat originala = original.clone();
		// Core.inRange(original, new Scalar(0, 127, 127), new Scalar(40, 255, 255), originala); hard coded values
		Core.inRange(original, new Scalar(HSV[0][0], HSV[1][0], HSV[2][0]), new Scalar(HSV[0][1], HSV[1][1], HSV[2][1]), originala);
		// Core.inRange(original, new Scalar(160, 127, 127), new Scalar(179, 255, 255), originalb);
		if(HSV[3][0] - HSV[3][1] != 0)
		{
			Mat originalb = original.clone();
			Core.inRange(original, new Scalar(HSV[3][0], HSV[1][0], HSV[2][0]), new Scalar(HSV[3][1], HSV[1][1], HSV[2][1]), originalb);
			original = addMats(originala, originalb);
			originalb = null;
		} else { original = originala; }
		Imgproc.blur(original, original, new Size(20, 20));
		Imgproc.erode(original, original, dilateErodeElement);
		Imgproc.erode(original, original, dilateErodeElement);
		Imgproc.dilate(original, original, dilateErodeElement);
		Imgproc.dilate(original, original, dilateErodeElement);
		Imgproc.threshold(original, original, 32, 255, original.type());
		originala = null;
		return original;
	}

}