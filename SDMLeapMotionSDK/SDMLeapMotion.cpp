//
//  SDMLeapMotion.c
//  SDMLeapMotionSDK
//
//  Created by Sam Marshall on 12/1/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef SDMLeapMotionSDK_SDMLeapMotion_c
#define SDMLeapMotionSDK_SDMLeapMotion_c

#include "SDMLeapMotion.h"

SDMLeapMotionControllerPtr SDMLeapMotionControllerCreate() {
	SDMLeapMotionControllerPtr controller = (SDMLeapMotionControllerPtr)calloc(0x1, sizeof(struct SDMLeapMotionController));
	if (controller) {
		controller->listenerArray = (SDMLeapListenerArrayPtr)calloc(0x1, sizeof(struct SDMLeapListenerArray));
		controller->deviceArray = (SDMLeapDeviceArrayPtr)calloc(0x1, sizeof(struct SDMLeapDeviceArray));
	}
	return controller;
}

void SDMLeapMotionControllerRelease(SDMLeapMotionControllerPtr controller) {
	if (controller->listenerArray) {
		for (uint32_t i = 0x0; i < controller->listenerArray->listenerCount; i++) {
			SDMLeapListenerRelease(controller->listenerArray->listener[i]);
		}
		free(controller->listenerArray);
	}
	
	if (controller->deviceArray) {
		for (uint32_t i = 0x0; i < controller->deviceArray->listenerCount; i++) {
			SDMLeapDeviceRelease(controller->deviceArray->listener[i]);
		}
		free(controller->deviceArray);
	}
	
	if (controller) {
		free(controller);
	}
}

#endif