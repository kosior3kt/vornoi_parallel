#include "canvas.h"



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

col32 get_colour(const point& _point){
   const point rand_point = point::get_random();   ///can't be that random, or must be cashed 
   auto salt = rand() % 6969;
   uint32_t retCol = _point.x * _point.y * _point.col * _point.radius * rand_point.x * rand_point.y * rand_point.col * rand_point.radius * salt * salt;
   ///should return uint32_t which vaguely reassambles colout (?)
   return retCol;
}

void draw_Voranoi(canvas& _im, const std::vector<point>& _points){

   std::array<col32, SEED_NUMBER> colours{};
   for(int y =0; y < WIDTH; ++y){
      for(int x =0; x< HEIGHT; ++x){
          ///look for distance from each of points here
         int p_closest = 0;
          for(int p = 1; p < SEED_NUMBER; ++p){
            if(
                  (x - _points[p_closest].x) * (x - _points[p_closest].x) + (y - _points[p_closest].y) * (y - _points[p_closest].y) >
                  (x - _points[p].x) * (x - _points[p].x) + (y - _points[p].y) * (y - _points[p].y)
              ) p_closest = p;
          }
            if(colours[p_closest] == 0) {
               colours[p_closest] = get_colour(_points[p_closest]);
            }
          _im[x][y] = colours[p_closest];
      }
   }

   //do compilers allow to treat 2d array as 1d?
}

void add_point(canvas& _im, const int& _width, const int& _height, const col32& _col, const int& _size){
   if(_width > WIDTH || _width < 0 || _height > HEIGHT || _height < 0) return;
   _im[_width][_height] = _col;
   for(int i = 0; i < _size; ++i)
   {
      for(int j = 0; j < _size; ++j){
         auto is_inside = [&](const int& _x, const int& _y)->bool{
            if(_x > HEIGHT || _x < 0 || _y > HEIGHT || _y < 0) return false;
            else return true;
         };
         if(is_inside(_width + i, _height + j))_im[_width + i][ _height + j] = _col;
         if(is_inside(_width - i, _height + j))_im[_width - i][ _height + j] = _col;
         if(is_inside(_width + i, _height - j))_im[_width + i][ _height - j] = _col;
         if(is_inside(_width - i, _height - j))_im[_width - i][ _height - j] = _col;
      }
   }
}

void draw_circle(canvas& _im, const point& _point){
   /// ......
   /// .###..
   /// .#@#..     ///so we need to get a sun square and then iterate over it. thne for each point in square if x^2 + y^2 < r^2 it is inside
   /// .###..
   /// ......

   auto x1 = _point.x - _point.radius;
   auto y1 = _point.y - _point.radius;
   auto x2 = _point.x + _point.radius;
   auto y2 = _point.y + _point.radius;
   
   for(int i = x1; i < x2; ++i){ 
         for(int j = y1; j < y2; ++j){
            if((i-_point.x) * (i-_point.x) + (j-_point.y) * (j-_point.y) < _point.radius * _point.radius) _im[i][j] = _point.col;
         }
   }
}


void add_point(canvas& _im, const point& _point)
{
   _im[_point.x][_point.y] = _point.col;
   for(int i = 0; i < _point.radius; ++i)
   {
      for(int j = 0; j < _point.radius; ++j){

         auto is_inside = [&](const int& _x, const int& _y)->bool{
            return !(_x > HEIGHT || _x < 0 || _y > HEIGHT || _y < 0);
         };
         // if(is_inside(_point.x + i, _point.y + j))_im[_point.x + i][ _point.y + j] = _point.col;
         // if(is_inside(_point.x - i, _point.y + j))_im[_point.x - i][ _point.y + j] = _point.col;
         // if(is_inside(_point.x + i, _point.y - j))_im[_point.x + i][ _point.y - j] = _point.col;
         // if(is_inside(_point.x - i, _point.y - j))_im[_point.x - i][ _point.y - j] = _point.col;
         
         draw_circle(_im, _point);
      }
   }
}

void add_line(canvas& _im, line& _line){
                   
};





void save_image_as_ppm(const canvas& _im, std::string _path){  
   std::ofstream file(_path);
   file<<"P3\n"<< std::to_string(WIDTH)<<" "<< std::to_string(HEIGHT)<<std::endl;
   file<<255<<std::endl;
   for(auto col : _im)
   {
      for(col32 val : col)
      {
         ///val saved as RRR GGG BBB where each of those is a number from 0 - 255. next line in next pixel

         uint8_t red    =  (val >> 8*2) & 0xFF;
         uint8_t green  =  (val >> 8*1) & 0xFF;
         uint8_t blue   =  (val >> 8*0) & 0xFF;
         stream_to_file(file, red, green, blue);   ///some casual c++ magic
      }
      file<<"\n";
   }
   file.close();
}


