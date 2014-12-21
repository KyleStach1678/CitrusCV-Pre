package org.citruscircuits.vision.effects;

import java.util.ArrayList;

import org.opencv.core.Mat;

public class EffectChain extends ImageEffect {
	private ArrayList<ImageEffect> effectChain;
	
	public EffectChain() {
		effectChain = new ArrayList<ImageEffect>();
	}
	
	@Override
	public Mat process(Mat original) {
		Mat retval = original.clone();
		for (ImageEffect effect : effectChain) {
			retval = effect.process(retval);
		}
		return retval;
	}

	public void addAfter(ImageEffect newEff, ImageEffect after) {
		int i = 1;
		for (ImageEffect e : effectChain)
		{
			if (e.equals(after)) {
				effectChain.add(i, newEff);
			}
			i++;
		}
	}
	
	public void addBefore(ImageEffect newEff, ImageEffect after) {
		int i = 0;
		for (ImageEffect e : effectChain)
		{
			if (e.equals(after)) {
				effectChain.add(i, newEff);
			}
			i++;
		}
	}
	
	public void addToEnd(ImageEffect newEff) {
		effectChain.add(newEff);
	}
	
	public void addToFront(ImageEffect newEff) {
		effectChain.add(effectChain.size(), newEff);
	}
	
}
