package org.citruscircuits.vision.detectors;
import org.opencv.core.*;

public abstract class ObjectDetector {
	public abstract DetectedObject findTarget(Mat source);
}
