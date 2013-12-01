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

#define FloatNegateConstant -1.f

#define FloatCompareEqual(a, b) ((float)fabs((a) - (b)) < FLT_EPSILON)

#define PointDistance(a, b) ((a - b)*(a - b))

#define VectorAddX(vector, addVector) (vector->x + addVector->x)
#define VectorAddY(vector, addVector) (vector->y + addVector->y)
#define VectorAddZ(vector, addVector) (vector->z + addVector->z)

#define VectorMinusX(vector, minusVector) (vector->x - minusVector->x)
#define VectorMinusY(vector, minusVector) (vector->y - minusVector->y)
#define VectorMinusZ(vector, minusVector) (vector->z - minusVector->z)

#define VectorMultiX(vector, multiScalar) (vector->x*multiScalar)
#define VectorMultiY(vector, multiScalar) (vector->y*multiScalar)
#define VectorMultiZ(vector, multiScalar) (vector->z*multiScalar)

#define VectorDivideX(vector, divScalar) (vector->x/divScalar)
#define VectorDivideY(vector, divScalar) (vector->y/divScalar)
#define VectorDivideZ(vector, divScalar) (vector->z/divScalar)

#define VectorCrossProductX(vector, crossVector) (vector->y * crossVector->z) - (vector->z * crossVector->y)
#define VectorCrossProductY(vector, crossVector) (vector->z * crossVector->x) - (vector->x * crossVector->z)
#define VectorCrossProductZ(vector, crossVector) (vector->x * crossVector->y) - (vector->y * crossVector->x)

#define VectorDotProduct(vector, dotVector) ((vector->x*dotVector->x) + (vector->y*dotVector->y) + (vector->z*dotVector->z))

#define VectorAxisTranslateSame(axis, c, C) (axis*axis*C + c)

#define VectorAxisTranslateXX(axisVector, s, c, C) VectorAxisTranslateSame(axisVector->x, c, C)
#define VectorAxisTranslateXY(axisVector, s, c, C) (axisVector->x*axisVector->y*C - axisVector->z*s)
#define VectorAxisTranslateXZ(axisVector, s, c, C) (axisVector->x*axisVector->z*C + axisVector->y*s)

#define VectorAxisTranslateYX(axisVector, s, c, C) (axisVector->y*axisVector->x*C + axisVector->z*s)
#define VectorAxisTranslateYY(axisVector, s, c, C) VectorAxisTranslateSame(axisVector->y, c, C)
#define VectorAxisTranslateYZ(axisVector, s, c, C) (axisVector->y*axisVector->z*C - axisVector->x*s)

#define VectorAxisTranslateZX(axisVector, s, c, C) (axisVector->z*axisVector->x*C - axisVector->y*s)
#define VectorAxisTranslateZY(axisVector, s, c, C) (axisVector->z*axisVector->y*C + axisVector->x*s)
#define VectorAxisTranslateZZ(axisVector, s, c, C) VectorAxisTranslateSame(axisVector->z, c, C)

#define VectorCompareEquals(vector, equalsVector) (FloatCompareEqual(vector->x, equalsVector->x) && FloatCompareEqual(vector->y, equalsVector->y) && FloatCompareEqual(vector->z, equalsVector->z))

#define MatrixCompareEquals(matrix, equalsMatrix) (SDMLeapVectorEqualsVector(matrix->xBasis, equalsMatrix->xBasis) && SDMLeapVectorEqualsVector(matrix->yBasis, equalsMatrix->yBasis) && SDMLeapVectorEqualsVector(matrix->zBasis, equalsMatrix->zBasis) && SDMLeapVectorEqualsVector(matrix->origin, equalsMatrix->origin))

#endif