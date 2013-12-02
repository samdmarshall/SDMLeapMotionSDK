//
//  SDMLeapPointable.h
//  SDMLeapMotionSDK
//
//  Created by Sam Marshall on 12/1/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef SDMLeapMotionSDK_SDMLeapPointable_h
#define SDMLeapMotionSDK_SDMLeapPointable_h

#include "Leap.h"
#include "SDMLeapMath.h"
#include "SDMLeapVector.h"
#include "SDMLeapFrame.h"
#include "SDMLeapHand.h"

struct SDMLeapPointable {
	Leap::Pointable *interfacePointable;
	SDMLeapFramePtr frame;
	SDMLeapHandPtr hand;
};

typedef struct SDMLeapPointable* SDMLeapPointablePtr;

struct SDMLeapPointableArray {
	SDMLeapPointablePtr pointable;
	uint32_t pointableCount;
};

typedef struct SDMLeapPointableArray* SDMLeapPointableArrayPtr;


SDMLeapPointableArrayPtr SDMLeapPointableArrayAdd(SDMLeapPointableArrayPtr array, SDMLeapPointablePtr pointable);

#endif