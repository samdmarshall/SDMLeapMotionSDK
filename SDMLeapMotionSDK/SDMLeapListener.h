//
//  SDMLeapListener.h
//  SDMLeapMotionSDK
//
//  Created by Sam Marshall on 12/1/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef SDMLeapMotionSDK_SDMLeapListener_h
#define SDMLeapMotionSDK_SDMLeapListener_h

#include <dispatch/dispatch.h>

#include "SDMLeapMath.h"

enum SDMLeapListenerCallbackType {
	SDMLeapListenerCallbackTypeInit = 0x0,
	SDMLeapListenerCallbackTypeConnect,
	SDMLeapListenerCallbackTypeDisconnect,
	SDMLeapListenerCallbackTypeExit,
	SDMLeapListenerCallbackTypeFrame,
	SDMLeapListenerCallbackTypeFocusGained,
	SDMLeapListenerCallbackTypeFocusLost,
	SDMLeapListenerCallbackTypeCount
};

typedef void (*SDMLeapListenerCallback)(SDMLeapListenerPtr, void *);

struct SDMLeapListener {
	dispatch_queue_t listenerQueue;
	SDMLeapListenerCallback initCallback;
	SDMLeapListenerCallback connectCallback;
	SDMLeapListenerCallback disconnectCallback;
	SDMLeapListenerCallback exitCallback;
	SDMLeapListenerCallback frameCallback;
	SDMLeapListenerCallback focusGainedCallback;
	SDMLeapListenerCallback focusLostCallback;
};

typedef struct SDMLeapListener* SDMLeapListenerPtr;

struct SDMLeapListenerArray {
	SDMLeapListenerPtr listener;
	uint32_t listenerCount;
};

typedef struct SDMLeapListenerArray* SDMLeapListenerArrayPtr;

SDMLeapListenerPtr SDMLeapListenerCreate();

SDMLeapListenerArrayPtr SDMLeapListenerArrayAdd(SDMLeapListenerArrayPtr array, SDMLeapListenerPtr listener);

void SDMLeapListenerRelease(SDMLeapListenerPtr listener);

#endif