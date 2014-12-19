package org.citruscircuits.vision.effects;

import org.opencv.core.Mat;
import org.opencv.core.Size;
import org.opencv.imgproc.Imgproc;

public class EdgeDetectEffect extends ImageEffect {

	@Override
	public Mat process(Mat original) {
		Mat retval = original.clone();
		Imgproc.blur(retval, retval, new Size(2, 2));
		Imgproc.Canny(retval, retval, 100, 200);
		return retval;
	}

}
