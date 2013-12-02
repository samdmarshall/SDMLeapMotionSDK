//
//  SDMLeapScreen.c
//  SDMLeapMotionSDK
//
//  Created by Sam Marshall on 12/1/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef SDMLeapMotionSDK_SDMLeapScreen_c
#define SDMLeapMotionSDK_SDMLeapScreen_c

#include "SDMLeapScreen.h"

SDMLeapScreenPtr SDMLeapScreenCreate(Leap::Screen *interfaceScreen) {
	SDMLeapScreenPtr screen = (SDMLeapScreenPtr)calloc(0x1, sizeof(struct SDMLeapScreen));
	if (screen) {
		screen->interfaceScreen = interfaceScreen;
	}
	return screen;
}

int32_t SDMLeapScreenIdentifier(SDMLeapScreenPtr screen) {
	return screen->interfaceScreen->id();
}

SDMLeapVectorPtr SDMLeapScreenIntersectPointableWithRatio(SDMLeapScreenPtr screen, SDMLeapPointablePtr pointable, bool normalize, float clampRatio) {
	Leap::Pointable *leapPointable = pointable->interfacePointable;
	Leap::Vector v = screen->interfaceScreen->intersect(*leapPointable, normalize, clampRatio);
	return SDMLeapVectorCreateFromComponents(v->x, v->y, v->z);
}
SDMLeapVectorPtr SDMLeapScreenIntersectPositionInDirectionWithRatio(SDMLeapScreenPtr screen, SDMLeapVectorPtr position, SDMLeapVectorPtr direction, bool normalize, float clampRatio) {
	Leap::Vector leapPosition(position->x, position->y, position->z);
	Leap::Vector leapDirection(direction->x, direction->y, direction->z);
	Leap::Vector v = screen->interfaceScreen->intersect(leapPosition, leapDirection, normalize, clampRatio);
	return SDMLeapVectorCreateFromComponents(v->x, v->y, v->z);
}

SDMLeapVectorPtr SDMLeapScreenProject(SDMLeapScreenPtr screen, SDMLeapVectorPtr position, bool normalize, float clampRatio) {
	Leap::Vector leapPosition(position->x, position->y, position->z);
	Leap::Vector v = screen->interfaceScreen->project(leapPosition, normalize, clampRatio);
	return SDMLeapVectorCreateFromComponents(v->x, v->y, v->z);
}

SDMLeapVectorPtr SDMLeapScreenHorizontalAxis(SDMLeapScreenPtr screen) {
	Leap::Vector v = screen->interfaceScreen->horizontalAxis();
	return SDMLeapVectorCreateFromComponents(v->x, v->y, v->z);
}

SDMLeapVectorPtr SDMLeapScreenVerticalAxis(SDMLeapScreenPtr screen) {
	Leap::Vector v = screen->interfaceScreen->verticalAxis();
	return SDMLeapVectorCreateFromComponents(v->x, v->y, v->z);
}

SDMLeapVectorPtr SDMLeapScreenBottomLeft(SDMLeapScreenPtr screen) {
	Leap::Vector v = screen->interfaceScreen->bottomLeftCorner();
	return SDMLeapVectorCreateFromComponents(v->x, v->y, v->z);
}

SDMLeapVectorPtr SDMLeapScreenNormal(SDMLeapScreenPtr screen) {
	Leap::Vector v = screen->interfaceScreen->normal();
	return SDMLeapVectorCreateFromComponents(v->x, v->y, v->z);
}

float SDMLeapScreenWidth(SDMLeapScreenPtr screen) {
	return screen->interfaceScreen->widthPixels();
}

float SDMLeapScreenHeight(SDMLeapScreenPtr screen) {
	return screen->interfaceScreen->heightPixels();
}

float SDMLeapScreenDistanceToPoint(SDMLeapScreenPtr screen, SDMLeapVectorPtr point) {
	Leap::Vector p(point->x, point-y, point->z);
	return screen->interfaceScreen->distanceToPoint(p);
}

bool SDMLeapScreenIsValid(SDMLeapScreenPtr screen) {
	return (bool)(screen->interfaceScreen->isValid() & 0xf);
}

bool SDMLeapScreenEqualsScreen(SDMLeapScreenPtr screen, SDMLeapScreenPtr otherScreen) {
	return (bool)(screen->interfaceScreen == otherScreen->interfaceScreen);
}

SDMLeapScreenPtr SDMLeapScreenCreateInvalid() {
	static const Leap::Screen &invalid_screen = Leap::Screen::invalid();
	return SDMLeapScreenCreate(&invalid_screen);
}

void SDMLeapScreenRelease(SDMLeapScreenPtr screen) {
	if (screen->interfaceScreen) {
		delete screen->interfaceScreen;
	}
	if (screen) {
		free(screen);
	}
}

#endif