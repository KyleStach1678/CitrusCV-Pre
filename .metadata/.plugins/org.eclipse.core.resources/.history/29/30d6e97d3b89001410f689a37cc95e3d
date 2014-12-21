package org.citruscircuits.vision.effects;

import java.util.Vector;

import org.opencv.core.Core;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.core.Scalar;
import org.opencv.core.Size;
import org.opencv.imgproc.Imgproc;

public class SelectColorEffect extends ImageEffect {
	public static Mat dilateErodeElement = Imgproc.getStructuringElement(Imgproc.MORPH_ELLIPSE, new Size(5, 5));
	public Scalar targetL, targetH;
	public float variance;
	public boolean acc;
	ColorType type;
	
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
	
	public enum ColorType {
		RGB, LAB, YUV, HSV
	}
	
	public void setTargetColor(ColorType type, Scalar low, Scalar high) {
		targetL = low;
		targetH = high;
		this.type = type;
	}

	@Override
	public Mat process(Mat original) {
		// TODO Use LAB colorspace
		//Imgproc.cvtColor(original, original, Imgproc.COLOR_BGR2Lab);
		//		Core.inRange(original, new Scalar(HSV[0][0], HSV[1][0], HSV[2][0]), new Scalar(HSV[0][1], HSV[1][1], HSV[2][1]), originala);
		switch(type) {
		case RGB:
			Core.inRange(original, targetL, targetH, original);
			break;
		case LAB:
			Imgproc.cvtColor(original, original, Imgproc.COLOR_BGR2Lab);
			original = rangeThresh(original, targetL, variance);
			break;
		case YUV:
			Imgproc.cvtColor(original, original, Imgproc.COLOR_BGR2YUV);
			Core.inRange(original, targetL, targetH, original);
			break;
		case HSV:
			Imgproc.cvtColor(original, original, Imgproc.COLOR_BGR2HSV);
			Core.inRange(original, targetL, targetH, original);
			break;
		default:
			break;
		}
		Imgproc.blur(original, original, new Size(20, 20));
		Imgproc.erode(original, original, dilateErodeElement);
		Imgproc.erode(original, original, dilateErodeElement);
		Imgproc.dilate(original, original, dilateErodeElement);
		Imgproc.dilate(original, original, dilateErodeElement);
		Imgproc.threshold(original, original, 32, 255, original.type());
		return original;
	}

	private Mat rangeThresh(Mat original, Scalar target, float allowedVariance) {
		float totVar = 0;
		Mat ret = Mat.zeros(original.size(), CvType.CV_8UC1);
		for (int row = 0; row < original.rows(); row++) {
			for (int col = 0; col < original.cols(); col++) {
				for (int i = 0; i < 3; i++) {
					totVar += Math.pow(target.val[i] - original.get(row, col)[i], 2);
				}
				if (Math.sqrt(totVar) <= allowedVariance) {
					ret.put(row, col, 255);
				}
				totVar = 0;
			}
		}
		return ret;
	}

}
