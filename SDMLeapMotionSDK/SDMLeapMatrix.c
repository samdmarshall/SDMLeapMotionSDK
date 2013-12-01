//
//  SDMLeapMatrix.c
//  SDMLeapMotionSDK
//
//  Created by Sam Marshall on 12/1/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef SDMLeapMotionSDK_SDMLeapMatrix_c
#define SDMLeapMotionSDK_SDMLeapMatrix_c

#include "SDMLeapMatrix.h"

SDMLeapMatrixPtr SDMLeapMatrixCreateFromComponents(SDMLeapVectorPtr xBasis, SDMLeapVectorPtr yBasis, SDMLeapVectorPtr zBasis, SDMLeapVectorPtr origin) {
	SDMLeapMatrixPtr matrix = (SDMLeapMatrixPtr)calloc(0x1, sizeof(struct SDMLeapMatrix));
	if (matrix) {
		matrix->xBasis = SDMLeapVectorCreateFromVector(xBasis);
		matrix->yBasis = SDMLeapVectorCreateFromVector(yBasis);
		matrix->zBasis = SDMLeapVectorCreateFromVector(zBasis);
		matrix->origin = SDMLeapVectorCreateFromVector(origin);
	}
	return matrix;
}

SDMLeapMatrixPtr SDMLeapMatrixCreateFromMatrix(SDMLeapMatrixPtr matrix) {
	return SDMLeapMatrixCreateFromComponents(matrix->xBasis, matrix->yBasis, matrix->zBasis, matrix->origin);
}

SDMLeapMatrixPtr SDMLeapMatrixCreateFromAxisRadians(SDMLeapVectorPtr axis, float angle) {
	SDMLeapVectorPtr noTranslate = SDMLeapVectorCreateFromComponents(0.f, 0.f, 0.f);
	SDMLeapMatrixPtr matrix = SDMLeapMatrixCreateFromAxisRadiansTranslation(axis, angle, noTranslate);
	SDMLeapVectorRelease(noTranslate);
	return matrix;
}

SDMLeapMatrixPtr SDMLeapMatrixCreateFromAxisRadiansTranslation(SDMLeapVectorPtr axis, float angle, SDMLeapVectorPtr translate) {
	SDMLeapVectorPtr axisVector = SDMLeapVectorNormalize(axis);
	float s = sin(angle);
	float c = cos(angle);
	float C = (1-c);
	SDMLeapVectorPtr xBasis = SDMLeapVectorCreateFromComponents((axisVector->x*axisVector->x*C + c),
																(axisVector->x*axisVector->y*C - axisVector->z*s), 
																(axisVector->x*axisVector->z*C + axisVector->y*s));
	SDMLeapVectorPtr yBasis = SDMLeapVectorCreateFromComponents((axisVector->y*axisVector->x*C + axisVector->z*s), 
																(axisVector->y*axisVector->y*C + c), 
																(axisVector->y*axisVector->z*C - axisVector->x*s));
	SDMLeapVectorPtr zBasis = SDMLeapVectorCreateFromComponents((axisVector->z*axisVector->x*C - axisVector->y*s), 
																(axisVector->z*axisVector->y*C + axisVector->x*s), 
																(axisVector->z*axisVector->z*C + c));
	SDMLeapVectorRelease(axisVector);
	SDMLeapVectorPtr origin = SDMLeapVectorCreateFromComponents(translate->x, translate->y, translate->z);
	SDMLeapMatrixPtr matrix = SDMLeapMatrixCreateFromComponents(xBasis, yBasis, zBasis, origin);
	SDMLeapVectorRelease(xBasis);
	SDMLeapVectorRelease(yBasis);
	SDMLeapVectorRelease(zBasis);
	SDMLeapVectorRelease(origin);
	return matrix;
}

bool SDMLeapMatrixEqualsMatrix(SDMLeapMatrixPtr matrix, equalsMatrix) {
	return (SDMLeapVectorEqualsVector(matrix->xBasis, equalsMatrix->xBasis) && 
			SDMLeapVectorEqualsVector(matrix->yBasis, equalsMatrix->yBasis) && 
			SDMLeapVectorEqualsVector(matrix->zBasis, equalsMatrix->zBasis) && 
			SDMLeapVectorEqualsVector(matrix->origin, equalsMatrix->origin))
}

SDMLeapVectorPtr SDMLeapMatrixTransformPoint(SDMLeapMatrixPtr matrix, SDMLeapVectorPtr point) {
	SDMLeapVectorPtr xyz = SDMLeapMatrixTransformDirection(matrix, point);
	
	SDMLeapVectorPtr xyzo = SDMLeapVectorAddVector(xyz, matrix->origin);
	SDMLeapVectorRelease(xyz);
	
	return xyzo;
}

SDMLeapVectorPtr SDMLeapMatrixTransformDirection(SDMLeapMatrixPtr matrix, SDMLeapVectorPtr dir) {
	SDMLeapVectorPtr xBasis = SDMLeapVectorMultiplyVector(matrix->xBasis, point->x);
	SDMLeapVectorPtr yBasis = SDMLeapVectorMultiplyVector(matrix->yBasis, point->y);
	SDMLeapVectorPtr zBasis = SDMLeapVectorMultiplyVector(matrix->zBasis, point->z);
	
	SDMLeapVectorPtr xy = SDMLeapVectorAddVector(xBasis, yBasis);
	SDMLeapVectorRelease(xBasis);
	SDMLeapVectorRelease(yBasis);
	
	SDMLeapVectorPtr xyz = SDMLeapVectorAddVector(xy, zBasis);
	SDMLeapVectorRelease(zBasis);
	SDMLeapVectorRelease(xy);
	
	return xyz;
}

SDMLeapMatrixPtr SDMLeapMatrixMultiplyMatrix(SDMLeapMatrixPtr matrix, SDMLeapMatrixPtr mulMatrix) {
	SDMLeapVectorPtr xBasis = SDMLeapMatrixTransformDirection(matrix, mulMatrix->xBasis);
	SDMLeapVectorPtr yBasis = SDMLeapMatrixTransformDirection(matrix, mulMatrix->yBasis);
	SDMLeapVectorPtr zBasis = SDMLeapMatrixTransformDirection(matrix, mulMatrix->zBasis);
	SDMLeapVectorPtr origin = SDMLeapMatrixTransformPoint(matrix, mulMatrix->origin);
	SDMLeapMatrixPtr resultMatrix = SDMLeapMatrixCreateFromComponents(xBasis, yBasis, zBasis, origin);
	SDMLeapVectorRelease(xBasis);
	SDMLeapVectorRelease(yBasis);
	SDMLeapVectorRelease(zBasis);
	SDMLeapVectorRelease(origin);
	return resultMatrix;
}

SDMLeapMatrixPtr SDMLeapMatrixIdentity() {
	SDMLeapVectorPtr xBasis = SDMLeapVectorCreateFromComponents(1.f,0.f,0.f);
	SDMLeapVectorPtr yBasis = SDMLeapVectorCreateFromComponents(0.f,1.f,0.f);
	SDMLeapVectorPtr zBasis = SDMLeapVectorCreateFromComponents(0.f,0.f,1.f);
	SDMLeapVectorPtr origin = SDMLeapVectorCreateFromComponents(0.f,0.f,0.f);
	SDMLeapMatrixPtr matrix = SDMLeapMatrixCreateFromComponents(xBasis, yBasis, zBasis, origin);
	SDMLeapVectorRelease(xBasis);
	SDMLeapVectorRelease(yBasis);
	SDMLeapVectorRelease(zBasis);
	SDMLeapVectorRelease(origin);
	return matrix;
}

SDMLeapMatrixPtr SDMLeapMatrixRigidInverse(SDMLeapMatrixPtr matrix) {
	SDMLeapVectorPtr xBasis = SDMLeapVectorCreateFromComponents(matrix->xBasis->x,matrix->yBasis->x,matrix->zBasis->x);
	SDMLeapVectorPtr yBasis = SDMLeapVectorCreateFromComponents(matrix->xBasis->y,matrix->yBasis->y,matrix->zBasis->y);
	SDMLeapVectorPtr zBasis = SDMLeapVectorCreateFromComponents(matrix->xBasis->z,matrix->yBasis->z,matrix->zBasis->z);
	SDMLeapVectorPtr origin = SDMLeapMatrixTransformDirection(matrix, -matrix->origin);
	SDMLeapMatrixPtr inverseMatrix = SDMLeapMatrixCreateFromComponents(xBasis, yBasis, zBasis, origin);
	SDMLeapVectorRelease(xBasis);
	SDMLeapVectorRelease(yBasis);
	SDMLeapVectorRelease(zBasis);
	SDMLeapVectorRelease(origin);
	return inverseMatrix;
}

void SDMLeapMatrixRelease(SDMLeapMatrixPtr matrix) {
	if (matrix->xBasis) {
		SDMLeapVectorRelease(matrix->xBasis);
	}
	if (matrix->yBasis) {
		SDMLeapVectorRelease(matrix->yBasis);
	}
	if (matrix->zBasis) {
		SDMLeapVectorRelease(matrix->zBasis);
	}
	if (matrix->origin) {
		SDMLeapVectorRelease(matrix->origin);
	}
	if (matrix) {
		free(matrix);
	}
}

#endif