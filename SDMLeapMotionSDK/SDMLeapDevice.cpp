//
//  SDMLeapDevice.c
//  SDMLeapMotionSDK
//
//  Created by Sam Marshall on 12/1/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef SDMLeapMotionSDK_SDMLeapDevice_c
#define SDMLeapMotionSDK_SDMLeapDevice_c

#include "SDMLeapDevice.h"

SDMLeapDevicePtr SDMLeapDeviceCreate(Leap::Device *leapDevice) {
	SDMLeapDevicePtr device = (SDMLeapDevicePtr)calloc(0x1, sizeof(struct SDMLeapDevice));
	if (device) {
		device->interfaceDevice = leapDevice;
	}
	return device;
}

SDMLeapDeviceArrayPtr SDMLeapDeviceArrayAdd(SDMLeapDeviceArrayPtr array, SDMLeapDevicePtr device) {
	if (array && array->deviceCount) {
		array->device = realloc(array->device, (array->deviceCount+0x1)*sizeof(struct SDMLeapListener));
		array->device[array->listenerCount] = device;
		array->deviceCount++;
	}
	return array;
}

float SDMLeapDeviceHorizontalView(SDMLeapDevicePtr device) {
	return device->interfaceDevice->horizontalViewAngle();
}

float SDMLeapDeviceVerticalView(SDMLeapDevicePtr device) {
	return device->interfaceDevice->verticalViewAngle();
}

float SDMLeapDeviceRange(SDMLeapDevicePtr device) {
	return device->interfaceDevice->range();
}

float SDMLeapDeviceDistanceToBoundry(SDMLeapDevicePtr device, SDMLeapVectorPtr vector) {
	Leap::Vector v(vector->x, vector->y, vector->z);
	return device->interfaceDevice->distanceToBoundary(v);
}

bool SDMLeapDeviceIsValid(SDMLeapDevicePtr device) {
	return (bool)(device->interfaceDevice->isValid() & 0xf);
}

bool SDMLeapDeviceEqualsDevice(SDMLeapDevicePtr device, SDMLeapDevicePtr otherDevice) {
	return (bool)(device->interfaceDevice == otherDevice->interfaceDevice);
}

SDMLeapDevicePtr SDMLeapDeviceCreateInvalidDevice() {
	return SDMLeapDeviceCreate(Leap::Device::invalid());
}

void SDMLeapDeviceRelease(SDMLeapDevicePtr device) {
	if (device->interfaceDevice) {
		delete device->interfaceDevice;
	}
	
	if (device) {
		free(device);
	}
}

#endif