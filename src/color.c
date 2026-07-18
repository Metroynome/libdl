#include "game.h"
#include "color.h"

u32 internal_colorLerp_inGame(u32, u32, float);
u32 internal_colorLerp_inLobby(u32, u32, float);

/*
 * NAME :    colorLerp
 * 
 * DESCRIPTION :
 *       Interpolates the color from a to b by t.
 * 
 * NOTES :
 * 
 * ARGS : 
 *          a     :           Start color.
 *          b     :           End color.
 *          t     :           Amount to interpolate by.
 * 
 * RETURN :
 * 
 * AUTHOR :      Daniel "Dnawrkshp" Gerendasy
 */
u32 colorLerp(u32 a, u32 b, float t)
{
    if (isInGame())
    {
        return internal_colorLerp_inGame(a, b, t);
    }
    else if (isInMenus())
    {
        return internal_colorLerp_inLobby(a, b, t);
    }

    return a;
}

u32 colorScale(u32 color, float scale)
{
  int r = scale * (color & 0xff);
  int g = scale * ((color >> 8) & 0xff);
  int b = scale * ((color >> 16) & 0xff);
  int a = scale * ((color >> 24) & 0xff);

  if (r > 255) r = 255;
  if (g > 255) g = 255;
  if (b > 255) b = 255;
  if (a > 255) a = 255;

  return (a << 24) | (b << 16) | (g << 8) | r;
}

int colorGetMax(u32 color)
{
  int r = color & 0xff;
  int g = (color >> 8) & 0xff;
  int b = (color >> 16) & 0xff;
  return (r > g) ? (r > b ? r : b) : (g > b ? g : b);
}

u32 colorSetChannel(u32 color, int channel, u8 value)
{
  int shift = 8 * channel;
  int mask = 0xff << shift;

  return (color & ~mask) | (value << shift);
}

u32 FastColorTween(float t, u32 a, u32 b)
{
  int ar = a & 0xff;
  int ag = (a >> 8) & 0xff;
  int ab = (a >> 16) & 0xff;
  int aa = (a >> 24) & 0xff;
  int br = b & 0xff;
  int bg = (b >> 8) & 0xff;
  int bb = (b >> 16) & 0xff;
  int ba = (b >> 24) & 0xff;
  u32 r = ar + (int)((float)(br - ar) * t);
  u32 g = ag + (int)((float)(bg - ag) * t);
  u32 bch = ab + (int)((float)(bb - ab) * t);
  u32 aCh = aa + (int)((float)(ba - aa) * t);

  return (aCh << 24) | (bch << 16) | (g << 8) | r;
}

u32 colorLevel99(int alpha, int cycleFrames)
{
  if (cycleFrames <= 0) cycleFrames = 150;

  float t = (float)(gameGetTime() % cycleFrames) / (float)cycleFrames;
  u32 from;
  u32 to;

  if (t < 0.333) {
    from = 0x804020;
    to = 0x208040;
  } else if (t < 0.667) {
    from = 0x208040;
    to = 0x402080;
    t -= 0.333;
  } else {
    from = 0x402080;
    to = 0x804020;
    t -= 0.667;
  }

  return (alpha << 24) | (FastColorTween(t * 3.0, from, to) & 0xffffff);
}

