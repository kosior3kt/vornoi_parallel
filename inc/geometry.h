#ifndef __GEOMETRY__
#define __GEOMETRY__

#include "defines.h"
#include <cmath>
#include <time.h>
#include <random>

//probably want to move this to different file - I will have to counf distance between two points at some point (hehe)
struct point{
   int x;
   int y;
   col32 col{colour::black};
   size_t radius{0};
   point(const int& _x, const int& _y) : x(_x), y(_y){};
   point(const int& _x, const int& _y, const col32& _col, const size_t& _size) : x(_x), y(_y), col(_col), radius(_size){};
   point() = delete; ///dont want to allow user to create empty point - this is gonna be haounting me later on...
   point(point&&) = default;
   point& operator=(point&&) = default;
   point(const point&) = default;
   static float distance(const point& _a, const point& _b);
   static point get_random(const col32& _col = colour::white, const size_t& _rad = 5);
};


struct line{
   point beginning;
   point end;
   line(const point& _b, const point& _e) : beginning(_b), end(_e){};

};

#endif
