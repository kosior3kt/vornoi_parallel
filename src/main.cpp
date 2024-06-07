#include <iostream>
#include "defines.h"
#include <array>
#include <fstream>

/*
template<typename file, typename arg>
void helper_save(file& _file, arg _arg){
   _file<<_arg<<" ";
}

template<typename file, typename first, typename ...args>
void helper_save(file& _file, first _arg, args... _args){
   _file<<_arg<<" ";
   helper_save(_file, _args...);
}
*/


void stream_to_file(std::ofstream &_file){
   //base case
}

template <typename T, typename... Args>
void stream_to_file(std::ofstream &_file, T && _first, Args&&... args){
   std::cout<< _first << " ";
   _file << std::forward<T>(_first) << " ";  ///shold there be a space if this is the last recursion call?
   if constexpr (sizeof...(args) > 0){
      stream_to_file(_file, std::forward<Args>(args)...);
   }
   else{
      std::cout<<"\n";
      _file<<std::endl;
   }
}

void fill_image(std::array<std::array<col32, WIDTH>, HEIGHT>& _im, col32 _col){
for(size_t i = 0; i < HEIGHT; ++i){
      for(size_t j = 0; j < HEIGHT; ++j){
         _im[i][j] = _col;
      }
   }
}

void save_image_as_ppm(const std::array<std::array<col32, WIDTH>, HEIGHT>& _im, std::string _path = default_path){  
   std::ofstream file(_path);
   //if(!file.is_open()) exit(); ///something horrible happend probably

   file<<"P6\n"<<WIDTH<<" "<<HEIGHT<<std::endl;
   file<<255<<std::endl<<255<<std::endl;
   std::cout<<"P6\n"<<WIDTH<<" "<<HEIGHT<<std::endl;
   std::cout<<255<<std::endl<<255<<std::endl;
   for(auto col : _im)
   {
      for(auto val : col)
      {
         ///val saved as RRR GGG BBB where each of those is a number from 0 - 255. next line in next pixel
         uint8_t red    = val & 0xFF << 8*2;
         uint8_t green  = val & 0xFF << 8*1;
         uint8_t blue   = val & 0xFF << 8*0;
         stream_to_file(file, red, green, blue);
      }
      
   }
   file.close();
}

int main(void){

   std::array<std::array<col32, WIDTH>, HEIGHT> image;
   fill_image(image, colour::red);
   save_image_as_ppm(image);
   std::cout<<"i'm still working UwU\n";
   return 0;
}
