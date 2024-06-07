#include <iostream>
#include "defines.h"
#include <array>
#include <fstream>
#include <vector>

void stream_to_file(std::ofstream &_file){
   //base case
}

template <typename T, typename... Args>
void stream_to_file(std::ofstream &_file, T && _first, Args&&... args){
   std::string temp = std::to_string(_first);
   _file << std::forward<std::string>(temp) << " ";  ///shold there be a space if this is the last recursion call?
   if constexpr (sizeof...(args) > 0){
      stream_to_file(_file, std::forward<Args>(args)...);
   }
   else{
      _file<<std::endl;
   }
}

void fill_image(canvas& _im, const col32& _col){
std::cout<< "filling everything with colour: " << std::hex << _col << std::endl;
for(size_t i = 0; i < HEIGHT; ++i){
      for(size_t j = 0; j < WIDTH; ++j){
         _im[i][j] = _col;
      }
   }
}

void add_point(canvas& _im, const int& _width, const int& _height, const col32& _col = colour::black, const int& _size = 0){
   if(_width > WIDTH || _width < 0 || _height > HEIGHT || _height < 0) return;
   _im[_width][_height] = _col;
   for(int i = 0; i < _size; ++i)
   {
      for(int j = 0; j < _size; ++j){
         auto is_inside = [&](const int& _x, const int& _y)->bool{
            if(_x > HEIGHT || _x < 0 || _y > HEIGHT || _y < 0) return false;
            else return true;
         };
         //if(_width + i < WIDTH && _height + j < HEIGHT) _im[_width + i][ _height + j] = _col;
         if(is_inside(_width + i, _height + j))_im[_width + i][ _height + j] = _col;
         if(is_inside(_width - i, _height + j))_im[_width - i][ _height + j] = _col;
         if(is_inside(_width + i, _height - j))_im[_width + i][ _height - j] = _col;
         if(is_inside(_width - i, _height - j))_im[_width - i][ _height - j] = _col;
      }
   }
}

void add_point(canvas& _im, const point& _point)
{
   _im[_point.x][_point.y] = _point.col;
   for(int i = 0; i < _point.size; ++i)
   {
      for(int j = 0; j < _point.size; ++j){

         auto is_inside = [&](const int& _x, const int& _y)->bool{
            if(_x > HEIGHT || _x < 0 || _y > HEIGHT || _y < 0) return false;
            else return true;
         };
         //if(_width + i < WIDTH && _height + j < HEIGHT) _im[_width + i][ _height + j] = _col;
         if(is_inside(_point.x + i, _point.y + j))_im[_point.x + i][ _point.y + j] = _point.col;
         if(is_inside(_point.x - i, _point.y + j))_im[_point.x - i][ _point.y + j] = _point.col;
         if(is_inside(_point.x + i, _point.y - j))_im[_point.x + i][ _point.y - j] = _point.col;
         if(is_inside(_point.x - i, _point.y - j))_im[_point.x - i][ _point.y - j] = _point.col;
      }
   }
}

void save_image_as_ppm(const canvas& _im, std::string _path = default_path){  
   std::ofstream file(_path);
   file<<"P3\n"<< std::to_string(WIDTH)<<" "<< std::to_string(HEIGHT)<<std::endl;
   file<<255<<std::endl;
   std::cout<<std::dec;
   for(auto col : _im)
   {
      for(col32 val : col)
      {
         ///val saved as RRR GGG BBB where each of those is a number from 0 - 255. next line in next pixel

         uint8_t red    =  (val >> 8*2) & 0xFF;
         uint8_t green  =  (val >> 8*1) & 0xFF;
         uint8_t blue   =  (val >> 8*0) & 0xFF;
         stream_to_file(file, red, green, blue);
      }
      file<<"\n";
   }
   file.close();
}

int main(void){

   std::vector<point> points;

   canvas image_red;
   canvas image_blue;
   canvas image_green;

   fill_image(image_red, colour::red);
   fill_image(image_blue, colour::blue);
   fill_image(image_green, colour::green);


   save_image_as_ppm(image_red, path_red);
   save_image_as_ppm(image_blue, path_blue);
   save_image_as_ppm(image_green, path_green);

   ///testing points here =3

   canvas image_black;
   fill_image(image_black, colour::black);
   add_point(image_black, HEIGHT/2, WIDTH/2, colour::white, 3);

   point p1(600, 500, colour::red, 7);
   point p2(250, 300, colour::blue, 5);
   points.push_back(p1);
   points.push_back(p2);

   for(auto p : points)
   {
      add_point(image_black, p);
   };

   add_point(image_black, HEIGHT/2, WIDTH/2, colour::white, 3);
   save_image_as_ppm(image_black);
   std::cout<<"i'm still working UwU, but barely...\n";
   return 0;
}
