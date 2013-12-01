//
//  SDMLeapMath.h
//  SDMLeapMotionSDK
//
//  Created by Sam Marshall on 12/1/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef SDMLeapMotionSDK_SDMLeapMath_h
#define SDMLeapMotionSDK_SDMLeapMath_h

#include "math.h"
#define FloatCompareEqual(a, b) ((float)fabs((a) - (b)) < FLT_EPSILON)

#define PointDistance(a, b) ((a - b)*(a - b))

#define VectorCrossProductX(vector, crossVector) (vector->y * crossVector->z) - (vector->z * crossVector->y)
#define VectorCrossProductY(vector, crossVector) (vector->z * crossVector->x) - (vector->x * crossVector->z)
#define VectorCrossProductZ(vector, crossVector) (vector->x * crossVector->y) - (vector->y * crossVector->x)

#define VectorDotProduct(vector, dotVector) ((vector->x*dotVector->x) + (vector->y*dotVector->y) + (vector->z*dotVector->z))

#endif