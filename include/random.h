/***************************************************
 * FILENAME :		random.h
 * DESCRIPTION :
 * AUTHOR :			Troy "Metroynome" Pruitt
 */

#ifndef _LIBDL_RANDOM_H_
#define _LIBDL_RANDOM_H_

#include <tamtypes.h>
#include "math.h"
#include "math3d.h"

#define RANDOM_SEED ((u32*)0x0021dc80)

/*
 * NAME :		randSeed
 * DESCRIPTION :
 *              Returns a random seed.
 * NOTES :
 * ARGS : 
 * RETURN :     Troy "Metroynome" Pruitt
 */
u32 randSeed(void);

/*
 * NAME :		rand
 * DESCRIPTION :
 * NOTES :
 * ARGS : 
 * RETURN :     Troy "Metroynome" Pruitt
 */
int rand(int max);

/*
 * NAME :		randVector
 * DESCRIPTION :
 * 			    Returns a vector where the first three components are between +- unitLen.
 * NOTES :
 * ARGS : 
 * RETURN :     Troy "Metroynome" Pruitt
 */
// u128 randVector(float unitLen);

/*
 * NAME :		randVectorRangeNeg
 * DESCRIPTION :
 * 			    Returns a vector where the first three components are between [min, max] or [-min, -max]
 * NOTES :
 * ARGS : 
 * RETURN :     Troy "Metroynome" Pruitt
 */
// u128 randVectorRangeNeg(float min, float max);

/*
 * NAME :		randVectorRange
 * DESCRIPTION :
 * 			    Returns a vector where the first three components are between [min, max]
 * NOTES :
 * ARGS : 
 * RETURN :     Troy "Metroynome" Pruitt
 */
void randVectorRange(VECTOR output, float min, float max);

/*
 * NAME :		randRangeFloat
 * DESCRIPTION :
 * NOTES :
 * ARGS : 
 * RETURN :     Troy "Metroynome" Pruitt
 */
float randRangeFloat(float min, float max);

/*
 * NAME :		randRangeFloatNeg
 * DESCRIPTION :
 * 			Returns a value between [min, max] or [-min, -max]
 * NOTES :
 * ARGS : 
 * RETURN :     Troy "Metroynome" Pruitt
 */
float randRangeFloatNeg(float min, float max);

/*
 * NAME :		randRangeInt
 * DESCRIPTION :
 * 			    Returns a value between [min, max]
 * NOTES :
 * ARGS : 
 * RETURN :     Troy "Metroynome" Pruitt
 */
int randRangeInt(int min, int max);

/*
 * NAME :		randRot
 * DESCRIPTION :
 * NOTES :
 * ARGS : 
 * RETURN :     Troy "Metroynome" Pruitt
 */
float randRot(void);

void randSphere(VECTOR output, float min, float max);

#endif // _LIBDL_RANDOM_H_
