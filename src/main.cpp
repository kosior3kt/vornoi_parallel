#include <iostream>
#include "defines.h"
#include <array>
#include <fstream>

void stream_to_file(std::ofstream &_file){
   //base case
}

template <typename T, typename... Args>
void stream_to_file(std::ofstream &_file, T && _first, Args&&... args){
   std::string temp = std::to_string(_first);
#ifdef DEBUG
   //std::cout<< temp << " ";
#endif
   _file << std::forward<std::string>(temp) << " ";  ///shold there be a space if this is the last recursion call?
   if constexpr (sizeof...(args) > 0){
      stream_to_file(_file, std::forward<Args>(args)...);
   }
   else{
      // std::cout<<"\n";
      // _file<<std::endl;
   }
}

void fill_image(std::array<std::array<col32, WIDTH>, HEIGHT>& _im, const col32& _col){
std::cout<< "filling everything with colour: " << std::hex << _col << std::endl;
for(size_t i = 0; i < HEIGHT; ++i){
      for(size_t j = 0; j < WIDTH; ++j){
         _im[i][j] = _col;
      }
   }

   // for(auto col : _im){
   //    for(auto val : col){
   //       val = _col; 
   //    }
   // }
}

void save_image_as_ppm(const std::array<std::array<col32, WIDTH>, HEIGHT>& _im, std::string _path = default_path){  
   std::ofstream file(_path);
   //if(!file.is_open()) exit(); ///something horrible happend probably

   // std::string width  = std::to_string(WIDTH);
   // std::string height = std::to_string(HEIGHT);
   file<<"P3\n"<< std::to_string(WIDTH)<<" "<< std::to_string(HEIGHT)<<std::endl;
   file<<255<<std::endl;
   std::cout<<std::dec;
#ifdef DEBUG
   std::cout<<"P3\n"<< std::to_string(WIDTH)<<" "<< std::to_string(HEIGHT)<<std::endl;
   std::cout<<255<<std::endl<<255<<std::endl;
#endif
   for(auto col : _im)
   {
      for(col32 val : col)
      {
         ///val saved as RRR GGG BBB where each of those is a number from 0 - 255. next line in next pixel
         //uint8_t red    = val & 0xFF << 8*2;
         
         // uint8_t red    =  val & (0xFF << 8*2);
         // uint8_t green  = val & (0xFF << 8*1);
         // uint8_t blue   = val & (0xFF << 8*0);

         uint8_t red    =  (val >> 8*2) & 0xFF;
         uint8_t green  =  (val >> 8*1) & 0xFF;
         uint8_t blue   =  (val >> 8*0) & 0xFF;
         stream_to_file(file, red, green, blue);
#ifdef DEBUG
         // std::cout<<std::hex<<"this is the value of val: \n"<<val<<std::endl;
         // std::cout<<std::hex<<"this is the value shifted by 16 to the left of val: \n"<<((val & 0xFF0000) >> 8 * 2)<<std::endl;
         // printf("this is the value of val: %d \n", val);
         printf("red: %d, green: %d, blue: %d \n", red, green, blue);
#endif 
      }
      file<<"\n";
#ifdef DEBUG
      std::cout<<std::endl;
#endif 
   }
   file.close();
}

int main(void){

   std::array<std::array<col32, WIDTH>, HEIGHT> image_red;
   std::array<std::array<col32, WIDTH>, HEIGHT> image_blue;
   std::array<std::array<col32, WIDTH>, HEIGHT> image_green;
   fill_image(image_red, colour::red);
   fill_image(image_blue, colour::blue);
   fill_image(image_green, colour::green);

   save_image_as_ppm(image_red, path_red);
   save_image_as_ppm(image_blue, path_blue);
   save_image_as_ppm(image_green, path_green);
   std::cout<<"i'm still working UwU, but barely...\n";
   return 0;
}
