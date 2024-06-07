#ifndef __DEFINES__
#define __DEFINES__

#include <inttypes.h>
#include <string>

///values 
#ifdef DEBUG
constexpr int WIDTH  = 5;
constexpr int HEIGHT = 3;
#else
constexpr int WIDTH  = 800;
constexpr int HEIGHT = 600;
#endif

using col32 = uint32_t;
using canvas = std::array<std::array<col32, WIDTH>, HEIGHT>;

///colours 
namespace colour{
   ///let's say that 0xAARRGGBB
   constexpr col32 white  = 0xFFFFFF;
   constexpr col32 red    = 0xFF0000;
   constexpr col32 blue   = 0x0000FF;
   constexpr col32 green  = 0x00FF00;
   constexpr col32 black  = 0x00000;
}


struct point{
   int x;
   int y;
   col32 col{colour::black};
   size_t size{0};
   point(const int& _x, const int& _y) : x(_x), y(_y){};
   point(const int& _x, const int& _y, const col32& _col, const size_t& _size) : x(_x), y(_y), col(_col), size(_size){};
   point() = delete; ///dont want to allow user to create empty point - this is gonna be haounting me later on...
   point(point&&) = default;
   point(const point&) = default;
};

std::string default_path = "/home/jk/Programming/cpp/Vornoi/res/res.ppm";
std::string path_red = "/home/jk/Programming/cpp/Vornoi/res/res_red.ppm";
std::string path_blue = "/home/jk/Programming/cpp/Vornoi/res/res_blue.ppm";
std::string path_green = "/home/jk/Programming/cpp/Vornoi/res/res_green.ppm";
#endif
