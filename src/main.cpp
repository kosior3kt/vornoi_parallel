#include <iostream>
#include "canvas.h"
#include "defines.h"
#include <vector>

int main(void){

   std::vector<point> points;

   canvas image_black;
   fill_image(image_black, colour::black);

   for(int i = 0; i < SEED_NUMBER; ++i){
      points.push_back(point::get_random());
   }
///merge this later
   
   //color_image();
   draw_Voranoi(image_black, points);

   for(auto p : points)
   {
      add_point(image_black, p);
   };

   save_image_as_ppm(image_black, "res/res.ppm");
   std::cout<<"i'm still working UwU, but barely...\n";
   return 0;
}
