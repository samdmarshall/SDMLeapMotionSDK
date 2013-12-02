//
//  SDMLeapMotion.h
//  SDMLeapMotionSDK
//
//  Created by Sam Marshall on 12/1/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef SDMLeapMotionSDK_SDMLeapMotion_h
#define SDMLeapMotionSDK_SDMLeapMotion_h

#include "Leap.h"
#include "SDMLeapMath.h"
#include "SDMLeapTypes.h"

struct SDMLeapMotionController {
	SDMLeapListenerArrayPtr listenerArray;
	SDMLeapDeviceArrayPtr deviceArray;
};

typedef struct SDMLeapMotionController* SDMLeapMotionControllerPtr;

SDMLeapMotionControllerPtr SDMLeapMotionControllerCreate();

void SDMLeapMotionControllerAddListener(SDMLeapMotionControllerPtr controller, SDMLeapListenerPtr listener);
void SDMLeapMotionControllerAddDevice(SDMLeapMotionControllerPtr controller, SDMLeapDevicePtr device);

bool SDMLeapMotionControllerIsConnected(SDMLeapMotionControllerPtr controller);
bool SDMLeapMotionControllerHasFocus(SDMLeapMotionControllerPtr controller);

void SDMLeapMotionControllerRelease(SDMLeapMotionControllerPtr controller);

#endif