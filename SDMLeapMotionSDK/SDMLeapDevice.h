//
//  SDMLeapDevice.h
//  SDMLeapMotionSDK
//
//  Created by Sam Marshall on 12/1/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef SDMLeapMotionSDK_SDMLeapDevice_h
#define SDMLeapMotionSDK_SDMLeapDevice_h

#include "Leap.h"
#include "SDMLeapMath.h"
#include "SDMLeapVector.h"

struct SDMLeapDevice {
	Leap::Device *interfaceDevice;
};

typedef struct SDMLeapDevice* SDMLeapDevicePtr;

struct SDMLeapDeviceArray {
	SDMLeapDevicePtr device;
	uint32_t deviceCount;
};

typedef struct SDMLeapDeviceArray* SDMLeapDeviceArrayPtr;

SDMLeapDevicePtr SDMLeapDeviceCreate(Leap::Device *leapDevice);

SDMLeapDeviceArrayPtr SDMLeapDeviceArrayAdd(SDMLeapDeviceArrayPtr array, SDMLeapDevicePtr device);

float SDMLeapDeviceHorizontalView(SDMLeapDevicePtr device);
float SDMLeapDeviceVerticalView(SDMLeapDevicePtr device);
float SDMLeapDeviceRange(SDMLeapDevicePtr device);
float SDMLeapDeviceDistanceToBoundry(SDMLeapDevicePtr device, SDMLeapVectorPtr vector);

bool SDMLeapDeviceIsValid(SDMLeapDevicePtr device);
bool SDMLeapDeviceEqualsDevice(SDMLeapDevicePtr device, SDMLeapDevicePtr otherDevice);

SDMLeapDevicePtr SDMLeapDeviceCreateInvalidDevice();

void SDMLeapDeviceRelease(SDMLeapDevicePtr device);

#endif