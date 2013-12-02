//
//  SDMLeapFrame.h
//  SDMLeapMotionSDK
//
//  Created by Sam Marshall on 12/1/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef SDMLeapMotionSDK_SDMLeapFrame_h
#define SDMLeapMotionSDK_SDMLeapFrame_h

#include "Leap.h"
#include "SDMLeapMath.h"
#include "SDMLeapHand.h"
#include "SDMLeapPointable.h"
#include "SDMLeapFinger.h"
#include "SDMLeapTool.h"
#include "SDMLeapGesture.h"

struct SDMLeapFrame {
	Leap::Frame *interfaceFrame;
	SDMLeapHandArrayPtr hand;
	SDMLeapPointableArrayPtr pointableArray;
	SDMLeapFingerArragyPtr fingerArray;
	SDMLeapToolArrayPtr toolArray;
	SDMLeapGestureArrayPtr gestureArray;
};

typedef struct SDMLeapFrame* SDMLeapFramePtr;

SDMLeapFramePtr SDMLeapFrameCreate(Leap::Frame *interfaceFrame);

int64_t SDMLeapFrameId(SDMLeapFramePtr frame);
int64_t SDMLeapFrameTimestamp(SDMLeapFramePtr frame);

SDMLeapVectorPtr SDMLeapFrameTranslation(SDMLeapFramePtr frame, SDMLeapFramePtr sinceFrame);
float SDMLeapFrameTranslationProbability(SDMLeapFramePtr frame, SDMLeapFramePtr sinceFrame);
float SDMLeapFrameRotationAngle(SDMLeapFramePtr frame, SDMLeapFramePtr sinceFrame);
SDMLeapVectorPtr SDMLeapFrameRotationAxis(SDMLeapFramePtr frame, SDMLeapFramePtr sinceFrame);
float SDMLeapFrameRotationAngleAxis(SDMLeapFramePtr frame, SDMLeapFramePtr sinceFrame, SDMLeapVectorPtr axis);
SDMLeapMatrixPtr SDMLeapFrameRotationMatrix(SDMLeapFramePtr frame, SDMLeapFramePtr sinceFrame);
float SDMLeapFrameRotationProbability(SDMLeapFramePtr frame, SDMLeapFramePtr sinceFrame);
float SDMLeapFrameScaleFactor(SDMLeapFramePtr frame, SDMLeapFramePtr sinceFrame);
float SDMLeapFrameScaleProbability(SDMLeapFramePtr frame, SDMLeapFramePtr sinceFrame);
SDMLeapInteractionBoxPtr SDMLeapFrameInteractionBox(SDMLeapFramePtr frame);
float SDMLeapFrameCurrentFPS(SDMLeapFramePtr frame);
bool SDMLeapFrameIsValid(SDMLeapFramePtr frame);

SDMLeapFramePtr SDMLeapFrameCreateInvalid();

void SDMLeapFrameRelease(SDMLeapFramePtr frame);

#endif