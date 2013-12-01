//
//  SDMLeapDevice.h
//  SDMLeapMotionSDK
//
//  Created by Sam Marshall on 12/1/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef SDMLeapMotionSDK_SDMLeapDevice_h
#define SDMLeapMotionSDK_SDMLeapDevice_h

#include "SDMLeapMath.h"

struct SDMLeapDevice {
	
};

typedef struct SDMLeapDevice* SDMLeapDevicePtr;

struct SDMLeapDeviceArray {
	SDMLeapDevicePtr device;
	uint32_t deviceCount;
};

typedef struct SDMLeapDeviceArray* SDMLeapDeviceArrayPtr;


#endif