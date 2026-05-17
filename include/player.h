/***************************************************
 * FILENAME :    player.h
 * 
 * DESCRIPTION :
 *     Contains player specific offsets and structures for Deadlocked.
 * 
 * NOTES :
 *     Each offset is determined per app id.
 *     This is to ensure compatibility between versions of Deadlocked/Gladiator.
 *     
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */

#ifndef _LIBDL_PLAYER_H_
#define _LIBDL_PLAYER_H_

#include "math.h"
#include "weapon.h"
#include "Moby.h"
#include "pad.h"
#include "team.h"
#include "math3d.h"
#include "vehicle.h"
#include "common.h"
#include "camera.h"
#include "guber.h"
#include "spawnpoint.h"
#include "collision.h"

#define PLAYER_MAX_HEALTH                   (50)

enum PlayerCameraType {
    CAMERA_TYPE_THIRD_PERSON,
    CAMERA_TYPE_LOCK_STRAFE,
    CAMERA_TYPE_FIRST_PERSON
};

enum PlayerState {
	PLAYER_STATE_IDLE = 0,
	PLAYER_STATE_LOOK = 1,
	PLAYER_STATE_WALK = 2,
	PLAYER_STATE_SKID = 3,
	PLAYER_STATE_CROUCH = 4,
	PLAYER_STATE_QUICK_TURN = 5,
	PLAYER_STATE_FALL = 6,
	PLAYER_STATE_JUMP = 7,
	PLAYER_STATE_GLIDE = 8,
	PLAYER_STATE_RUN_JUMP = 9,
	PLAYER_STATE_LONG_JUMP = 10,
	PLAYER_STATE_FLIP_JUMP = 11,
	PLAYER_STATE_JINK_JUMP = 12,
	PLAYER_STATE_ROCKET_JUMP = 13,
	PLAYER_STATE_DOUBLE_JUMP = 14,
	PLAYER_STATE_HELI_JUMP = 15,
	PLAYER_STATE_CHARGE_JUMP = 16,
	PLAYER_STATE_WALL_JUMP = 17,
	PLAYER_STATE_WATER_JUMP = 18,
	PLAYER_STATE_COMBO_ATTACK = 19,
	PLAYER_STATE_JUMP_ATTACK = 20,
	PLAYER_STATE_THROW_ATTACK = 21,
	PLAYER_STATE_GET_HIT = 22,
	PLAYER_STATE_LEDGE_GRAB = 23,
	PLAYER_STATE_LEDGE_IDLE = 24,
	PLAYER_STATE_LEDGE_TRAVERSE_LEFT = 25,
	PLAYER_STATE_LEDGE_TRAVERSE_RIGHT = 26,
	PLAYER_STATE_LEDGE_JUMP = 27,
	PLAYER_STATE_VISIBOMB = 28,
	PLAYER_STATE_TARGETING = 29,
	PLAYER_STATE_GUN_WAITING = 30,
	PLAYER_STATE_WALLOPER_ATTACK = 31,
	PLAYER_STATE_ATTACK_BOUNCE = 32,
	PLAYER_STATE_ROCKET_STOMP = 33,
	PLAYER_STATE_GLOVE_ATTACK = 34,
	PLAYER_STATE_GRAPPLE_SHOOT = 35,
	PLAYER_STATE_GRAPPLE_PULL = 36,
	PLAYER_STATE_GRAPPLE_PULL_VEHICLE = 37,
	PLAYER_STATE_SUCK_CANNON = 38,
	PLAYER_STATE_GRIND = 39,
	PLAYER_STATE_GRIND_JUMP = 40,
	PLAYER_STATE_GRIND_SWITCH_JUMP = 41,
	PLAYER_STATE_GRIND_ATTACK = 42,
	PLAYER_STATE_SWING = 43,
	PLAYER_STATE_SWING_FALL = 44,
	PLAYER_STATE_RECOIL = 45,
	PLAYER_STATE_ICE_WALK = 46,
	PLAYER_STATE_DEVASTATOR = 47,
	PLAYER_STATE_SLIDE = 48,
	PLAYER_STATE_VEHICLE = 49,
	PLAYER_STATE_SWIMUNDER = 50,
	PLAYER_STATE_IDLEUNDER = 51,
	PLAYER_STATE_CHARGEUNDER = 52,
	PLAYER_STATE_SWIMSURF = 53,
	PLAYER_STATE_IDLESURF = 54,
	PLAYER_STATE_BOLT_CRANK = 55,
	PLAYER_STATE_LAVA_JUMP = 56,
	PLAYER_STATE_DEATH = 57,
	PLAYER_STATE_BOARD = 58,
	PLAYER_STATE_MAGNE_WALK = 59,
	PLAYER_STATE_GRIND_HIT = 62,
	PLAYER_STATE_GRIND_JUMP_TURN = 63,
	PLAYER_STATE_VENDOR_BOOTH = 98,
	PLAYER_STATE_NPC = 99,
	PLAYER_STATE_WALK_TO_POS = 100,
	PLAYER_STATE_SKID_TO_POS = 101,
	PLAYER_STATE_IDLE_TO_POS = 102,
	PLAYER_STATE_JUMP_TO_POS = 103,
	PLAYER_STATE_QUICKSAND_SINK = 104,
	PLAYER_STATE_QUICKSAND_JUMP = 105,
	PLAYER_STATE_DROWN = 106,
	PLAYER_STATE_MAGNE_ATTACK = 111,
	PLAYER_STATE_MAGNE_JUMP = 112,
	PLAYER_STATE_CUT_SCENE = 113,
	PLAYER_STATE_WADE = 114,
	PLAYER_STATE_ZIP = 115,
	PLAYER_STATE_GET_HIT_SURF = 116,
	PLAYER_STATE_GET_HIT_UNDER = 117,
	PLAYER_STATE_DEATH_FALL = 118,
	PLAYER_STATE_SLOPESLIDE = 120,
	PLAYER_STATE_JUMP_BOUNCE = 121,
	PLAYER_STATE_DEATHSAND_SINK = 122,
	PLAYER_STATE_LAVA_DEATH = 123,
	PLAYER_STATE_CHARGE = 125,
	PLAYER_STATE_ICEWATER_FREEZE = 126,
	PLAYER_STATE_ELECTRIC_DEATH = 127,
	PLAYER_STATE_ROCKET_HOVER = 128,
	PLAYER_STATE_ELECTRIC_DEATH_UNDER = 129,
	PLAYER_STATE_SKATE = 130,
	PLAYER_STATE_MOON_JUMP = 131,
	PLAYER_STATE_JET = 132,
	PLAYER_STATE_THROW_SHURIKEN = 133,
	PLAYER_STATE_RACEBIKE = 134,
	PLAYER_STATE_SPEEDBOAT = 135,
	PLAYER_STATE_HOVERPLANE = 136,
	PLAYER_STATE_LATCH_GRAB = 137,
	PLAYER_STATE_LATCH_IDLE = 138,
	PLAYER_STATE_LATCH_JUMP = 139,
	PLAYER_STATE_PULLSHOT_ATTACH = 140,
	PLAYER_STATE_PULLSHOT_PULL = 141,
	PLAYER_STATE_GET_FLATTENED = 142,
	PLAYER_STATE_SKYDIVE = 143,
	PLAYER_STATE_ELECTRIC_GET_HIT = 144,
	PLAYER_STATE_FLAIL_ATTACK = 145,
	PLAYER_STATE_MAGIC_TELEPORT = 146,
	PLAYER_STATE_TELEPORT_IN = 147,
	PLAYER_STATE_DEATH_NO_FALL = 148,
	PLAYER_STATE_TAUNT_SQUAT = 149,
	PLAYER_STATE_TAUNT_ASSPOINT = 150,
	PLAYER_STATE_TAUNT_ASSRUB = 151,
	PLAYER_STATE_TURRET_DRIVER = 152,
	PLAYER_STATE_WAIT_FOR_RESURRECT = 153,
	PLAYER_STATE_WAIT_FOR_JOIN = 154,
	PLAYER_STATE_DROPPED = 155,
	PLAYER_STATE_CNT = 156
};

typedef enum PLAYER_TYPE_ENUM {
	PLAYER_TYPE_IDLE = 0,
	PLAYER_TYPE_WALK = 1,
	PLAYER_TYPE_FALL = 2,
	PLAYER_TYPE_LEDGE = 3,
	PLAYER_TYPE_JUMP = 4,
	PLAYER_TYPE_GLIDE = 5,
	PLAYER_TYPE_ATTACK = 6,
	PLAYER_TYPE_GET_HIT = 7,
	PLAYER_TYPE_SHOOT = 8,
	PLAYER_TYPE_BUSY = 9,
	PLAYER_TYPE_BOUNCE = 10,
	PLAYER_TYPE_STOMP = 11,
	PLAYER_TYPE_CROUCH = 12,
	PLAYER_TYPE_GRAPPLE = 13,
	PLAYER_TYPE_SWING = 14,
	PLAYER_TYPE_GRIND = 15,
	PLAYER_TYPE_SLIDE = 16,
	PLAYER_TYPE_SWIM = 17,
	PLAYER_TYPE_SURF = 18,
	PLAYER_TYPE_HYDRO = 19,
	PLAYER_TYPE_DEATH = 20,
	PLAYER_TYPE_BOARD = 21,
	PLAYER_TYPE_RACEBOARD = 22,
	PLAYER_TYPE_SPIN = 23,
	PLAYER_TYPE_NPC = 24,
	PLAYER_TYPE_QUICKSAND = 25,
	PLAYER_TYPE_ZIP = 26,
	PLAYER_TYPE_HOLO = 27,
	PLAYER_TYPE_CHARGE = 28,
	PLAYER_TYPE_ROCKET_HOVER = 29,
	PLAYER_TYPE_JET = 30,
	PLAYER_TYPE_RACEBIKE = 31,
	PLAYER_TYPE_SPEEDBOAT = 32,
	PLAYER_TYPE_PULL = 33,
	PLAYER_TYPE_LATCH = 34,
	PLAYER_TYPE_LADDER = 36,
	PLAYER_TYPE_SKYDIVE = 37,
	PLAYER_TYPE_CNT = 38
} PLAYER_TYPE_ENUM;

typedef struct tNW_GetHitMessage { // 0x10
	/* 0x0 */ vec3 momentum;
	/* 0xc */ unsigned char sequenceNum;
	/* 0xd */ signed char hitPlayerIndex;
	/* 0xe */ signed char frame;
} tNW_GetHitMessage_t;

struct tNW_PlayerStateMessage { // 0x1c
	/* 0x00 */ char netPlayerIndex;
	/* 0x01 */ char newState;
	/* 0x02 */ char seqNum;
	/* 0x03 */ char frame;
	/* 0x04 */ vec3 pos;
	/* 0x10 */ vec3 rot;
};

struct tNW_PlayerWarpMessage { // 0x20
	/* 0x00 */ char netPlayerIndex;
	/* 0x01 */ char dontKillMeInBaseHack;
	/* 0x02 */ char resetPadRing;
	/* 0x03 */ char playerSeq;
	/* 0x04 */ vec3 playerPos;
	/* 0x10 */ vec3 playerRot;
	/* 0x1c */ short int state;
	/* 0x1e */ char isResurrecting;
} tNW_PlayerWarpMessage_t;

typedef struct tNW_PlayerPadInputMessage { // 0x98
	/* 0x00 */ int cameraRot[4];
	/* 0x10 */ short unsigned int playerPos[3];
	/* 0x16 */ unsigned char sequenceNum;
	/* 0x17:0 */ unsigned char stateAndRotFlag : 1;
	/* 0x17:1 */ unsigned char playerIndex : 1;
	/* 0x17:2 */ unsigned char flags : 2;
	/* 0x17:4 */ unsigned char framesWithButtonDiffs : 4;
	/* 0x18 */ unsigned char pad_data[128];
} tNW_PlayerPadInputMessage_t;

typedef struct tNW_PlayerData { // 0xc0
	/* 0x00 */ VECTOR vPosition;
	/* 0x10 */ vec3 vRotation;
	/* 0x1c */ int timeStamp;
	/* 0x20 */ VECTOR vIdealVec;
	/* 0x30 */ int idealVecTime;
	/* 0x34 */ int accountId;
	/* 0x38 */ unsigned int UID;
	/* 0x3c */ int playerType;
	/* 0x40 */ int playerTeam;
	/* 0x44 */ float hitPoints;
	/* 0x48 */ int handGadget;
	/* 0x4c */ int lastKeepAlive;
	/* 0x50 */ int remoteTarget;
	/* 0x54 */ int playerIndex;
	/* 0x58 */ int cameraElevationSettings[3];
	/* 0x64 */ int cameraAzimuthSettings[3];
	/* 0x70 */ int cameraRotationSettings[3];
	/* 0x7c */ int rank[6];
	/* 0x94 */ char cGadgetLevel[32];
	/* 0xb4 */ unsigned int updated;
	/* 0xb8 */ short unsigned int gadgetsWithAmmo;
	/* 0xba */ short unsigned int fpsMode;
	/* 0xbc */ unsigned char flags;
} tNW_PlayerData_t;

typedef struct tNW_PlayerPadInputMessageListElem { // 0xa4
	/* 0x00 */ struct tNW_PlayerPadInputMessage msg;
	/* 0x98 */ struct tNW_PlayerPadInputMessageListElem *pNext;
	/* 0x9c */ struct tNW_PlayerPadInputMessageListElem *pPrev;
	/* 0xa0 */ bool inUse;
} tNW_PlayerPadInputMessageListElem_t;

typedef struct tNW_Player { // 0xad0
	/* 0x000 */ int netClientIndex;
	/* 0x004 */ tNW_PlayerData_t *pNetPlayerData;
	/* 0x008 */ short int bLocal;
	/* 0x00a */ short int bSpawned;
	/* 0x00c */ short int bGiveMeTheDasBoot;
	/* 0x00e */ short int bCallbackCalled;
	/* 0x010 */ int latency;
	/* 0x014 */ unsigned int flags;
	/* 0x018 */ char accountName[32];
	/* 0x038 */ struct tNW_PlayerWarpMessage warpMessage;
	/* 0x058 */ struct tNW_PlayerPadInputMessageListElem padMessageElems[16];
	/* 0xa98 */ char padMessageCurDecodePos;
	/* 0xa99 */ char activePadFrame;
	/* 0xa9c */ int lastActiveSeqNum;
	/* 0xaa0 */ int numBufferedPadMessageElems;
	/* 0xaa4 */ int receivedActivePadMsgFrame;
	/* 0xaa8 */ char pullBack;
	/* 0xaa9 */ signed char jitterThrottleFrames;
	/* 0xaaa */ char numConseqSkips;
	/* 0xaac */ struct tNW_PlayerPadInputMessageListElem *pActivePadMsg;
	/* 0xab0 */ struct tNW_PlayerPadInputMessageListElem *pPadMsgListTail;
	/* 0xab4 */ unsigned char padFrame[20];
	/* 0xac8 */ int homeBaseIndex;
	/* 0xacc */ int homeNodeIndex;
} tNW_Player_t;

struct HeroMove { // 0xa0
	/* 0x00 */ VECTOR behavior;
	/* 0x10 */ VECTOR external;
	/* 0x20 */ VECTOR actual;
	/* 0x30 */ VECTOR actualFromBehavior;
	/* 0x40 */ VECTOR actualFromBehaviorGrav;
	/* 0x50 */ VECTOR actualFromBehavior2D;
	/* 0x60 */ VECTOR actualFromExternal;
	/* 0x70 */ VECTOR taper;
	/* 0x80 */ float speed;
	/* 0x84 */ float speed2D;
	/* 0x88 */ float forwardSpeed;
	/* 0x8c */ float ascent;
	/* 0x90 */ float zSpeed;
	/* 0x94 */ float externalSpeed;
	/* 0x98 */ int pad[2];
};

struct HeroTimers { // 0xb4
	/* 0x00 */ int state;
	/* 0x04 */ int stateType;
	/* 0x08 */ int subState;
	/* 0x0c */ int animState;
	/* 0x10 */ int stickOn;
	/* 0x14 */ int stickOff;
	/* 0x18 */ short int noLedge;
	/* 0x1a */ short int allowQuickSelect;
	/* 0x1c */ int firing;
	/* 0x20 */ int moveModifierTimer;
	/* 0x24 */ int boltMultTimer;
	/* 0x28 */ int wallJumpOk;
	/* 0x2c */ short int postHitInvinc;
	/* 0x2e */ short int ignoreHeroColl;
	/* 0x30 */ short int collOff;
	/* 0x32 */ short int invisible;
	/* 0x34 */ short int slide;
	/* 0x36 */ short int bezerker;
	/* 0x38 */ short int noWallJump;
	/* 0x3a */ short int noJumps;
	/* 0x3c */ short int boxBreaking;
	/* 0x3e */ short int noMag;
	/* 0x40 */ short int noChargeJump;
	/* 0x42 */ short int resurrectWait;
	/* 0x44 */ int timeSinceStrafe;
	/* 0x48 */ short int noHackerSwitch;
	/* 0x4a */ short int noInput;
	/* 0x4c */ short int noJumpLookBack;
	/* 0x4e */ short int noShockAbort;
	/* 0x50 */ short int stuck;
	/* 0x52 */ short int noSwing;
	/* 0x54 */ short int noWaterJump;
	/* 0x56 */ short int noWaterDive;
	/* 0x58 */ short int facialExpression;
	/* 0x5a */ short int idle;
	/* 0x5c */ short int bumpPushing;
	/* 0x5e */ short int lookButton;
	/* 0x60 */ short int edgeStop;
	/* 0x62 */ short int clankRedEye;
	/* 0x64 */ short int edgePath;
	/* 0x66 */ short int magSlope;
	/* 0x68 */ short int ledgeCamAdj;
	/* 0x6a */ short int screenFlashRed;
	/* 0x6c */ short int holdDeathPose;
	/* 0x6e */ short int strafeMove;
	/* 0x70 */ short int noRaisedGunArm;
	/* 0x72 */ short int noExternalRot;
	/* 0x74 */ short int screenFlashOn;
	/* 0x76 */ short int screenFadeOn;
	/* 0x78 */ int lastVehicleTimer;
	/* 0x7c */ float gadgetRefire;
	/* 0x80 */ int timeAlive;
	/* 0x84 */ int noFpsCamTimer;
	/* 0x88 */ int endDeathEarly;
	/* 0x8c */ short int forceGlide;
	/* 0x8e */ short int noGrind;
	/* 0x90 */ short int instaGrind;
	/* 0x92 */ short int noCamInputTimer;
	/* 0x94 */ short int postTeleportTimer;
	/* 0x96 */ short int multiKillTimer;
	/* 0x98 */ short int armorLevelTimer;
	/* 0x9a */ short int damageMuliplierTimer;
	/* 0x9c */ int powerupEffectTimer;
	/* 0xa0 */ short int juggernautFadeTimer;
	/* 0xa2 */ short int onFireTimer;
	/* 0xa4 */ short int acidTimer;
	/* 0xa6 */ short int freezeTimer;
	/* 0xa8 */ short int noHelmTimer;
	/* 0xaa */ short int elecTimer;
	/* 0xac */ short int boltDistMulTimer;
	/* 0xae */ short int explodeTimer;
	/* 0xb0 */ short int noDeathTimer;
	/* 0xb2 */ short int invincibilityTimer;
};

struct HeroColl { // 0x80
	/* 0x00 */ VECTOR normal;
	/* 0x10 */ VECTOR ip;
	/* 0x20 */ float top;
	/* 0x24 */ float bot;
	/* 0x28 */ float ideal_top;
	/* 0x2c */ float ideal_bot;
	/* 0x30 */ float idealRadius;
	/* 0x34 */ float radius;
	/* 0x38 */ float radiusSpeed;
	/* 0x3c */ Moby *pContactMoby;
	/* 0x40 */ Moby *pBumpMoby;
	/* 0x44 */ float bumpPushSpeed;
	/* 0x48 */ float distToWall;
	/* 0x4c */ float wallAng;
	/* 0x50 */ float wallSlope;
	/* 0x54 */ char wallIsCrate;
	/* 0x55 */ char wallIsMoby;
	/* 0x56 */ char contact;
	/* 0x57 */ char cpad;
	/* 0x58 */ float ledgeHeight;
	/* 0x5c */ float ledgeDist;
	/* 0x60 */ int atLedge;
	/* 0x64 */ Moby *pWallJumpMoby;
	/* 0x68 */ int pad[2];
	/* 0x70 */ float radiusSqd;
};

struct HeroGround { // 0xc0
	/* 0x00 */ VECTOR normal;
	/* 0x10 */ VECTOR waterNormal;
	/* 0x20 */ VECTOR gravity;
	/* 0x30 */ VECTOR point;
	/* 0x40 */ VECTOR lastGoodPos;
	/* 0x50 */ VECTOR externalBootGrav;
	/* 0x60 */ float feetHeights[2];
	/* 0x68 */ float pitchSlopes[2];
	/* 0x70 */ float rollSlopes[2];
	/* 0x78 */ float height;
	/* 0x7c */ float dist;
	/* 0x80 */ float slope;
	/* 0x84 */ float pitchSlope;
	/* 0x88 */ float rollSlope;
	/* 0x8c */ float angz;
	/* 0x90 */ float waterHeight;
	/* 0x94 */ float quicksandHeight;
	/* 0x98 */ int underWater;
	/* 0x9c */ Moby *pMoby;
	/* 0xa0 */ int onGood;
	/* 0xa4 */ float speed;
	/* 0xa8 */ short int magnetic;
	/* 0xaa */ short int stickLanding;
	/* 0xac */ short int offAny;
	/* 0xae */ short int offGood;
	/* 0xb0 */ int oscillating;
	/* 0xb4 */ float oscPos1;
	/* 0xb8 */ float oscPos2;
	/* 0xbc */ int pad[1];
};

struct HeroTrack { // 0x60
	/* 0x00 */ VECTOR idealPos;
	/* 0x10 */ VECTOR idealRot;
	/* 0x20 */ VECTOR idealWallPos;
	/* 0x30 */ VECTOR idealWallRot;
	/* 0x40 */ VECTOR prevVel;
	/* 0x50 */ Moby *pMoby;
	/* 0x54 */ int flags;
	/* 0x58 */ int pad[2];
};

struct HeroAnim { // 0x20
	/* 0x00 */ float speed;
	/* 0x04 */ int iscale;
	/* 0x08 */ int flags;
	/* 0x0c */ int interping;
	/* 0x10 */ int env_index;
	/* 0x14 */ int env_time;
	/* 0x18 */ float mayaFrm;
	/* 0x1c */ float mayaFrmDelt;
};

struct HeroJoints { // 0x180
	/* 0x000 */ mtx4 gadgetMtxs[6];
};

struct HeroAnimLayers { // 0x34
	/* 0x00 */ struct MobyAnimLayer *pArmBlenders[2];
	/* 0x08 */ struct MobyAnimLayer *pFiringBlenders[2];
	/* 0x10 */ struct MobyAnimLayer *pHeadBlender;
	/* 0x14 */ int detachingFiring;
	/* 0x18 */ int armBlenderSharesIdle;
	/* 0x1c */ int gadgetAttachedId;
	/* 0x20 */ int usingRunAnim[4];
	/* 0x30 */ int headAnim;
};

struct HeroTweaker { // 0xb0
	/* 0x00 */ struct Manipulator manip;
	/* 0x40 */ VECTOR rot;
	/* 0x50 */ VECTOR speed;
	/* 0x60 */ VECTOR target;
	/* 0x70 */ VECTOR trans;
	/* 0x80 */ VECTOR transSpeed;
	/* 0x90 */ VECTOR transTarget;
	/* 0xa0 */ short int joint;
	/* 0xa2 */ short int whichMoby;
	/* 0xa4 */ float gain;
	/* 0xa8 */ float damp;
	/* 0xac */ float scale;
};

struct FpsCamVars { // 0x160
	/* 0x000 */ mtx3 mtx;
	/* 0x030 */ VECTOR pos;
	/* 0x040 */ float z_rot;
	/* 0x044 */ float z_speed_current;
	/* 0x048 */ float z_speed_max_quick;
	/* 0x04c */ float z_speed_max_aim;
	/* 0x050 */ float z_accel_quick;
	/* 0x054 */ float z_accel_aim;
	/* 0x058 */ float z_target_slowness_factor_quick;
	/* 0x05c */ float z_target_slowness_factor_aim;
	/* 0x060 */ float y_rot;
	/* 0x064 */ float y_speed_current;
	/* 0x068 */ float y_speed_max;
	/* 0x06c */ float y_accel;
	/* 0x070 */ float y_target_slowness_factor;
	/* 0x074 */ float strafe_turn_factor;
	/* 0x078 */ float strafe_tilt_factor;
	/* 0x07c */ float max_target_angle;
	/* 0x080 */ int state;
	/* 0x084 */ short int quick_turn_input_time;
	/* 0x086 */ short int snap_hold_time;
	/* 0x088 */ float snap_input;
	/* 0x08c */ Moby *pTarget;
	/* 0x090 */ VECTOR target_last_pos;
	/* 0x0a0 */ VECTOR target_vel;
	/* 0x0b0 */ float target_blend_fac;
	/* 0x0b4 */ float max_y_rot;
	/* 0x0b8 */ float min_y_rot;
	/* 0x0bc */ Moby *pExcludeMoby;
	/* 0x0c0 */ VECTOR ext_pos_ofs;
	/* 0x0d0 */ VECTOR ext_rot_ofs;
	/* 0x0e0 */ short int flags;
	/* 0x0e2 */ short int allegiance;
	/* 0x0e4 */ void *special_target_func;
	/* 0x0e8 */ mtx3 *pWorldMtx;
	/* 0x0ec */ mtx3 *pWorldInvMtx;
	/* 0x0f0 */ VECTOR facing_dir;
	/* 0x100 */ VECTOR internal_facing_dir;
	/* 0x110 */ VECTOR aim_pos;
	/* 0x120 */ float range;
	/* 0x124 */ float ext_extension;
	/* 0x128 */ float ext_entension_speed;
	/* 0x12c */ int cam_slot;
	/* 0x130 */ void *pHero;
	/* 0x134 */ float camRadius;
	/* 0x138 */ int camSettingsIndex;
	/* 0x13c */ int karma_pad;
	/* 0x140 */ VECTOR prevCamPos;
	/* 0x150 */ int karma_pad2[4];
};

struct HeroFps { // 0x240
	/* 0x000 */ mtx3 worldMtx;
	/* 0x030 */ mtx3 worldInvMtx;
	/* 0x060 */ VECTOR gunFPSQuat;
	/* 0x070 */ VECTOR camEffVel;
	/* 0x080 */ VECTOR camPos;
	/* 0x090 */ VECTOR camDir;
	/* 0x0a0 */ struct FpsCamVars fVars;
	/* 0x200 */ float camYSpeed;
	/* 0x204 */ float camZSpeed;
	/* 0x208 */ float gunInterp;
	/* 0x20c */ float gunInterpSpeed;
	/* 0x210 */ int active;
	/* 0x214 */ float gunWithdrawSpeed;
	/* 0x218 */ float gunWithdrawDist;
	/* 0x21c */ float gunWithdrawIdeal;
	/* 0x220 */ float bobRot;
	/* 0x224 */ float bobRotSpeed;
	/* 0x228 */ float bobAmp;
	/* 0x22c */ float camHeroOfs;
	/* 0x230 */ float camHeroOfsSpeed;
	/* 0x234 */ int ignoreGroundHeight;
	/* 0x238 */ float reticulePulseAng;
	/* 0x23c */ int reticuleFadeInTimer;
};

struct HeroWeaponPosRec { // 0x100
	/* 0x00 */ mtx4 fpGunMtx[2];
	/* 0x80 */ mtx4 tpGunMtx[2];
};

struct HeroWalkToPos { // 0x30
	/* 0x00 */ VECTOR idealPos;
	/* 0x10 */ VECTOR idealRot;
	/* 0x20 */ int abortOnArrival;
	/* 0x24 */ int walkToTeleport;
	/* 0x28 */ int teleportWaitTime;
	/* 0x2c */ Moby *pTeleTarget;
};

struct HeroSpecialIdleDef { // 0x10
	/* 0x0 */ int anim;
	/* 0x4 */ float frequency;
	/* 0x8 */ float minRepeatTime;
	/* 0xc */ int repeatTimer;
};

struct HeroSurf { // 0x30
	/* 0x00 */ float sinkDepth;
	/* 0x04 */ float sinkRate;
	/* 0x08 */ int minSwimTimer;
	/* 0x0c */ float surfHeight;
	/* 0x10 */ float surfHeightSpeed;
	/* 0x14 */ Moby *pIceCube;
	/* 0x18 */ float bobt;
	/* 0x1c */ float bobz;
	/* 0x20 */ float swingAng1;
	/* 0x24 */ float swingAng2;
	/* 0x28 */ int pad[2];
};

struct HeroSwim { // 0x50
	/* 0x00 */ VECTOR padWindUp;
	/* 0x10 */ int diveTime;
	/* 0x14 */ float bankSpeed;
	/* 0x18 */ float pitchSpeed;
	/* 0x1c */ float yawSpeed;
	/* 0x20 */ int bubbleTimer;
	/* 0x24 */ int minSwimTimer;
	/* 0x28 */ short int chargeBubbleTimer;
	/* 0x2a */ short int soundTimer;
	/* 0x2c */ float buoyancySpeed;
	/* 0x30 */ short int padUpTime;
	/* 0x32 */ short int padDownTime;
	/* 0x34 */ short int ring_timer;
	/* 0x36 */ short int drop_timer;
	/* 0x38 */ short int wake_timer;
	/* 0x3a */ short int plunge_bubbles;
	/* 0x3c */ short int solidRiseTimer;
	/* 0x3e */ short int riseTimer;
	/* 0x40 */ int riseTapCnt;
	/* 0x44 */ int timeRiseLastPressed;
	/* 0x48 */ int pad[2];
};

struct HeroGrind { // 0x100
	/* 0x00 */ VECTOR closestPoint;
	/* 0x10 */ VECTOR rootPos;
	/* 0x20 */ VECTOR lHandPos;
	/* 0x30 */ VECTOR rHandPos;
	/* 0x40 */ VECTOR closestPointSwitch;
	/* 0x50 */ VECTOR rampTarget;
	/* 0x60 */ struct Path *pPath;
	/* 0x64 */ int curNode;
	/* 0x68 */ float curSegLen;
	/* 0x6c */ int valid;
	/* 0x70 */ int EOPtime;
	/* 0x74 */ float speed;
	/* 0x78 */ int pathDir;
	/* 0x7c */ float ang;
	/* 0x80 */ float slope;
	/* 0x84 */ int wrap;
	/* 0x88 */ float heroAngOfs;
	/* 0x8c */ int animDir;
	/* 0x90 */ int switching;
	/* 0x94 */ struct Path *pSwitchPath;
	/* 0x98 */ int switchCurNode;
	/* 0x9c */ float switchCurSegLen;
	/* 0xa0 */ int switchWrap;
	/* 0xa4 */ float slopeSpeed;
	/* 0xa8 */ int switchTime;
	/* 0xac */ int leanDir;
	/* 0xb0 */ float userSpeed;
	/* 0xb4 */ int grappleTrigger;
	/* 0xb8 */ int onRamp;
	/* 0xbc */ short int rampTrigger;
	/* 0xbe */ short int damage;
	/* 0xc0 */ int rampJumpQueued;
	/* 0xc4 */ int useRampJumpTarget;
	/* 0xc8 */ float rampJumpGravity;
	/* 0xcc */ float getHitSpeed;
	/* 0xd0 */ float aimDirOfs;
	/* 0xd4 */ float aimDirSpeed;
	/* 0xd8 */ Moby *pTarget;
	/* 0xdc */ float centeringSpeed;
	/* 0xe0 */ float twirlRot;
	/* 0xe4 */ float twirlRotSpeed;
	/* 0xe8 */ float twirlCamRotz;
	/* 0xec */ short int twirlTimer;
	/* 0xee */ short int twirlCamOn;
	/* 0xf0 */ float twirlCamRotZspeed;
	/* 0xf4 */ struct COLL_DAM_OUT *cdo;
	/* 0xf8 */ int noGroundTime;
	/* 0xfc */ short int turnDir;
	/* 0xfe */ short int pad;
};

struct HeroShadow { // 0x28
	/* 0x00 */ float slope;
	/* 0x04 */ float plane;
	/* 0x08 */ float range;
	/* 0x0c */ int sample_id;
	/* 0x10 */ int pad[2];
	/* 0x18 */ float sample_pos[4];
};

struct HeroEyes { // 0x2d0
	/* 0x000 */ struct Manipulator manips[7];
	/* 0x1c0 */ struct Manipulator clankpackManips[4];
	/* 0x2c0 */ int blink_timer;
	/* 0x2c4 */ int blink_next;
	/* 0x2c8 */ int blink_frequency;
	/* 0x2cc */ short int clankBlinkCountdown;
	/* 0x2ce */ short int clankBlinkTime;
};

struct HeroNPJumpThrustStage { // 0x10
	/* 0x0 */ float initThrust;
	/* 0x4 */ float thrustDelta;
	/* 0x8 */ int time;
	/* 0xc */ int pad;
};

struct HeroJumpNonParab { // 0x30
	/* 0x00 */ int startThrustTime;
	/* 0x04 */ int endThrustTime;
	/* 0x08 */ float thrustStartFrm;
	/* 0x0c */ float peakFrm;
	/* 0x10 */ int timeToPeakFrm;
	/* 0x14 */ struct HeroNPJumpThrustStage *thrustTable;
	/* 0x18 */ int thrustStageIndex;
	/* 0x1c */ int thrustStageTimer;
	/* 0x20 */ float thrust;
	/* 0x24 */ float chargeJumpThrust;
	/* 0x28 */ float descendGravity;
	/* 0x2c */ int pad;
};

struct HeroJump { // 0x100
	/* 0x00 */ struct HeroJumpNonParab nonParab;
	/* 0x30 */ VECTOR takeoffPos;
	/* 0x40 */ VECTOR snapJumpThrustVec;
	/* 0x50 */ VECTOR snapJumpForwardVec;
	/* 0x60 */ float camHeight;
	/* 0x64 */ float turnSpeed;
	/* 0x68 */ float wallJumpXySpeed;
	/* 0x6c */ char land_timer;
	/* 0x6d */ char useNonParabAscent;
	/* 0x6e */ char descend;
	/* 0x6f */ char noGlide;
	/* 0x70 */ float maxFallSpeed;
	/* 0x74 */ float maxXySpeed;
	/* 0x78 */ float ideal_height;
	/* 0x7c */ short int pushOffTime;
	/* 0x7e */ short int framesToLand;
	/* 0x80 */ float up_thrust;
	/* 0x84 */ float up_thrust_total;
	/* 0x88 */ float coll_bot;
	/* 0x8c */ float ledgeJumpSpeed;
	/* 0x90 */ float snapJumpThrustAng;
	/* 0x94 */ float snapJumpForwardAng;
	/* 0x98 */ float peakFrm;
	/* 0x9c */ float landFrm;
	/* 0xa0 */ float gameLandFrm;
	/* 0xa4 */ int snapJumpDir;
	/* 0xa8 */ float snapJumpRunThrust;
	/* 0xac */ float snapJumpSpeed;
	/* 0xb0 */ VECTOR wallJumpDir;
	/* 0xc0 */ VECTOR wallJumpDirCur;
	/* 0xd0 */ float accel;
	/* 0xd4 */ float decel;
	/* 0xd8 */ float minHeight;
	/* 0xdc */ float maxHeight;
	/* 0xe0 */ float fallThresh;
	/* 0xe4 */ float animMayaScale;
	/* 0xe8 */ short int maxUpTime;
	/* 0xea */ short int bailoutSafetyTime;
	/* 0xec */ short int particleTimer;
	/* 0xee */ short int particleTimer2;
	/* 0xf0 */ float gravity;
	/* 0xf4 */ short int minForwardThrust;
	/* 0xf6 */ short int minTimeToGlide;
	/* 0xf8 */ short int onIce;
	/* 0xfa */ short int minTimeToFall;
	/* 0xfc */ char gloveAttackOk;
	/* 0xfd */ char strafingFlip;
	/* 0xfe */ char flipJumpOk;
	/* 0xff */ char doubleJumpOk;
};

struct HeroLockOn { // 0x50
	/* 0x00 */ VECTOR strafeIdealVec;
	/* 0x10 */ Moby *pMoby;
	/* 0x14 */ short int strafing;
	/* 0x16 */ char strafingBack;
	/* 0x17 */ char strafingDir;
	/* 0x18 */ float strafeRot;
	/* 0x1c */ float strafeRotSpeed;
	/* 0x20 */ float backSpeed;
	/* 0x24 */ int strafeRotTimer;
	/* 0x28 */ short int strafeLeftDampTimer;
	/* 0x2a */ short int strafeRightDampTimer;
	/* 0x2c */ int strafeTurnDiffZero;
	/* 0x30 */ VECTOR curRetPos;
	/* 0x40 */ Moby *curRetMoby;
	/* 0x44 */ float fadeInterp;
	/* 0x48 */ float retRot;
	/* 0x4c */ float strafeTurnDiff;
};

struct HeroFireDir { // 0x50
	/* 0x00 */ mtx3 m;
	/* 0x30 */ VECTOR v;
	/* 0x40 */ VECTOR rot;
};

struct HeroZip { // 0x50
	/* 0x00 */ VECTOR closestPoint;
	/* 0x10 */ VECTOR idealVec;
	/* 0x20 */ Path_t *pPath;
	/* 0x24 */ int curNode;
	/* 0x28 */ float curSegLen;
	/* 0x2c */ int valid;
	/* 0x30 */ int EOPtime;
	/* 0x34 */ float speed;
	/* 0x38 */ int pathDir;
	/* 0x3c */ int wrap;
	/* 0x40 */ float ang;
	/* 0x44 */ float slope;
	/* 0x48 */ float centeringSpeed;
	/* 0x4c */ int pad[1];
};

struct HeroThrust { // 0x10
	/* 0x0 */ float ideal;
	/* 0x4 */ float actual;
	/* 0x8 */ int pad[2];
};

struct HeroTurn { // 0x20
	/* 0x00 */ VECTOR idealVec;
	/* 0x10 */ float ideal;
	/* 0x14 */ float speed;
	/* 0x18 */ float diff;
	/* 0x1c */ int pad;
};

struct HeroWalk { // 0x30
	/* 0x00 */ VECTOR idealTurnVec;
	/* 0x10 */ float iceMotionDotProduct;
	/* 0x14 */ float lastGroundSlope;
	/* 0x18 */ float idealTurnAng;
	/* 0x1c */ char ideal_motion;
	/* 0x1d */ char skateThrust;
	/* 0x1e */ char long_trans;
	/* 0x1f */ char qturning;
	/* 0x20 */ int idealAngSet;
	/* 0x24 */ int pad[3];
};

struct HeroAttack { // 0xb0
	/* 0x00 */ VECTOR near;
	/* 0x10 */ VECTOR far;
	/* 0x20 */ VECTOR oldNear;
	/* 0x30 */ VECTOR oldFar;
	/* 0x40 */ VECTOR wrenchHandle;
	/* 0x50 */ VECTOR wrenchTip;
	/* 0x60 */ VECTOR idealVec;
	/* 0x70 */ VECTOR bounceVec;
	/* 0x80 */ Moby *pTarget;
	/* 0x84 */ Moby *pMoby;
	/* 0x88 */ int rotSet;
	/* 0x8c */ float rot;
	/* 0x90 */ float bounceAng;
	/* 0x94 */ float speedFactor;
	/* 0x98 */ Moby *pGunPointMoby;
	/* 0x9c */ short int id;
	/* 0x9e */ short int soundPlayed;
	/* 0xa0 */ float descend;
	/* 0xa4 */ float aimAngz;
	/* 0xa8 */ float aimAngy;
	/* 0xac */ int throwAttackDamageID;
};

struct HeroAttackDef { // 0x2c
	/* 0x00 */ int type;
	/* 0x04 */ int stage;
	/* 0x08 */ int endComboFrm;
	/* 0x0c */ int inputFrm;
	/* 0x10 */ int transFrm;
	/* 0x14 */ int jumpTransFrm;
	/* 0x18 */ int etcTransFrm;
	/* 0x1c */ int startDamFrm;
	/* 0x20 */ int stopDamFrm;
	/* 0x24 */ int startBlurFrm;
	/* 0x28 */ int stopBlurFrm;
};

struct HeroMobys { // 0x10
	/* 0x0 */ Moby *ground;
	/* 0x4 */ Moby *hero;
	/* 0x8 */ int pad[2];
};

struct HeroCharge { // 0x20
	/* 0x00 */ VECTOR padWindUp;
	/* 0x10 */ float groundSpeed;
	/* 0x14 */ int hitEdge;
	/* 0x18 */ int pad[2];
};

struct HeroHotspots { // 0x10
	/* 0x0 */ short int index;
	/* 0x2 */ char ice;
	/* 0x3 */ char magictele;
	/* 0x4 */ char water;
	/* 0x5 */ char lava;
	/* 0x6 */ char quicksand;
	/* 0x7 */ char magnetic;
	/* 0x8 */ char noStand;
	/* 0x9 */ char deathsand;
	/* 0xa */ char icewater;
	/* 0xb */ char groundType;
	/* 0xc */ int pad;
};

struct HeroWind { // 0x20
	/* 0x00 */ VECTOR vel;
	/* 0x10 */ float speed;
	/* 0x14 */ float angy;
	/* 0x18 */ float angz;
	/* 0x1c */ int pad[1];
};

struct HeroDust { // 0x10
	/* 0x0 */ float vel;
	/* 0x4 */ float velvar;
	/* 0x8 */ int timer;
	/* 0xc */ short int rate;
	/* 0xe */ short int flags;
};

struct HeroFall { // 0x20
	/* 0x00 */ float gravity;
	/* 0x04 */ float xyDecel;
	/* 0x08 */ float xRotSpeed;
	/* 0x0c */ float yRotSpeed;
	/* 0x10 */ float xRotSpeedIdeal;
	/* 0x14 */ float yRotSpeedIdeal;
	/* 0x18 */ float glideTaperSpeed;
	/* 0x1c */ int pad[1];
};

struct HeroLedge { // 0x40
	/* 0x00 */ VECTOR idealWallPos;
	/* 0x10 */ VECTOR idealGrabPos;
	/* 0x20 */ float groundHeight;
	/* 0x24 */ float wallAngZ;
	/* 0x28 */ int valid;
	/* 0x2c */ float gravity;
	/* 0x30 */ float camHeight;
	/* 0x34 */ int flags;
	/* 0x38 */ Moby *pMoby;
	/* 0x3c */ int pad;
};

struct HeroTractorBeam { // 0x10
	/* 0x0 */ Moby *pTarget;
	/* 0x4 */ float zRotOfs;
	/* 0x8 */ float zRotSpeed;
	/* 0xc */ float xySpeed;
};

struct HeroGrapple { // 0x30
	/* 0x00 */ float speed;
	/* 0x04 */ Moby *pTarget;
	/* 0x08 */ int valid;
	/* 0x0c */ float timeToTarget;
	/* 0x10 */ float distToTarget;
	/* 0x14 */ int straightenOut;
	/* 0x18 */ int vehicle;
	/* 0x1c */ float cableLen;
	/* 0x20 */ float idealCableLen;
	/* 0x24 */ float targetScore;
	/* 0x28 */ int earlyAbort;
	/* 0x2c */ int pad[1];
};

struct HeroPullShot { // 0x30
	/* 0x00 */ Moby *pTarget;
	/* 0x04 */ int valid;
	/* 0x08 */ float targetScore;
	/* 0x0c */ int connected;
	/* 0x10 */ int pad[8];
};

struct HeroDynamo { // 0x30
	/* 0x00 */ Moby *pTarget;
	/* 0x04 */ int valid;
	/* 0x08 */ float targetScore;
	/* 0x0c */ int trigger;
	/* 0x10 */ Moby *last_pTarget;
	/* 0x14 */ int pad[7];
};

struct HeroSwing { // 0x40
	/* 0x00 */ Moby *pNextTarget;
	/* 0x04 */ Moby *pTarget;
	/* 0x08 */ float targetScore;
	/* 0x0c */ short int connected;
	/* 0x0e */ char valid;
	/* 0x0f */ char qSwitchMe;
	/* 0x10 */ float idealRadius;
	/* 0x14 */ float curCableLen;
	/* 0x18 */ float radialSpeed;
	/* 0x1c */ float forwardAng;
	/* 0x20 */ float gravity;
	/* 0x24 */ float firstSwingSpeed;
	/* 0x28 */ float alignRotSpeed;
	/* 0x2c */ short int animScaleQueued;
	/* 0x2e */ short int firstSwing;
	/* 0x30 */ float swingElv;
	/* 0x34 */ float radialGain;
	/* 0x38 */ float radialDamp;
	/* 0x3c */ float radialLimit;
};

struct HeroQuickSand { // 0x10
	/* 0x0 */ int timesFallen;
	/* 0x4 */ int pad[3];
};

struct HeroHeadIdle { // 0x20
	/* 0x00 */ VECTOR rotOffset;
	/* 0x10 */ int timer;
	/* 0x14 */ float gain;
	/* 0x18 */ float damp;
	/* 0x1c */ int pad[1];
};

struct HeroTailIdle { // 0x50
	/* 0x00 */ VECTOR rotOffsets[4];
	/* 0x40 */ int timers[4];
};

struct HeroQueuedSound { // 0x8
	/* 0x0 */ short int active;
	/* 0x2 */ short int sound;
	/* 0x4 */ short int timer;
	/* 0x6 */ short int flags;
};

struct HeroCommand { // 0xc
	/* 0x0 */ int state;
	/* 0x4 */ Moby *pCurTarget;
	/* 0x8 */ int timer;
};

struct HeroPlayerConstants { // 0x70
	/* 0x00 */ int mobyNum;
	/* 0x04 */ float maxWalkSpeed;
	/* 0x08 */ float kneeHeight;
	/* 0x0c */ float kneeCheckDist;
	/* 0x10 */ float colRadius;
	/* 0x14 */ float colTop;
	/* 0x18 */ float colBot;
	/* 0x1c */ float colBotFall;
	/* 0x20 */ int jumpPushOffTime;
	/* 0x24 */ float jumpPeakFrm;
	/* 0x28 */ float jumpLandFrm;
	/* 0x2c */ float jumpGameLandFrm;
	/* 0x30 */ float jumpMaxHeight;
	/* 0x34 */ float jumpMinHeight;
	/* 0x38 */ int jumpMaxUpTime;
	/* 0x3c */ float jumpGravity;
	/* 0x40 */ float jumpMaxXySpeed;
	/* 0x44 */ float fallGravity;
	/* 0x48 */ float maxFallSpeed;
	/* 0x4c */ float walkAnimSpeedMul;
	/* 0x50 */ float walkAnimSpeedLimLower;
	/* 0x54 */ float walkAnimSpeedLimUpper;
	/* 0x58 */ float jogAnimSpeedMul;
	/* 0x5c */ float jogAnimSpeedLimLower;
	/* 0x60 */ float jogAnimSpeedLimUpper;
	/* 0x64 */ int pad[3];
};

struct MotionBlur { // 0x150
	/* 0x000 */ VECTOR posRing[8];
	/* 0x080 */ VECTOR rotRing[8];
	/* 0x100 */ int blurAlphas[4];
	/* 0x110 */ int blurSteps[4];
	/* 0x120 */ Moby *blurMobys[4];
	/* 0x130 */ float gapReduction[4];
	/* 0x140 */ short int ringIndex;
	/* 0x142 */ short int ringValidSize;
	/* 0x144 */ Moby *pTrackedMoby;
	/* 0x148 */ int blurCnt;
	/* 0x14c */ int active;
};


typedef struct Gadget { // 0x50
	/* 0x00 */ VECTOR jointPos;
	/* 0x10 */ VECTOR jointRot;
	/* 0x20 */ Moby *pMoby;
	/* 0x24 */ Moby *pMoby2;
	/* 0x28 */ bool padButtonDown;
	/* 0x2c */ int alignPad;
	/* 0x30 */ int padButton;
	/* 0x34 */ int gsSpawnFrame;
	/* 0x38 */ char noAmmoTime;
	/* 0x39 */ char unEquipTimer;
	/* 0x3a */ char detached;
	/* 0x3b */ char unequipTime;
	/* 0x3c */ char unEquipStatus;
	/* 0x3d */ char unEquipDelay;
	/* 0x40 */ int equippedTime;
	/* 0x44 */ int state;
	/* 0x48 */ int id;
	/* 0x4c */ float lightAng;
} Gadget;

typedef struct Hero { // 0x2fe0
	/* 0x0000 */ struct Guber guber;
	/* 0x0020 */ mtx4 mtx;
	/* 0x0060 */ mtx4 invMtx;
	/* 0x00a0 */ VECTOR pos;
	/* 0x00b0 */ VECTOR rot;
	/* 0x00c0 */ VECTOR rotSpeed;
	/* 0x00d0 */ VECTOR sphereCenter;
	/* 0x00e0 */ VECTOR missileTarget;
	/* 0x00f0 */ VECTOR cg;
	/* 0x0100 */ VECTOR mtxFxScale;
	/* 0x0110 */ VECTOR lastPos;
	/* 0x0120 */ VECTOR stickInput;
	/* 0x0130 */ struct HeroMove move;
	/* 0x01d0 */ struct HeroColl coll;
	/* 0x0250 */ struct HeroGround ground;
	/* 0x0310 */ struct HeroTrack track;
	/* 0x0370 */ struct HeroTimers timers;
	/* 0x0430 */ struct HeroHotspots hotspots;
	/* 0x0440 */ struct HeroGrind grind;
	/* 0x0540 */ struct HeroZip zip;
	/* 0x0590 */ struct HeroFireDir fireDir;
	/* 0x05e0 */ struct HeroLockOn lockOn;
	/* 0x0630 */ struct HeroMobys mobys;
	/* 0x0640 */ struct HeroAnim anim;
	/* 0x0660 */ struct HeroJoints joints;
	/* 0x07e0 */ struct HeroAnimLayers animLayers;
	/* 0x0820 */ struct HeroTweaker tweaker[18];
	/* 0x1480 */ struct HeroShadow shadow;
	/* 0x14b0 */ struct HeroEyes eyes;
	/* 0x1780 */ struct HeroThrust thrust;
	/* 0x1790 */ struct HeroTurn turn;
	/* 0x17b0 */ struct HeroAttack attack;
	/* 0x1860 */ struct HeroHeadIdle headIdle;
	/* 0x1880 */ struct HeroTailIdle tailIdle;
	/* 0x18d0 */ struct HeroFps fps;
	/* 0x1b10 */ struct HeroWeaponPosRec weaponPosRec;
	/* 0x1c10 */ struct HeroWalkToPos walkToPos;
	/* 0x1c40 */ struct HeroSurf surf;
	/* 0x1c70 */ struct HeroWalk walk;
	/* 0x1ca0 */ struct HeroJump jump;
	/* 0x1da0 */ struct HeroLedge ledge;
	/* 0x1de0 */ struct HeroTractorBeam tractorBeam;
	/* 0x1df0 */ struct HeroCharge charge;
	/* 0x1e10 */ struct HeroSwim swim;
	/* 0x1e60 */ struct HeroWind wind;
	/* 0x1e80 */ struct HeroFall fall;
	/* 0x1ea0 */ struct HeroGrapple grapple;
	/* 0x1ed0 */ struct HeroSwing swing;
	/* 0x1f10 */ struct HeroPullShot pullShot;
	/* 0x1f40 */ struct HeroDynamo dynamo;
	/* 0x1f70 */ struct HeroQuickSand quicksand;
	/* 0x1f80 */ struct HeroDust dust;
	/* 0x1f90 */ struct HeroCommand command;
	/* 0x1f9c */ struct TargetVars target;
	/* 0x2030 */ struct MotionBlur motionBlur;
	/* 0x2180 */ struct MotionBlur wrenchMotionBlur;
	/* 0x22d0 */ Gadget gadgets[6];
	/* 0x24b0 */ int assGadgets[6];
	/* 0x24d0 */ VECTOR prevHandPos;
	/* 0x24e0 */ VECTOR gadgetGlowPos[8];
	/* 0x2560 */ int gadgetGlowRGBA[8];
	/* 0x2580 */ float gadgetGlowSize[8];
	/* 0x25a0 */ float gadgetGlowOfs[8];
	/* 0x25c0 */ short int gadgetGlowCnt;
	/* 0x25c4 */ float heroSpeedAdjuster;
	/* 0x25c8 */ char playerPostDrawFxRegistered;
	/* 0x25c9 */ char playerPostPreDrawFxRegistered;
	/* 0x25ca */ char playerFontDrawRegistered;
	/* 0x25cc */ int state;
	/* 0x25d0 */ int subState;
	/* 0x25d4 */ int stateType;
	/* 0x25d8 */ int previousState;
	/* 0x25dc */ int previousType;
	/* 0x25e0 */ int previousStateTimer;
	/* 0x25e4 */ int prePreviousState;
	/* 0x25e8 */ int prePreviousType;
	/* 0x25ec */ int stateHistory[8];
	/* 0x260c */ int stateTypeHistory[8];
	/* 0x262c */ int stateTimerHistory[8];
	/* 0x264c */ int stateHistoryLen;
	/* 0x2650 */ int effectsLevel;
	/* 0x2654 */ float minDistToLocalCamera;
	/* 0x2658 */ char cycleFiring;
	/* 0x2659 */ char gravityType;
	/* 0x265a */ char firing;
	/* 0x265c */ int clankIdleTimer;
	/* 0x2660 */ char raisedGunArm;
	/* 0x2661 */ char inShallowWater;
	/* 0x2662 */ char invisible;
	/* 0x2663 */ char hideWeapon;
	/* 0x2664 */ char gadgetsOff;
	/* 0x2665 */ char gadgetNotReady;
	/* 0x2666 */ char wrenchOnly;
	/* 0x2667 */ char holdingDeathAnim;
	/* 0x2668 */ char hideWrench;
	/* 0x2669 */ char spawnBoltsToMe;
	/* 0x266a */ char aiFollowingMe;
	/* 0x266b */ char forceWrenchSwitch;
	/* 0x266c */ char forceSwingSwitch;
	/* 0x266d */ char isLocal;
	/* 0x266e */ char inBaseHack;
	/* 0x266f */ char shieldTrigger;
	/* 0x2670 */ char curSeg;
	/* 0x2671 */ char handGadgetType;
	/* 0x2672 */ char externalUpdate;
	/* 0x2674 */ int hudGadgets[6];
	/* 0x268c */ int desiredGadgets[6];
	/* 0x26a4 */ int preemptedGadgets[6];
	/* 0x26bc */ int restoreGadgetFlags[6];
	/* 0x26d4 */ int loadingGadget;
	/* 0x26d8 */ int hackerRemovedGadget;
	/* 0x26dc */ char currIdleAnim;
	/* 0x26dd */ char machineGunFire;
	/* 0x26e0 */ int lastHackTime;
	/* 0x26e4 */ GadgetBox *pGadgetBox;
	/* 0x26e8 */ short int minesPendingExplode[2];
	/* 0x26f0 */ VECTOR failsafePosRing[32];
	/* 0x28f0 */ float rotZRing[32];
	/* 0x2970 */ mtx3 gadgetRotRing[16];
	/* 0x2c70 */ int rotZringIndex;
	/* 0x2c74 */ int rotZringValidSize;
	/* 0x2c78 */ int failsafeRingIndex;
	/* 0x2c7c */ int failsafeRingValidSize;
	/* 0x2c80 */ int gadgetRotRingIndex;
	/* 0x2c84 */ int gadgetRotRingValidSize;
	/* 0x2c88 */ int cameraPosRing[8];
	/* 0x2ca8 */ int cameraRotRing[8];
	/* 0x2cc8 */ int camRingIndex;
	/* 0x2ccc */ int camRingValidSize;
	/* 0x2cd0 */ VECTOR camPos;
	/* 0x2ce0 */ VECTOR camRot;
	/* 0x2cf0 */ mtx3 camUMtx;
	/* 0x2d20 */ struct HeroQueuedSound queuedSounds[2];
	/* 0x2d30 */ int loopingSounds[9];
	/* 0x2d54 */ Moby *loopingSoundMobys[9];
	/* 0x2d78 */ struct HeroSpecialIdleDef SpecialIdles[4];
	/* 0x2db8 */ int specialIdleHistory[4];
	/* 0x2dc8 */ int specialIdleHistoryIndex;
	/* 0x2dcc */ int specialIdleHistorySize;
	/* 0x2dd0 */ int specialIdleID;
	/* 0x2dd4 */ int firingAnim;
	/* 0x2dd8 */ int firingGadget;
	/* 0x2ddc */ int desiredCam;
	/* 0x2de0 */ int savedLights[2];
	/* 0x2de8 */ int lightFxOn;
	/* 0x2dec */ Moby *pHeadTargetMoby;
	/* 0x2df0 */ Moby *pSheepMoby;
	/* 0x2df4 */ Moby *pWhoHitMe;
	/* 0x2df8 */ struct Hero *pWhoSheepedMe;
	/* 0x2dfc */ Moby *pAcidDamager;
	/* 0x2e00 */ int acidDamagerGadgetId;
	/* 0x2e04 */ bool useAcidDamagerGadgetId;
	/* 0x2e05 */ bool sheepMeLongTime;
	/* 0x2e08 */ float stickStrength;
	/* 0x2e0c */ float stickRawAngle;
	/* 0x2e10 */ int targetModeDelay;
	/* 0x2e14 */ float waterDepth;
	/* 0x2e18 */ short int edgePath;
	/* 0x2e1c */ float glideDescentRate;
	/* 0x2e20 */ float hitPoints;
	/* 0x2e24 */ float boltPickupRadiusXY;
	/* 0x2e28 */ float boltPickupZthresh;
	/* 0x2e2c */ short int noClank;
	/* 0x2e30 */ float skidDecel;
	/* 0x2e34 */ short int mtxFxActive;
	/* 0x2e38 */ float analogStickStrength;
	/* 0x2e3c */ short int deathFallChannel;
	/* 0x2e3e */ short int wallJumpAngLimiter;
	/* 0x2e40 */ char wallJumpHeightFactor;
	/* 0x2e41 */ char wallJumpChainCnt;
	/* 0x2e44 */ float wallJumpDist;
	/* 0x2e48 */ float moonJumpIdealHeight;
	/* 0x2e4c */ float moonJumpGravity;
	/* 0x2e50 */ short int chargeDoubleTapTimer;
	/* 0x2e52 */ short int chargeDownTimer;
	/* 0x2e54 */ short int chargeDelayTimer;
	/* 0x2e56 */ short int tweakersReset;
	/* 0x2e58 */ int gadgetFilter;
	/* 0x2e5c */ int gadgetFilterSize;
	/* 0x2e60 */ int targetGadgetFilterSize;
	/* 0x2e64 */ float FPS_InterpSpeed;
	/* 0x2e68 */ float FPS_InterpAccel;
	/* 0x2e6c */ int FPS_StartTime;
	/* 0x2e70 */ char FPSTapTimer;
	/* 0x2e71 */ char FPSTapCount;
	/* 0x2e72 */ char strafeTapTimer;
	/* 0x2e73 */ char strafeTapCount;
	/* 0x2e74 */ char lockedStrafeModeOn;
	/* 0x2e78 */ unsigned int lastDamagedMeOwnerUID;
	/* 0x2e7c */ int lastDamagedMeGadgetId;
	/* 0x2e80 */ float lastDamagedMeHp;
	/* 0x2e84 */ signed char restoreCamAzDir;
	/* 0x2e85 */ signed char restoreCamRotSpd;
	/* 0x2e88 */ int rAmb;
	/* 0x2e8c */ int gAmb;
	/* 0x2e90 */ int bAmb;
	/* 0x2e94 */ Moby *lastWeaponTarget;
	/* 0x2e98 */ Moby *recentTargets[4];
	/* 0x2ea8 */ int lastWeaponTargetTime;
	/* 0x2eac */ struct tNW_GetHitMessage getHitMessage;
	/* 0x2ebc */ struct FlashVars flashVars;
	/* 0x2ecc */ char isGetHitMsgPending;
	/* 0x2ecd */ char lookAndCrouch;
	/* 0x2ece */ char lookAndThrowWrench;
	/* 0x2ecf */ char earlyThrowAbort;
	/* 0x2ed0 */ char lookAndGetHit;
	/* 0x2ed1 */ char lastDeathWasSuicide;
	/* 0x2ed2 */ char noWeaponSwitching;
	/* 0x2ed3 */ char noWrenchEquip;
	/* 0x2ed4 */ char jackpotMult;
	/* 0x2ed5 */ signed char rocketHitMe;
	/* 0x2ed6 */ char explode;
	/* 0x2ed7 */ bool deathWasCalled;
	/* 0x2ed8 */ int hudHealthTimer;
	/* 0x2edc */ bool pauseOn;
	/* 0x2edd */ char pauseTimer;
	/* 0x2ee0 */ int tauntOverrideTimer;
	/* 0x2ee4 */ char playerType;
	/* 0x2ee8 */ Moby *flagMoby;
	/* 0x2eec */ struct HeroPlayerConstants *playerConst;
	/* 0x2ef0 */ Moby *pMoby;
	/* 0x2ef4 */ struct VehicleBase *pVehicle;
	/* 0x2ef8 */ struct VehicleBase *pVehiclePending;
	/* 0x2efc */ GameCamera *camera;
	/* 0x2f00 */ PAD *pPad;
	/* 0x2f04 */ float cheatX;
	/* 0x2f08 */ float cheatY;
	/* 0x2f0c */ float cheatZ;
	/* 0x2f10 */ int mpIndex;
	/* 0x2f14 */ int mpTeam;
	/* 0x2f18 */ int vehicleState;
	/* 0x2f1c */ int vehicleStateTimer;
	/* 0x2f20 */ int pointsLastKill;
	/* 0x2f24 */ float maxHP;
	/* 0x2f28 */ struct tNW_Player *pNetPlayer;
	/* 0x2f2c */ struct tNW_PlayerStateMessage newStateMessage;
	/* 0x2f48 */ int timeOfReceivedStateMsg;
	/* 0x2f4c */ Moby *lastVehicleMoby;
	/* 0x2f50 */ int iLastVehicleOffTime;
	/* 0x2f54 */ Moby *pLastGrindRail;
	/* 0x2f58 */ float closestCamDistSqr;
	/* 0x2f5c */ int bSphereVis;
	/* 0x2f60 */ float m_shortTermLinkDirtyTime;
	/* 0x2f64 */ float m_accumLinkDirtyTime;
	/* 0x2f70 */ VECTOR initialPos;
	/* 0x2f80 */ VECTOR initialRot;
	/* 0x2f90 */ float stashedWallCheckHeight;
	/* 0x2f94 */ float stashedWallCheckDist;
	/* 0x2f98 */ float stashedWallDist;
	/* 0x2f9c */ int lookModeTimeout;
	/* 0x2fa0 */ int lookModeDelay;
	/* 0x2fa4 */ int baseExperience;
	/* 0x2fa8 */ int Experience;
	/* 0x2fac */ int currentAcumXp;
	/* 0x2fb0 */ float damageMultipler;
	/* 0x2fb4 */ int armorLevel;
	/* 0x2fb8 */ bool limitBreakFull;
	/* 0x2fbc */ float limitBreakPercentage;
	/* 0x2fc0 */ float movementSpeedModifier;
	/* 0x2fc4 */ char grindRailWeaponLock;
	/* 0x2fc5 */ char currArmAnim;
	/* 0x2fc6 */ short int activePadFrame;
	/* 0x2fc8 */ char alreadyPlayedNoAmmoClick;
	/* 0x2fc9 */ char sceneInvis;
	/* 0x2fca */ char ninjaCheatActive;
	/* 0x2fcb */ char hadWind;
	/* 0x2fcc */ Moby *pWrenchReplacement;
	/* 0x2fd0 */ int startLimitBreakDiff;
	union {
	struct { // 0x31f0
		/* 0x2fe0 */ int frameSentStick;
		/* 0x2fe4 */ float damageDone;
		/* 0x2fe8 */ short int numKills;
		/* 0x2fea */ char slot;
		/* 0x2fec */ struct PadStream padStream;
		/* 0x31cc */ unsigned char startGameButtonOffFrames;
		/* 0x31cd */ unsigned char curPadMsgSequenceNum;
		/* 0x31ce */ char curPadMsgFrame;
		/* 0x31cf */ char framesUntilStateRot;
		/* 0x31d0 */ char mapTimer;
		/* 0x31d2 */ short int lastMineId;
		/* 0x31d4 */ struct HeroCommand command;
		/* 0x31e0 */ Moby *pRespawnDest;
	} LocalHero;
	struct { // 0x3ab0
	/* 0x2fe0 */ struct GameCamera DummyCamera;
	/* 0x3450 */ struct PAD RemotePad;
	/* 0x3a10 */ bool completedEnoughUpdates;
	/* 0x3a11 */ bool rotOutOfSyncLastUpdate;
	/* 0x3a12 */ char padFrameChunksReceived;
	/* 0x3a13 */ char posOutOfSyncLastUpdate;
	/* 0x3a14 */ char stateAtSyncFrame;
	/* 0x3a20 */ VECTOR receivedSyncPos;
	/* 0x3a30 */ VECTOR posAtSyncFrame;
	/* 0x3a40 */ VECTOR syncPosDifference;
	/* 0x3a50 */ VECTOR receivedSyncRot;
	/* 0x3a60 */ VECTOR rotAtSyncFrame;
	/* 0x3a70 */ float interpVel;
	/* 0x3a74 */ float syncRotDifference;
	/* 0x3a78 */ int flags;
	/* 0x3a7c */ int sequenceIdOfSyncData;
	/* 0x3a80 */ int receivedState;
	/* 0x3a90 */ VECTOR remoteCorrectionVel;
	/* 0x3aa0 */ float remoteCorrectionRotVel;
	/* 0x3aa4 */ char syncFrameOffset;
	} RemoteHero;
	};
} Hero;

typedef Hero Player;

typedef void (*PlayerUpdate_func)(Player * player);
typedef int (*GetMoby_Func)(Player *player);
typedef void (*HandleEvent_Func)(Player *player, GuberEvent *event);
typedef bool (*FriendlyToTeam_Func)(Player *player, int team);
typedef int (*GetTeam_Func)(Player *player);
typedef int (*GetVehicleMoby_Func)(Player *player);
typedef int (*GetSlot_Func)(Player *player);
typedef void (*PlayerUpdateState_func)(Player * player, int stateId, int bTransAnim, int bForce, int bFall);

typedef struct PlayerVTable {
    int pad[2];
    void * FUNC_08;
    PlayerUpdate_func Update;
    GetMoby_Func GetMoby;
	HandleEvent_Func HandleEvent;
	int pad_18;
	FriendlyToTeam_Func FriendlyToTeam;
	void * FUNC_20;
	GetTeam_Func GetTeam;
	void * FUNC_28;
    void * FUNC_2C;
    void * FUNC_30;
    void * FUNC_34;
    void * FUNC_38;
    PlayerUpdateState_func InitBodyState;
	void * FUNC_40;
	void * FUJNC_44;
	GetVehicleMoby_Func GetVehicleMoby;
	GetSlot_Func GetSlot; // uses returns player->LocalHero.slot
} PlayerVTable;


/*
 * NAME :    playerGetAll
 * 
 * DESCRIPTION :
 *       Returns a pointer to an array of Player object pointers.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ Player ** playerGetAll(void);

/*
 * NAME :    playerGetFromIndex
 * 
 * DESCRIPTION :
 *       Returns a pointer to the given player.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ Player * playerGetFromIndex(int idx);

/*
 * NAME :    playerIsValid
 * 
 * DESCRIPTION :
 *       Returns a whether the given player is a valid and connected client.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
int playerIsValid(Player * player);

/*
 * NAME :    playerEquipWeapon
 * 
 * DESCRIPTION :
 *       Change player's equipped weapon.
 * 
 * NOTES :
 * 
 * ARGS : 
 *      player      :           Pointer to player data struct
 *      weaponId    :           Weapon id to set
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_SETTER__ void playerEquipWeapon(Player * player, int weaponId);

/*
 * NAME :    playerSetLocalEquipslot
 * 
 * DESCRIPTION :
 *       Set's the given local player's equip slot with the given weapon id.
 * 
 * NOTES :
 * 
 * ARGS : 
 *      localPlayerId      :           Local player index.
 *      
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_SETTER__ void playerSetLocalEquipslot(int localPlayerId, int slot, int weaponId);

/*
 * NAME :    playerGetLocalEquipslot
 * 
 * DESCRIPTION :
 *       Gets the given local player's currently equipped weapon in the given slot.
 * 
 * NOTES :
 * 
 * ARGS : 
 *      localPlayerId      :           Local player index.
 *      
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ int playerGetLocalEquipslot(int localPlayerId, int slot);

/*
 * NAME :    playerGetWeaponMaxAmmo
 * 
 * DESCRIPTION :
 *       Gets the given player's max ammo for the given weapon id.
 * 
 * NOTES :
 * 
 * ARGS : 
 *      
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ short playerGetWeaponMaxAmmo(GadgetBox* gBox, int weaponId);

/*
 * NAME :    playerSetTeam
 * 
 * DESCRIPTION :
 *       Change player's equipped weapon.
 * 
 * NOTES :
 * 
 * ARGS : 
 *      player      :           Pointer to player data struct
 *      teamId    :             Team id to set
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_SETTER__ void playerSetTeam(Player * player, int teamId);

/*
 * NAME :    playerIsLocal
 * 
 * DESCRIPTION :
 *       Whether or not the given player is local or remote.
 * 
 * NOTES :
 * 
 * ARGS : 
 *      player      :           Target player.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ int playerIsLocal(Player * player);

/*
 * NAME :    playerIdIsLocal
 * 
 * DESCRIPTION :
 *       Whether or not the given player id is local or remote.
 * 
 * NOTES :
 * 
 * ARGS : 
 *      player      :           Target player id.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ int playerIdIsLocal(int playerId);

/*
 * NAME :    playerGetNumLocals
 * 
 * DESCRIPTION :
 *       Number of locals the client has.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ int playerGetNumLocals(void);

/*
 * NAME :    playerGiveWeapon
 * 
 * DESCRIPTION :
 *       Converts a WEAPON_SLOT_INDEX to the respective WEAPON_IDS
 * 
 * NOTES :
 * 
 * ARGS : 
 *      gadgetBox   :           Target player's gadget box.
 *      weaponId    :           ID of weapon to give.
 *      weaponLevel :           Level of weapon.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
void playerGiveWeapon(GadgetBox * gadgetBox, int weaponId, int weaponLevel, int giveMaxAmmo);

/*
 * NAME :    playerStripWeapons
 * 
 * DESCRIPTION :
 *       Removes all weapons from the given player's gadgetbox.
 * 
 * NOTES :
 * 
 * ARGS : 
 *      player      :           Target player's.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
void playerStripWeapons(Player* player);

/*
 * NAME :    playerGetWeaponAlphaModCount
 * 
 * DESCRIPTION :
 *       Returns the number of the given alpha mod on the given weapon.
 * 
 * NOTES :
 * 
 * ARGS : 
 *      gadgetBox   :           Target player's gadget box.
 *      weaponId    :           ID of weapon to check.
 *      alphaModId :            Alpha mod to count.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
int playerGetWeaponAlphaModCount(GadgetBox* gadgetBox, int weaponId, int alphaModId);

/*
 * NAME :    playerRespawn
 * 
 * DESCRIPTION :
 *       Respawns the given player.
 * 
 * NOTES :
 *          Spawn point is determined internally.
 *          This will freeze on CQ if the player hasn't picked a node to respawn to.
 * 
 * ARGS : 
 *      player      :           Target player.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
void playerRespawn(Player * player);

/*
 * NAME :    playerIncHealth
 * 
 * DESCRIPTION :
 *       
 * 
 * NOTES :
 * 
 * 
 * ARGS : 
 *      player      :           Target player.
 *       health      :            Target health.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
void playerIncHealth(Player * player, float health);

/*
 * NAME :    playerDecHealth
 * 
 * DESCRIPTION :
 *       
 * 
 * NOTES :
 * 
 * 
 * ARGS : 
 *      player      :           Target player.
 *       health      :            Target health.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
void playerDecHealth(Player * player, float health);

/*
 * NAME :    playerSetHealth
 * 
 * DESCRIPTION :
 *       
 * 
 * NOTES :
 * 
 * 
 * ARGS : 
 *      player      :           Target player.
 *       health      :            Target health.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
void playerSetHealth(Player * player, float health);

/*
 * NAME :    playerDropFlag
 * 
 * DESCRIPTION :
 *       Causes the player to drop the flag.
 * 
 * NOTES :
 * 
 * 
 * ARGS : 
 *      player      :           Target player.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
void playerDropFlag(Player * player, int a1);

/*
 * NAME :    playerIsDead
 * 
 * DESCRIPTION :
 *       Returns non-zero if the given player is dead.
 * 
 * NOTES :
 * 
 * 
 * ARGS : 
 *      player      :           Target player.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
int playerIsDead(Player * player);

/*
 * NAME :    playerStateIsDead
 * 
 * DESCRIPTION :
 *       Returns non-zero if the given player state is dead.
 * 
 * NOTES :
 * 
 * 
 * ARGS : 
 *      state      :           State.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
int playerStateIsDead(int state);

/*
 * NAME :    playerSetPosRot
 * 
 * DESCRIPTION :
 *       Sets a given player's position and rotation.
 * 
 * NOTES :
 * 
 * ARGS : 
 *      player      :           Target player.
 *      p           :           Position.
 *      r           :           Rotation.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_SETTER__ void playerSetPosRot(Player * player, VECTOR p, VECTOR r);

/*
 * NAME :    playerGetSpawnpoint
 * 
 * DESCRIPTION :
 *       Gets a given player's next spawn position and rotation.
 * 
 * NOTES :
 * 
 * ARGS : 
 *      player      :           Target player.
 *      outPos      :           Out position.
 *      outRot      :           Out rotation.
 *       isFirst      :            Whether or not its the player's first spawn.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_SETTER__ void playerGetSpawnpoint(Player * player, VECTOR outPos, VECTOR outRot, int isFirst);

/*
 * NAME :    playerGetPad
 * 
 * DESCRIPTION :
 *       Returns a pointer to the player's pad data.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          player:                     Target player.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ PadButtonStatus * playerGetPad(Player * player);

/*
 * NAME :    playerPadGetButton
 * 
 * DESCRIPTION :
 *       Returns 1 when the given player is pressing the given button combination.
 *          Returns negative on failure.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          player:                     Pointer to player's player object.
 *          buttonMask:                 Buttons to check.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ int playerPadGetButton(Player * player, u16 buttonMask);

/*
 * NAME :    playerPadGetAnyButton
 * 
 * DESCRIPTION :
 *       Returns 1 when the given player is pressing any of the given buttons.
 *          Returns negative on failure.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          player:                     Pointer to player's player object.
 *          buttonMask:                 Buttons to check.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ int playerPadGetAnyButton(Player * player, u16 buttonMask);

/*
 * NAME :    playerPadGetButtonDown
 * 
 * DESCRIPTION :
 *       Returns 1 during the frame that the given player starts pressing the given button combination.
 *          Returns negative on failure.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          player:                     Pointer to player's player object.
 *          buttonMask:                 Buttons to check.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ int playerPadGetButtonDown(Player * player, u16 buttonMask);

/*
 * NAME :    playerPadGetAnyButtonDown
 * 
 * DESCRIPTION :
 *       Returns 1 during the frame that the given player starts pressing any of the given buttons.
 *          Returns negative on failure.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          player:                     Pointer to player's player object.
 *          buttonMask:                 Buttons to check.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ int playerPadGetAnyButtonDown(Player * player, u16 buttonMask);

/*
 * NAME :    playerPadGetButtonUp
 * 
 * DESCRIPTION :
 *       Returns 1 during the frame that the given player releases the given button combination.
 *          Returns negative on failure.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          player:                     Pointer to player's player object.
 *          buttonMask:                 Buttons to check.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ int playerPadGetButtonUp(Player * player, u16 buttonMask);

/*
 * NAME :    playerPadGetAnyButtonUp
 * 
 * DESCRIPTION :
 *       Returns 1 during the frame that the given player releases any of the given buttons.
 *          Returns negative on failure.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          player:                     Pointer to player's player object.
 *          buttonMask:                 Buttons to check.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ int playerPadGetAnyButtonUp(Player * player, u16 buttonMask);

/*
 * NAME :    playerGetVTable
 * 
 * DESCRIPTION :
 *       Returns pointer to the given player's vtable.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          player:                     Pointer to player's player object.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
__LIBDL_GETTER__ PlayerVTable* playerGetVTable(Player * player);

/*
 * NAME :    playerGetFromUID
 * 
 * DESCRIPTION :
 *       Returns pointer to the player with the given UID.
 *       Returns NULL if not found.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          uid:                       Player UID.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
Player * playerGetFromUID(int uid);

/*
 * NAME :    playerGetFromSlot
 * 
 * DESCRIPTION :
 *       Returns pointer to the player with the given local slot index.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          slot:                       Player slot index.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
Player * playerGetFromSlot(int slot);

/*
 * NAME :    playerGetJuggSafeTeam
 * 
 * DESCRIPTION :
 *       Returns juggernaut safe team.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
int playerGetJuggSafeTeam(Player * player);

/*
 * NAME :    playerIsConnected
 * 
 * DESCRIPTION :
 *       Returns whether or not the given player still has a valid connection.
 * 
 * NOTES :
 * 
 * ARGS : 
 * 
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
int playerIsConnected(Player * player);

#endif // _LIBDL_PLAYER_H_
