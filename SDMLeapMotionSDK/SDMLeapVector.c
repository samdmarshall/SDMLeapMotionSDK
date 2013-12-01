//
//  SDMLeapVector.c
//  SDMLeapMotionSDK
//
//  Created by Sam Marshall on 12/1/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef SDMLeapMotionSDK_SDMLeapVector_c
#define SDMLeapMotionSDK_SDMLeapVector_c

#include "SDMLeapVector.h"

static SDMLeapVector SDMLeapVectorDefinedVectors[SDMLeapVectorAxisCount] = {
	{0.f,0.f,0.f},
	{1.f,0.f,0.f},
	{0.f,1.f,0.f},
	{0.f,0.f,1.f},
	{-1.f,0.f,0.f},
	{1.f,0.f,0.f},
	{0.f,-1.f,0.f},
	{0.f,1.f,0.f},
	{0.f,0.f,-1.f},
	{0.f,0.f,1.f}
};

SDMLeapVectorPtr SDMLeapVectorCreateFromComponents(float x, float y, float z) {
	SDMLeapVectorPtr vector = (SDMLeapVectorPtr)calloc(0x1, sizeof(struct SDMLeapVector));
	if (vector) {
		vector->x = x;
		vector->y = y;
		vector->z = z;
	}
	return vector;
}

SDMLeapVectorPtr SDMLeapVectorCreateFromVector(SDMLeapVectorPtr vector) {
	return SDMLeapVectorCreateFromComponents(vector->x, vector->y, vector->z);
}

bool SDMLeapVectorEqualsVector(SDMLeapVectorPtr vector, SDMLeapVectorPtr equalsVector) {
	return (FloatCompareEqual(vector->x, equalsVector->x) && 
			FloatCompareEqual(vector->y, equalsVector->y) && 
			FloatCompareEqual(vector->z, equalsVector->z));
}

float SDMLeapVectorGetMagnitude(SDMLeapVectorPtr vector) {
	return sqrt((vector->x * vector->x) + (vector->y * vector->y) + (vector->z * vector->z));
}

float SDMLeapVectorDistanceToVector(SDMLeapVectorPtr vector, SDMLeapVectorPtr distant) {
	return sqrt(((vector->x - distant->x)*(vector->x - distant->x)) + 
				((vector->y - distant->y)*(vector->y - distant->y)) + 
				((vector->z - distant->z)*(vector->z - distant->z)));
}

float SDMLeapVectorAngleToVector(SDMLeapVectorPtr vector, SDMLeapVectorPtr distant) {
	float denom = pow(SDMLeapVectorGetMagnitude(vector),2) * pow(SDMLeapVectorGetMagnitude(distant),2);
	if (FloatCompareEqual(denom,0.f) || denom < 0.f) {
		denom = 0.f;
	} else {
		denom = acos(SDMLeapVectorDotVector(vector, distant) / sqrt(denom));
	}
	return denom;
}

float SDMLeapVectorPitch(SDMLeapVectorPtr vector) {
	return atan2(vector->y, -vector->z);
}

float SDMLeapVectorRoll(SDMLeapVectorPtr vector) {
	return atan2(vector->x, -vector->y);
}

float SDMLeapVectorYaw(SDMLeapVectorPtr vector) {
	return atan2(vector->x, -vector->z);
}

float SDMLeapVectorDotVector(SDMLeapVectorPtr vector, SDMLeapVectorPtr dotVector) {
	return ((vector->x*dotVector->x) + (vector->y*dotVector->y) + (vector->z*dotVector->z));
}

SDMLeapVectorPtr SDMLeapVectorNegate(SDMLeapVectorPtr vector) {
	return SDMLeapVectorCreateFromComponents(-vector->x, -vector->y, -vector->z);
}

SDMLeapVectorPtr SDMLeapVectorAddVector(SDMLeapVectorPtr vector, SDMLeapVectorPtr addVector) {
	return SDMLeapVectorCreateFromComponents(vector->x+addVector->x, vector->y+addVector->y, vector->z+addVector->z);
}

SDMLeapVectorPtr SDMLeapVectorMinusVector(SDMLeapVectorPtr vector, SDMLeapVectorPtr minusVector) {
	return SDMLeapVectorCreateFromComponents(vector->x-minusVector->x, vector->y-minusVector->y, vector->z-minusVector->z);
}

SDMLeapVectorPtr SDMLeapVectorMultiplyVector(SDMLeapVectorPtr vector, float mul) {
	return SDMLeapVectorCreateFromComponents(vector->x*mul, vector->y*mul, vector->z*mul);
}

SDMLeapVectorPtr SDMLeapVectorDivideVector(SDMLeapVectorPtr vector, float div) {
	return SDMLeapVectorCreateFromComponents(vector->x/div, vector->y/div, vector->z/div);
}

SDMLeapVectorPtr SDMLeapVectorCrossVector(SDMLeapVectorPtr vector, SDMLeapVectorPtr crossVector) {
	float x = (vector->y * crossVector->z) - (vector->z * crossVector->y);
	float y = (vector->z * crossVector->x) - (vector->x * crossVector->z);
	float z = (vector->x * crossVector->y) - (vector->y * crossVector->x);
	return SDMLeapVectorCreateFromComponents(x, y, z);
}

SDMLeapVectorPtr SDMLeapVectorNormalize(SDMLeapVectorPtr vector) {
	float denom = pow(SDMLeapVectorGetMagnitude(vector),2);
	if (denom <= 0.0f) {
	  return SDMLeapVectorAxis(SDMLeapVectorAxisZero);
	}
	denom = 1.0f / sqrt(denom);
	return SDMLeapVectorCreateFromComponents(vector->x*denom, vector->y*denom, vector->z*denom);
}

SDMLeapVectorPtr SDMLeapVectorAxis(enum SDMLeapVectorAxis axis) {
	SDMLeapVector v = SDMLeapVectorDefinedVectors[axis];
	SDMLeapVectorPtr vector = SDMLeapVectorCreateFromComponents(v.x, v.y, v.z);
	return vector;
}

void SDMLeapVectorRelease(SDMLeapVectorPtr vector) {
	if (vector) {
		free(vector);
	}
}

#endif