#ifndef __DEFINES__
#define __DEFINES__

#include <inttypes.h>
#include <string>
#include <vector>

///values 
#ifdef DEBUG
constexpr int WIDTH  = 5;
constexpr int HEIGHT = 3;
#else
constexpr int WIDTH  = 800;
constexpr int HEIGHT = 600;
constexpr int SEED_NUMBER = 69;
#endif

using col32 = uint32_t;
using canvas = std::array<std::array<col32, WIDTH>, HEIGHT>;

///colours 
namespace colour{
   ///let's say that 0xRRGGBB
   constexpr col32 white  = 0xFFFFFF;
   constexpr col32 red    = 0xFF0000;
   constexpr col32 green  = 0x00FF00;
   constexpr col32 blue   = 0x0000FF;
   constexpr col32 black  = 0x00000;
}

#endif
