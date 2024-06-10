#ifndef __CANVAS__
#define __CANVAS__

#include <array>
#include <fstream>
#include "defines.h"
#include <iostream>
#include "geometry.h"
#include <cmath>

namespace paths
{
   //static std::string default_path = "~/Programming/cpp/Vornoi/res/res.ppm";
   static std::string default_path = "/Users/jk/Programming/CPP/Vornoi/res";
   static std::string path_red = "/home/jk/Programming/cpp/Vornoi/res/res_red.ppm";
   static std::string path_blue = "/home/jk/Programming/cpp/Vornoi/res/res_blue.ppm";
   static std::string path_green = "/home/jk/Programming/cpp/Vornoi/res/res_green.ppm";
}


void fill_image(canvas& _im, const col32& _col);
void draw_Voranoi(canvas& _im, const std::vector<point>& _points);
void add_point(canvas& _im, const int& _width, const int& _height, const col32& _col = colour::black, const int& _size = 0);
void add_point(canvas& _im, const point& _point);
void add_line(canvas& _im, const line& _line);
void save_image_as_ppm(const canvas& _im, std::string _path = paths::default_path);
void draw_circle(canvas& _im, const point& point);
col32 get_colour(const point&);

#endif

