/***************************************************
 * FILENAME :    spawnpoint.h
 * 
 * DESCRIPTION :
 *     Contains spawnpoint specific offsets and structures for Deadlocked.
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */

#ifndef _LIBDL_SPAWNPOINT_H_
#define _LIBDL_SPAWNPOINT_H_

#include "math3d.h"
#include "common.h"

#define SPAWNPOINTS ((Cuboid*)(*(u32*)0x00222820))
#define SP_COUNT (*(int*)0x00222824)
#define SP_HILL_PTR (*(u32*)0x00222698)


typedef struct Cuboid { // 0x80
	/* 0x00 */ mtx3 matrix;
	/* 0x30 */ VECTOR pos;
	/* 0x40 */ mtx3 imatrix;
	/* 0x70 */ VECTOR rot;
} Cuboid;

typedef struct Path { // 0x10
	/* 0x0 */ int nNodes;
	/* 0x4 */ int bPathNormalized;
	/* 0x8 */ char pad[8];
	/* 0x10 */ VECTOR nodes[0];
} Path_t;

/*
 * NAME :    spawnPointGetCount
 * 
 * DESCRIPTION :
 *       
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ int spawnPointGetCount();

/*
 * NAME :    hillPointGetCount
 * 
 * DESCRIPTION :
 *       
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ short hillPointGetCount();

/*
 * NAME :    hillPointSetCount
 * 
 * DESCRIPTION :
 *       
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_SETTER__ void hillPointSetCount(short count);

/*
 * NAME :    hillPointGetIndex
 * 
 * DESCRIPTION :
 *       
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ int hillPointGetIndex(int id);

/*
 * NAME :    hillPointSetIndex
 * 
 * DESCRIPTION :
 *       
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_SETTER__ void hillPointSetIndex(int id, int value);

/*
 * NAME :    spawnPointIsPlayer
 * 
 * DESCRIPTION :
 *       
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
int spawnPointIsPlayer(int index);

/*
 * NAME :    spawnPointGet
 * 
 * DESCRIPTION :
 *       
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ Cuboid * spawnPointGet(int index);

/*
 * NAME :    spawnPointSet
 * 
 * DESCRIPTION :
 *       
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_SETTER__ void spawnPointSet(Cuboid * sp, int index);

/*
 * NAME :    spawnPointIsPointInside
 * 
 * DESCRIPTION :
 *       
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
int spawnPointIsPointInside(Cuboid* sp, VECTOR point, VECTOR outDt);

#endif // _LIBDL_SPAWNPOINT_H_
