package org.citruscircuits.vision.detectors;

import java.util.ArrayList;

import org.opencv.core.*;
import org.opencv.imgproc.Imgproc;

public class DetectedContour extends DetectedObject {
	ArrayList<MatOfPoint> detected;
	
	public DetectedContour() {
		detected = new ArrayList<MatOfPoint>();
	}
	
	@Override
	public Mat draw(Mat in, Scalar color) {
		Imgproc.drawContours(in, detected, 0, color, 3);
		return in;
	}

	@Override
	public Rect findBoundingBox() {
		return Imgproc.boundingRect(detected.get(0));
	}

	@Override
	public boolean found() {
		return detected.size() > 0;
	}
}
