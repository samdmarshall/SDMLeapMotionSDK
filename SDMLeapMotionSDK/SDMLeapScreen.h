//
//  SDMLeapScreen.h
//  SDMLeapMotionSDK
//
//  Created by Sam Marshall on 12/1/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef SDMLeapMotionSDK_SDMLeapScreen_h
#define SDMLeapMotionSDK_SDMLeapScreen_h

#include "Leap.h"
#include "SDMLeapMath.h"
#include "SDMLeapVector.h"

struct SDMLeapScreen {
	Leap::Screen *interfaceScreen;
};

typedef struct SDMLeapScreen* SDMLeapScreenPtr;

SDMLeapScreenPtr SDMLeapScreenCreate(Leap::Screen *interfaceScreen);

int32_t SDMLeapScreenIdentifier(SDMLeapScreenPtr screen);
SDMLeapVectorPtr SDMLeapScreenIntersectPointableWithRatio(SDMLeapScreenPtr screen, SDMLeapPointablePtr pointable, bool normalize, float clampRatio);
SDMLeapVectorPtr SDMLeapScreenIntersectPositionInDirectionWithRatio(SDMLeapScreenPtr screen, SDMLeapVectorPtr position, SDMLeapVectorPtr direction, bool normalize, float clampRatio);
SDMLeapVectorPtr SDMLeapScreenProject(SDMLeapScreenPtr screen, SDMLeapVectorPtr position, bool normalize, float clampRatio);

SDMLeapVectorPtr SDMLeapScreenHorizontalAxis(SDMLeapScreenPtr screen);
SDMLeapVectorPtr SDMLeapScreenVerticalAxis(SDMLeapScreenPtr screen);
SDMLeapVectorPtr SDMLeapScreenBottomLeft(SDMLeapScreenPtr screen);
SDMLeapVectorPtr SDMLeapScreenNormal(SDMLeapScreenPtr screen);
float SDMLeapScreenWidth(SDMLeapScreenPtr screen);
float SDMLeapScreenHeight(SDMLeapScreenPtr screen);
float SDMLeapScreenDistanceToPoint(SDMLeapScreenPtr screen, SDMLeapVectorPtr point);

bool SDMLeapScreenIsValid(SDMLeapScreenPtr screen);
bool SDMLeapScreenEqualsScreen(SDMLeapScreenPtr screen, SDMLeapScreenPtr otherScreen);

SDMLeapScreenPtr SDMLeapScreenCreateInvalid();

void SDMLeapScreenRelease(SDMLeapScreenPtr screen);

#endif