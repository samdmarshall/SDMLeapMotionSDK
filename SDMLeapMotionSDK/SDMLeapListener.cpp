//
//  SDMLeapListener.c
//  SDMLeapMotionSDK
//
//  Created by Sam Marshall on 12/1/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef SDMLeapMotionSDK_SDMLeapListener_c
#define SDMLeapMotionSDK_SDMLeapListener_c

#include "SDMLeapListener.h"

SDMLeapListenerPtr SDMLeapListenerCreate() {
	SDMLeapListenerPtr listener = (SDMLeapListenerPtr)calloc(0x1, sizeof(struct SDMLeapListener));
	if (listener) {
		listener->listenerQueue = dispatch_queue_create();
		listener->initCallback = NULL;
		listener->connectCallback = NULL;
		listener->disconnectCallback = NULL;
		listener->exitCallback = NULL;
		listener->frameCallback = NULL;
		listener->focusGainedCallback = NULL;
		listener->focusLostCallback = NULL;
	}
	return listener;
}

SDMLeapListenerArrayPtr SDMLeapListenerArrayAdd(SDMLeapListenerArrayPtr array, SDMLeapListenerPtr listener) {
	if (array && array->listenerCount) {
		array->listener = realloc(array->listener, (array->listenerCount+0x1)*sizeof(struct SDMLeapListener));
		array->listener[array->listenerCount] = listener;
		array->listenerCount++;
	}
	return array;
}

void SDMLeapListenerRelease(SDMLeapListenerPtr listener) {
	if (listener->listenerQueue) {
		dispatch_release(listener->listenerQueue);
	}
	
	if (listener) {
		free(listener);
	}
}

#endif