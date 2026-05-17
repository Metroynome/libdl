#include <tamtypes.h>
#include "string.h"
#include "spawnpoint.h"
#include "game.h"

int spawnPointGetCount()
{
    return SP_COUNT;
}

short hillPointGetCount()
{
    u32 * hillInfo = (u32*)SP_HILL_PTR;
    if (!hillInfo)
        return 0;

    return *((short*)(hillInfo + 12) + 1);
}

void hillPointSetCount(short count)
{
    u32 hillInfo = (u32)SP_HILL_PTR;
    if (!hillInfo)
        return;

    *(short*)(hillInfo + 0x32) = count;
}

int hillPointGetIndex(int id)
{
    u32 hillInfo = (u32)SP_HILL_PTR;
    if (!hillInfo)
        return -1;

    return ((u32*)(hillInfo + 0x50))[id];
}

void hillPointSetIndex(int id, int value)
{
    u32 hillInfo = (u32)SP_HILL_PTR;
    if (!hillInfo)
        return;

    ((u32*)(hillInfo + 0x50))[id] = value;
}

int spawnPointIsPlayer(int index)
{
  int i;
  GameData* gameData = gameGetData();
  for (i = 0; i < 64; ++i)
  {
    if (gameData->DeathmatchGameData->ResurrectionPts[i] == index)
      return 1;
  }

  return 0;
}

Cuboid * spawnPointGet(int index)
{
    Cuboid * spawnPoints = SPAWNPOINTS;
    if (!spawnPoints)
        return NULL;

    return &spawnPoints[index];
}

void spawnPointSet(Cuboid * sp, int index)
{
    Cuboid * spawnPoints = SPAWNPOINTS;
    if (!spawnPoints)
        return;

    memcpy(&spawnPoints[index], sp, sizeof(Cuboid));
}
