#ifndef __DEFINES__
#define __DEFINES__

#include <inttypes.h>
#include <string>

using col32 = uint32_t;


///values 
#ifdef DEBUG
constexpr int WIDTH  = 5;
constexpr int HEIGHT = 3;
#else
constexpr int WIDTH  = 800;
constexpr int HEIGHT = 600;
#endif

///colours 
namespace colour{
   ///let's say that 0xAARRGGBB
   constexpr col32 black  = 0xFFFFFF;
   constexpr col32 red    = 0xFF0000;
   constexpr col32 blue   = 0x0000FF;
   constexpr col32 green  = 0x00FF00;
   constexpr col32 white  = 0x00000;
}

std::string default_path = "/home/jk/Programming/cpp/Vornoi/res/res.ppm";
std::string path_red = "/home/jk/Programming/cpp/Vornoi/res/res_red.ppm";
std::string path_blue = "/home/jk/Programming/cpp/Vornoi/res/res_blue.ppm";
std::string path_green = "/home/jk/Programming/cpp/Vornoi/res/res_green.ppm";
#endif
