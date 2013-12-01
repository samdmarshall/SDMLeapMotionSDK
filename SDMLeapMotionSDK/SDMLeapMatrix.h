//
//  SDMLeapMatrix.h
//  SDMLeapMotionSDK
//
//  Created by Sam Marshall on 12/1/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef SDMLeapMotionSDK_SDMLeapMatrix_h
#define SDMLeapMotionSDK_SDMLeapMatrix_h

#include "SDMLeapMath.h"
#include "SDMLeapVector.h"

struct SDMLeapMatrix {
	SDMLeapVectorPtr xBasis;
	SDMLeapVectorPtr yBasis;
	SDMLeapVectorPtr zBasis;
	SDMLeapVectorPtr origin;
};

typedef struct SDMLeapMatrix* SDMLeapMatrixPtr;

SDMLeapMatrixPtr SDMLeapMatrixCreateFromComponents(SDMLeapVectorPtr xBasis, SDMLeapVectorPtr yBasis, SDMLeapVectorPtr zBasis, SDMLeapVectorPtr origin);
SDMLeapMatrixPtr SDMLeapMatrixCreateFromMatrix(SDMLeapMatrixPtr matrix);
SDMLeapMatrixPtr SDMLeapMatrixCreateFromAxisRadians(SDMLeapVectorPtr axis, float angle);
SDMLeapMatrixPtr SDMLeapMatrixCreateFromAxisRadiansTranslation(SDMLeapVectorPtr axis, float angle, SDMLeapVectorPtr translate);

bool SDMLeapMatrixEqualsMatrix(SDMLeapMatrixPtr matrix, equalsMatrix);
SDMLeapVectorPtr SDMLeapMatrixTransformPoint(SDMLeapMatrixPtr matrix, SDMLeapVectorPtr point);
SDMLeapVectorPtr SDMLeapMatrixTransformDirection(SDMLeapMatrixPtr matrix, SDMLeapVectorPtr dir);
SDMLeapMatrixPtr SDMLeapMatrixMultiplyMatrix(SDMLeapMatrixPtr matrix, SDMLeapMatrixPtr mulMatrix);
SDMLeapMatrixPtr SDMLeapMatrixIdentity();
SDMLeapMatrixPtr SDMLeapMatrixRigidInverse(SDMLeapMatrixPtr matrix);

void SDMLeapMatrixRelease(SDMLeapMatrixPtr matrix);

#endif