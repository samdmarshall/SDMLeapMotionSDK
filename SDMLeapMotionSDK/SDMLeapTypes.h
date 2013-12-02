//
//  SDMLeapTypes.h
//  SDMLeapMotionSDK
//
//  Created by Sam Marshall on 12/1/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef SDMLeapMotionSDK_SDMLeapTypes_h
#define SDMLeapMotionSDK_SDMLeapTypes_h

typedef uintptr_t* Pointer;
typedef uintptr_t* (*FunctionPointer)();

struct SDMLeapArray {
	Pointer array;
	uint32_t arrayCount;
};

typedef struct SDMLeapArray* SDMLeapArrayPtr;

#include "SDMLeapListener.h"
#include "SDMLeapDevice.h"
#include "SDMLeapScreen.h"
#include "SDMLeapFrame.h"

#include "SDMLeapVector.h"
#include "SDMLeapMatrix.h"
#include "SDMLeapPointable.h"
#include "SDMLeapHand.h"
#include "SDMLeapFinger.h"
#include "SDMLeapTool.h"
#include "SDMLeapGesture.h"
#include "SDMLeapInteractionBox.h"

#endif