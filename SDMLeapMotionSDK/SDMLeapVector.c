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
	return VectorCompareEquals(vector, equalsVector);
}

float SDMLeapVectorGetMagnitude(SDMLeapVectorPtr vector) {
	return sqrt(VectorMultiX(vector, vector->x) + VectorMultiY(vector,vector->y) + VectorMultiZ(vector,vector->z));
}

float SDMLeapVectorDistanceToVector(SDMLeapVectorPtr vector, SDMLeapVectorPtr distant) {
	return sqrt(PointDistance(vector->x, distant->x) + PointDistance(vector->y, distant->y) + PointDistance(vector->z, distant->z));
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
	return VectorDotProduct(vector, dotVector);
}

SDMLeapVectorPtr SDMLeapVectorNegate(SDMLeapVectorPtr vector) {
	float x = VectorMultiX(vector,FloatNegateConstant);
	float y = VectorMultiY(vector,FloatNegateConstant);
	float z = VectorMultiZ(vector,FloatNegateConstant);
	return SDMLeapVectorCreateFromComponents(x, y, z);
}

SDMLeapVectorPtr SDMLeapVectorAddVector(SDMLeapVectorPtr vector, SDMLeapVectorPtr addVector) {
	float x = VectorAddX(vector, addVector);
	float y = VectorAddY(vector, addVector);
	float z = VectorAddZ(vector, addVector);
	return SDMLeapVectorCreateFromComponents(x, y, z);
}

SDMLeapVectorPtr SDMLeapVectorMinusVector(SDMLeapVectorPtr vector, SDMLeapVectorPtr minusVector) {
	float x = VectorMinusX(vector, minusVector);
	float y = VectorMinusY(vector, minusVector);
	float z = VectorMinusZ(vector, minusVector);
	return SDMLeapVectorCreateFromComponents(x, y, z);
}

SDMLeapVectorPtr SDMLeapVectorMultiplyVector(SDMLeapVectorPtr vector, float mul) {
	float x = VectorMultiX(vector,mul);
	float y = VectorMultiY(vector,mul);
	float z = VectorMultiZ(vector,mul);
	return SDMLeapVectorCreateFromComponents(x, y, z);
}

SDMLeapVectorPtr SDMLeapVectorDivideVector(SDMLeapVectorPtr vector, float div) {
	float x = VectorDivideX(vector,div);
	float y = VectorDivideY(vector,div);
	float z = VectorDivideZ(vector,div);
	return SDMLeapVectorCreateFromComponents(x, y, z);}

SDMLeapVectorPtr SDMLeapVectorCrossVector(SDMLeapVectorPtr vector, SDMLeapVectorPtr crossVector) {
	float x = VectorCrossProductX(vector, crossVector);
	float y = VectorCrossProductY(vector, crossVector);
	float z = VectorCrossProductZ(vector, crossVector);
	return SDMLeapVectorCreateFromComponents(x, y, z);
}

SDMLeapVectorPtr SDMLeapVectorNormalize(SDMLeapVectorPtr vector) {
	float denom = pow(SDMLeapVectorGetMagnitude(vector),2);
	if (denom <= 0.0f) {
	  return SDMLeapVectorCreateFromVector(SDMLeapVectorAxis(SDMLeapVectorAxisZero));
	}
	denom = 1.0f / sqrt(denom);
	SDMLeapVectorPtr resultVector = SDMLeapVectorCreateFromVector(vector);
	return SDMLeapVectorMultiplyVector(resultVector, denom);
}

SDMLeapVectorPtr SDMLeapVectorAxis(enum SDMLeapVectorAxis axis) {
	SDMLeapVectorPtr vector;
	if (axis < SDMLeapVectorAxisCount) {
		vector = SDMLeapVectorCreateFromVector(&(SDMLeapVectorDefinedVectors[axis]));
	} else {
		vector = SDMLeapVectorCreateFromVector(&(SDMLeapVectorDefinedVectors[SDMLeapVectorAxisZero]));
	}
	return vector;
}

void SDMLeapVectorRelease(SDMLeapVectorPtr vector) {
	if (vector) {
		free(vector);
	}
}

#endif