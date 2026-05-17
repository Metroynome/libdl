/***************************************************
 * FILENAME :    guber.h
 * 
 * DESCRIPTION :
 *     Contains guber specific offsets and structures for Deadlocked.
 * 
 * NOTES :
 *     Each offset is determined per app id.
 *     This is to ensure compatibility between versions of Deadlocked/Gladiator.
 *     
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */

#ifndef _LIBDL_GUBER_H_
#define _LIBDL_GUBER_H_

#include <tamtypes.h>
#include "math3d.h"
#include "common.h"
#include "moby.h"
#include "gid.h"


typedef Moby* (*GuberGetMoby_func)(struct Guber* guber);

/*
 * NAME :    PlayerVTable
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
struct GuberVTable
{
    void * FUNC_00;
    void * FUNC_04;
    void * FUNC_08;
    void * FUNC_0C;
    GuberGetMoby_func GetMoby;
    void * FUNC_14;
    void * FUNC_18;
    void * FUNC_1C;
    void * FUNC_20;
};

/*
 * NAME :    GuberDef
 * 
 * DESCRIPTION :
 *       Contains the guber definition struct data.
 * 
 * NOTES :
 *          Mobies are objects that can be spawned in game.
 *          This includes things like vehicles, turrets, mod pads, etc
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
typedef struct Gid { // 0x4
	/* 0x0:0 */ unsigned int ObjectIndex : 12;
	/* 0x1:4 */ unsigned int ObjectCount : 12;
	/* 0x3:0 */ unsigned int ObjectType : 4;
	/* 0x3:4 */ unsigned int HostId : 4;
} Gid_t;

typedef struct Guber { // 0x18
	union { // 0x4
		/* 0x00 */ unsigned int UID;
		/* 0x00 */ Gid_t gid;
	};
	/* 0x04 */ int MasterHostId;
	/* 0x08 */ int State;
	/* 0x0c */ struct Guber *pNext;
	/* 0x10 */ struct Guber *pPrev;
	/* 0x14 */ struct GuberVTable* vtable;
} Guber;

typedef struct GuberMoby {
    Guber Guber;
    Moby * Moby;
    short ModeBits;
    u8 PADDING_0[2];
    void * UpdateFunc;
    int ClientUpdateTime;
    int TeamNum;
    int EnableAutoMigrateMaster;
    int LastMasterMigrateTime;
    int CurrentMaster;
    int NextMaster;
    int MasterTransferTime;
    int LastMasterMessageTime;
    int MasterHandler;
    int AssignedMaster;
    int LastAssignedTransferMaster;
    char LastMessageNum;
    char MessageNum;
    u8 PADDING_1[2];
} GuberMoby;

typedef struct NetEvent {
    struct {
        unsigned int EventID : 4;
        unsigned int NetDataSize : 6;
        unsigned int OriginClientIdx : 4;
        unsigned int RelDispatchTime : 18;
    };
  int CreateTime;
  unsigned int ObjUID;
  char NetData[64];
} NetEvent;

typedef struct GuberEvent {
    NetEvent NetEvent;
    int NetSendTime;
    int NetSendTo;
    u8 NetDataOffset;
    char MsgSendPending;
    u8 PADDING[2];
    void * NextEvent;
} GuberEvent;



/*
 * Returns pointer to the first GuberMoby if it exists.
 */
__LIBDL_GETTER__ GuberMoby * guberMobyGetFirst(void);

Guber * guberGetObjectByUID(u32 uid);

Guber * guberGetObjectByMoby(Moby* moby);

Guber * guberGetOrCreateObjectByMoby(Moby* moby, int a1, int a2);

u32 guberGetUID(Moby* moby);

void guberEventRead(GuberEvent * event, void * dest, int size);

void guberEventWrite(GuberEvent * event, void * src, int size);

GuberEvent* guberEventAlloc(void);
GuberEvent* guberEventAllocSafe(void);

GuberEvent* guberEventCreateEvent(Guber * guber, int eventId, int arg3, int arg4);
GuberEvent* guberEventCreateEventSafe(Guber * guber, int eventId, int arg3, int arg4);
int guberCountFreeEvents(void);

int guberMobyCreateSpawned(short mobyId, short pvarSize, GuberEvent ** event, Guber * parent);

struct Player * guberMobyGetPlayerDamager(Moby* moby);

void guberMobyDestroy(Moby* moby);

void* masterGet(u32 uid);
void* masterDelete(void * master);
void* masterCreate(void * object, u32 a1);

#endif // _LIBDL_GUBER_H_
