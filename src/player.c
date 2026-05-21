#include "string.h"
#include "player.h"
#include "team.h"
#include "game.h"

void internal_playerSetPosRot(Player *, VECTOR, VECTOR, int, int, int, int, int);

/*
 * 
 */
#define PLAYER_STRUCT_ARRAY                         ((Player**)0x00344C38)

/*
 * Local player 1 dme player index.
 */
#define PLAYER_1_ID                                 (*(u32*)0x0017218C)

/*
 * Local player 2 dme player index.
 */
#define PLAYER_2_ID                                 (*(u32*)0x001B6ED8)

/*
 *
 */
#define PLAYER_LOCAL_COUNT                          (*(int*)0x00172174)

/*
 * Weapon stuff.
 */
#define WEAPON_EQUIPSLOT                            ((int*)0x0020C690)

// 
extern const PadHistory DefaultPadHistory;

// Player pad history
PadHistory PlayerPadHistory[GAME_MAX_PLAYERS] = {};

//--------------------------------------------------------------------------------
Player ** playerGetAll(void)
{
    return PLAYER_STRUCT_ARRAY;
}

//--------------------------------------------------------------------------------
Player * playerGetFromIndex(int idx)
{
    if (idx < 0 || idx >= GAME_MAX_PLAYERS)
        return NULL;

    return PLAYER_STRUCT_ARRAY[idx];
}

//--------------------------------------------------------------------------------
int playerIsValid(Player * player)
{
    return player && player->pMoby && player->pNetPlayer && playerIsConnected(player);
}

//--------------------------------------------------------------------------------
void playerSetLocalEquipslot(int localmpIndex, int slot, int weaponId)
{
    int * equipslots = WEAPON_EQUIPSLOT;
    equipslots[slot + (localmpIndex * 3)] = weaponId;
}

//--------------------------------------------------------------------------------
int playerGetLocalEquipslot(int localmpIndex, int slot)
{
    int * equipslots = WEAPON_EQUIPSLOT;
    return equipslots[slot + (localmpIndex * 3)];
}

//--------------------------------------------------------------------------------
void playerSetHealth(Player * player, float health)
{
    if (!player)
        return;

    player->hitPoints = health;
    if (player->pNetPlayer && player->pNetPlayer->pNetPlayerData)
        player->pNetPlayer->pNetPlayerData->hitPoints = health;
}

//--------------------------------------------------------------------------------
void playerSetTeam(Player * player, int teamId)
{
  if (!player || player->mpTeam == teamId)
      return;

  player->mpTeam = teamId;
  player->pMoby->glow_rgba = TEAM_COLORS[teamId];
  player->pMoby->modeBits2 = (player->pMoby->modeBits2 & 0xff) | ((0x80 + (8 * teamId)) << 8);
  player->pMoby->triggers = 0;

  // update game settings
  GameSettings* gs = gameGetSettings();
  if (gs) {
    gs->PlayerTeams[player->mpIndex] = teamId;
  }
 
  // move to correct voice channel
  if (player->isLocal && player->mpIndex == 0) {
    int channel = voiceGetChannel();
    if (channel > 0 && channel != (teamId + 1)) {
      internal_voiceEnableGlobalChat(1);
      internal_voiceEnableGlobalChat(0);
    }
  }
}

//--------------------------------------------------------------------------------
int playerIsLocal(Player * player)
{
    return (int)player >= 0x00300000 && (int)player <= 0x00400000;
}

//--------------------------------------------------------------------------------
int playerGetNumLocals(void)
{
    return PLAYER_LOCAL_COUNT;
}

//--------------------------------------------------------------------------------
int playerIdIsLocal(int playerId)
{
    return PLAYER_1_ID == playerId || PLAYER_2_ID == playerId;
}

//--------------------------------------------------------------------------------
void playerSetPosRot(Player * player, VECTOR p, VECTOR r)
{
    internal_playerSetPosRot(player, p, r, 0, 1, 1, 1, 1);
}

//--------------------------------------------------------------------------------
PAD * playerGetPad(Player * player)
{
    if (!player)
        return 0;

    if (player->isLocal) {
        if (!player->pPad) return 0;
        return (PAD*)player->pPad;
    }
    else
    {
        struct tNW_Player* netPlayer = player->pNetPlayer;
        if (!netPlayer)
            return 0;

        return (PAD*)(netPlayer->padMessageElems[0].msg.pad_data);
    }
}

//--------------------------------------------------------------------------------
void playerPadUpdate(void)
{
    int i;
    PAD * playerPad;
    struct PadHistory * padHistory;
    Player ** players = playerGetAll();
    Player * player;

    // Update player pad in game
    if (isInGame())
    {
        for (i = 0; i < GAME_MAX_PLAYERS; ++i)
        {
            player = players[i];
            padHistory = &PlayerPadHistory[i];
            playerPad = playerGetPad(player);

            // Copy last player pad
            if (playerPad)
            {
                memcpy(padHistory, &playerPad->btns, sizeof(struct PadHistory));
                padHistory->id = player->mpIndex;
            }
            // Reset pad if no player
            else if (padHistory->id >= 0)
            {
                memcpy(padHistory, &DefaultPadHistory, sizeof(struct PadHistory));
            }
        }
    }

    // Reset player pad history when not in game
    else if (PlayerPadHistory[0].id >= 0)
    {
        for (i = 0; i < GAME_MAX_PLAYERS; ++i)
            memcpy(PlayerPadHistory + i, &DefaultPadHistory, sizeof(struct PadHistory));
    }
}

//--------------------------------------------------------------------------------
int playerPadGetButton(Player * player, u16 buttonMask)
{
    if (!player)
        return 0;

    PAD * paddata = playerGetPad(player);
    if (!paddata)
        return 0;

    return (paddata->btns & buttonMask) == 0;
}

//--------------------------------------------------------------------------------
int playerPadGetAnyButton(Player * player, u16 buttonMask)
{
    if (!player)
        return 0;

    PAD * paddata = playerGetPad(player);
    if (!paddata)
        return 0;

    return (paddata->btns & buttonMask) != buttonMask;
}

//--------------------------------------------------------------------------------
int playerPadGetButtonDown(Player * player, u16 buttonMask)
{
    if (!player)
        return 0;

    return playerPadGetButton(player, buttonMask) &&
            (PlayerPadHistory[player->mpIndex].btns & buttonMask) != 0;
}

//--------------------------------------------------------------------------------
int playerPadGetAnyButtonDown(Player * player, u16 buttonMask)
{
    if (!player)
        return 0;

    return playerPadGetAnyButton(player, buttonMask) &&
            (PlayerPadHistory[player->mpIndex].btns & buttonMask) == buttonMask;
}

//--------------------------------------------------------------------------------
int playerPadGetButtonUp(Player * player, u16 buttonMask)
{
    if (!player)
        return 0;

    return !playerPadGetButton(player, buttonMask) &&
        (PlayerPadHistory[player->mpIndex].btns & buttonMask) == 0;
}

//--------------------------------------------------------------------------------
int playerPadGetAnyButtonUp(Player * player, u16 buttonMask)
{
    if (!player)
        return 0;

    return !playerPadGetAnyButton(player, buttonMask) &&
        (PlayerPadHistory[player->mpIndex].btns & buttonMask) != buttonMask;
}

//--------------------------------------------------------------------------------
PlayerVTable* playerGetVTable(Player * player)
{
    if (!player)
        return NULL;

    return (PlayerVTable*)player->guber.vtable;
}

//--------------------------------------------------------------------------------
int stateIsDead(int state)
{
  return state == PLAYER_STATE_DEATH
        || state == PLAYER_STATE_DROWN
        || state == PLAYER_STATE_DEATH_FALL
        || state == PLAYER_STATE_DEATHSAND_SINK
        || state == PLAYER_STATE_LAVA_DEATH
        || state == PLAYER_STATE_DEATH_NO_FALL
        || state == PLAYER_STATE_WAIT_FOR_RESURRECT
        ;
}

//--------------------------------------------------------------------------------
int playerIsDead(Player * player)
{
  return stateIsDead(player->state);
}
