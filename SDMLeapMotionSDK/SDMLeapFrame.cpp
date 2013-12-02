//
//  SDMLeapFrame.c
//  SDMLeapMotionSDK
//
//  Created by Sam Marshall on 12/1/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef SDMLeapMotionSDK_SDMLeapFrame_c
#define SDMLeapMotionSDK_SDMLeapFrame_c

#include "SDMLeapFrame.h"

// do we actually need this? this SDK is so bad!
Leap::Hand SDMLeapFrameGetHandPtr(Pointer object, SDMLeapHandArrayPtr handArray) {
	Leap::Hand &leapHand = Leap::Hand::invalid();
	if (object->hand()->isValid()) {
		for (uint32_t i = 0x0; i < handArray->handCount; i++) {
			if (object->hand()->id() == handArray->hand[i].interfaceHand->id()) {
				leapHand = handArray->hand[i].interfaceHand;
				break;
			}
		}
	}
	return leapHand;
}

SDMLeapFramePtr SDMLeapFrameCreate(Leap::Frame *interfaceFrame) {
	SDMLeapFramePtr frame = (SDMLeapFramePtr)calloc(0x1, sizeof(struct SDMLeapFrame));
	if (frame) {
		frame->interfaceFrame = new Leap::Frame(*(const Leap::Frame *)interfaceFrame);
		
		frame->handArray = (SDMLeapHandArrayPtr)calloc(0x1, sizeof(struct SDMLeapHandArray));
		for (uint32_t i = 0x0; i < frame->interfaceFrame->hands().count(); i++) {
			SDMLeapHandPtr hand = SDMLeapHandCreate(frame->interfaceFrame->hands()[i]);
			frame->handArray = SDMLeapHandArrayAdd(frame->handArray, hand);
		}
		
		frame->pointableArray = (SDMLeapPointableArrayPtr)calloc(0x1, sizeof(struct SDMLeapPointableArray));
		// dispatch apply async this.
		for (uint32_t i = 0x0; i < frame->interfaceFrame->pointables().count(); i++) {
			Leap::Pointable &leapPointable = frame->interfaceFrame->pointables()[i];
			Leap::Hand &leapHand = SDMLeapFrameGetHandPtr(leapPointable, frame->handArray);
			SDMLeapPointablePtr pointable = SDMLeapPointableCreate(leapPointable, frame, leapHand);
			frame->pointableArray = SDMLeapPointableArrayAdd(frame->pointableArray, pointable);
		}
		
		frame->fingerArray = (SDMLeapFingerArrayPtr)calloc(0x1, sizeof(struct SDMLeapFingerArray));
		// dispatch apply async this.
		for (uint32_t i = 0x0; i < frame->interfaceFrame->fingers().count(); i++) {
			Leap::Finger &leapFinger = frame->interfaceFrame->fingers()[i];
			Leap::Hand &leapHand = SDMLeapFrameGetHandPtr(leapFinger, frame->handArray);
			SDMLeapFingerPtr finger = SDMLeapFingerCreate(leapFinger, frame, leapHand);
			frame->fingerArray = SDMLeapFingerArrayAdd(frame->fingerArray, finger);
		}
		
		frame->toolArray = (SDMLeapToolArrayPtr)calloc(0x1, sizeof(struct SDMLeapToolArray));
		// dispatch apply async this.
		for (uint32_t i = 0x0; i < frame->interfaceFrame->tools().count(); i++) {
			Leap::Tool &leapTool = frame->interfaceFrame->tools()[i];
			Leap::Hand &leapHand = SDMLeapFrameGetHandPtr(leapTool, frame->handArray);
			SDMLeapToolPtr tool = SDMLeapToolCreate(leapTool, frame, leapHand);
			frame->toolArray = SDMLeapPointableArrayAdd(frame->toolArray, tool);
		}
	}
	return frame;
}

int64_t SDMLeapFrameId(SDMLeapFramePtr frame) {
	return frame->interfaceFrame->id();
}

int64_t SDMLeapFrameTimestamp(SDMLeapFramePtr frame) {
	return frame->interfaceFrame->timestamp();
}

SDMLeapVectorPtr SDMLeapFrameTranslation(SDMLeapFramePtr frame, SDMLeapFramePtr sinceFrame) {
	Leap::Vector v = frame->interfaceFrame->translation(*(sinceFrame->interfaceFrame));
	return SDMLeapVectorCreateFromComponents(v->x, v->y, v->z);
}

float SDMLeapFrameTranslationProbability(SDMLeapFramePtr frame, SDMLeapFramePtr sinceFrame) {
	return frame->interfaceFrame->translationProbability(*(sinceFrame->interfaceFrame));
}

float SDMLeapFrameRotationAngle(SDMLeapFramePtr frame, SDMLeapFramePtr sinceFrame) {
	return frame->interfaceFrame->rotationAxis(*(sinceFrame->interfaceFrame));
}

SDMLeapVectorPtr SDMLeapFrameRotationAxis(SDMLeapFramePtr frame, SDMLeapFramePtr sinceFrame) {
	Leap::Vector v = frame->interfaceFrame->rotationAxis(*(sinceFrame->interfaceFrame));
	return SDMLeapVectorCreateFromComponents(v->x, v->y, v->z);
}

float SDMLeapFrameRotationAngleAxis(SDMLeapFramePtr frame, SDMLeapFramePtr sinceFrame, SDMLeapVectorPtr axis) {
	Leap::Vector v(axis->x, axis->y, axis->z);
	return frame->interfaceFrame->rotationAngle(*(sinceFrame->interfaceFrame), v);
}

SDMLeapMatrixPtr SDMLeapFrameRotationMatrix(SDMLeapFramePtr frame, SDMLeapFramePtr sinceFrame) {
	Leap::Matrix m = frame->interfaceFrame->rotationMatrix(*(sinceFrame->interfaceFrame));
	SDMLeapVectorPtr xBasis = SDMLeapVectorCreateFromComponents(m->xBasis->x, m->xBasis->y, m->xBasis->z);
	SDMLeapVectorPtr yBasis = SDMLeapVectorCreateFromComponents(m->yBasis->x, m->yBasis->y, m->yBasis->z);
	SDMLeapVectorPtr zBasis = SDMLeapVectorCreateFromComponents(m->zBasis->x, m->zBasis->y, m->zBasis->z);
	SDMLeapVectorPtr origin = SDMLeapVectorCreateFromComponents(m->origin->x, m->origin->y, m->origin->z);
	SDMLeapMatrixPtr matrix = SDMLeapMatrixCreateFromComponents(xBasis, yBasis, zBasis, origin);
	SDMLeapVectorRelease(xBasis);
	SDMLeapVectorRelease(yBasis);
	SDMLeapVectorRelease(zBasis);
	SDMLeapVectorRelease(origin);
	return matrix;
}

float SDMLeapFrameRotationProbability(SDMLeapFramePtr frame, SDMLeapFramePtr sinceFrame) {
	return frame->interfaceFrame->rotationProbability(*(sinceFrame->interfaceFrame));
}

float SDMLeapFrameScaleFactor(SDMLeapFramePtr frame, SDMLeapFramePtr sinceFrame) {
	return frame->interfaceFrame->scaleFactor(*(sinceFrame->interfaceFrame));
}

float SDMLeapFrameScaleProbability(SDMLeapFramePtr frame, SDMLeapFramePtr sinceFrame) {
	return frame->interfaceFrame->scaleProbability(*(sinceFrame->interfaceFrame));
}

SDMLeapInteractionBoxPtr SDMLeapFrameInteractionBox(SDMLeapFramePtr frame) {
	Leap::InteractionBox leapInteractionBox = frame->interfaceFrame->interactionBox();
	return SDMLeapInteractionBoxCreate(leapInteractionBox);
}

float SDMLeapFrameCurrentFPS(SDMLeapFramePtr frame) {
	return frame->interfaceFrame->currentFramesPerSecond();
}

bool SDMLeapFrameIsValid(SDMLeapFramePtr frame) {
	return (bool)(frame->interfaceFrame->isValid() & 0xf);
}

SDMLeapFramePtr SDMLeapFrameCreateInvalid() {
	static const Leap::Frame &invalid_frame = Leap::Frame::invalid();
	return SDMLeapFrameCreate(&invalid_frame);
}

void SDMLeapFrameRelease(SDMLeapFramePtr frame) {
	if (frame->interfaceFrame) {
		delete frame->interfaceFrame;
	}
	
	if (frame->handArray) {
		for (uint32_t i = 0x0; i < frame->handArray->handCount; i++) {
			SDMLeapHandRelease(frame->handArray->hand[i]);
		}
		free(frame->handArray);
	}
	
	if (frame->pointableArray) {
		for (uint32_t i = 0x0; i < frame->pointableArray->pointableCount; i++) {
			SDMLeapHandRelease(frame->pointableArray->pointable[i]);
		}
		free(frame->pointableArray);
	}
	
	if (frame->fingerArray) {
		for (uint32_t i = 0x0; i < frame->fingerArray->fingerCount; i++) {
			SDMLeapHandRelease(frame->fingerArray->finger[i]);
		}
		free(frame->fingerArray);
	}
	
	if (frame->toolArray) {
		for (uint32_t i = 0x0; i < frame->toolArray->toolCount; i++) {
			SDMLeapHandRelease(frame->toolArray->tool[i]);
		}
		free(frame->toolArray);
	}
}

#endif