//
//  SDMLeapVector.h
//  SDMLeapMotionSDK
//
//  Created by Sam Marshall on 12/1/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef SDMLeapMotionSDK_SDMLeapVector_h
#define SDMLeapMotionSDK_SDMLeapVector_h

#include "SDMLeapMath.h"

enum SDMLeapVectorAxis {
	SDMLeapVectorAxisZero = 0x0,
	SDMLeapVectorAxisX = 0x1,
	SDMLeapVectorAxisY = 0x2,
	SDMLeapVectorAxisZ = 0x3,
	SDMLeapVectorAxisLeft = 0x4,
	SDMLeapVectorAxisRight = 0x5,
	SDMLeapVectorAxisDown = 0x6,
	SDMLeapVectorAxisUp = 0x7,
	SDMLeapVectorAxisForward = 0x8,
	SDMLeapVectorAxisBackward = 0x9,
	SDMLeapVectorAxisCount
};

struct SDMLeapVector {
	float x;
	float y;
	float z;
};

typedef struct SDMLeapVector* SDMLeapVectorPtr;

SDMLeapVectorPtr SDMLeapVectorCreateFromComponents(float x, float y, float z);
SDMLeapVectorPtr SDMLeapVectorCreateFromVector(SDMLeapVectorPtr vector);

bool SDMLeapVectorEqualsVector(SDMLeapVectorPtr vector, SDMLeapVectorPtr equalsVector);
float SDMLeapVectorGetMagnitude(SDMLeapVectorPtr vector);
float SDMLeapVectorDistanceToVector(SDMLeapVectorPtr vector, SDMLeapVectorPtr distant);
float SDMLeapVectorAngleToVector(SDMLeapVectorPtr vector, SDMLeapVectorPtr distant);
float SDMLeapVectorPitch(SDMLeapVectorPtr vector);
float SDMLeapVectorRoll(SDMLeapVectorPtr vector);
float SDMLeapVectorYaw(SDMLeapVectorPtr vector);
float SDMLeapVectorDotVector(SDMLeapVectorPtr vector, SDMLeapVectorPtr dotVector);
SDMLeapVectorPtr SDMLeapVectorNegate(SDMLeapVectorPtr vector);
SDMLeapVectorPtr SDMLeapVectorAddVector(SDMLeapVectorPtr vector, SDMLeapVectorPtr addVector);
SDMLeapVectorPtr SDMLeapVectorMinusVector(SDMLeapVectorPtr vector, SDMLeapVectorPtr minusVector);
SDMLeapVectorPtr SDMLeapVectorMultiplyVector(SDMLeapVectorPtr vector, float mul);
SDMLeapVectorPtr SDMLeapVectorDivideVector(SDMLeapVectorPtr vector, float div);
SDMLeapVectorPtr SDMLeapVectorCrossVector(SDMLeapVectorPtr vector, SDMLeapVectorPtr crossVector);
SDMLeapVectorPtr SDMLeapVectorNormalize(SDMLeapVectorPtr vector);
SDMLeapVectorPtr SDMLeapVectorAxis(enum SDMLeapVectorAxis axis);

void SDMLeapVectorRelease(SDMLeapVectorPtr vector);

#endif