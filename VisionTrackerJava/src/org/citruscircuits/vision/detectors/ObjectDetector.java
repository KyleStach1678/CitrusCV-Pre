package org.citruscircuits.vision.detectors;
import org.opencv.core.*;

public abstract class ObjectDetector {
	public abstract Rect findTarget(Mat source);
}
