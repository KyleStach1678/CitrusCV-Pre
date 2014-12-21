package org.citruscircuits.vision.detectors;

import org.opencv.core.*;

public abstract class DetectedObject {
	public abstract Mat draw(Mat in, Scalar color);
	public abstract Rect findBoundingBox();
	public abstract boolean found();
}