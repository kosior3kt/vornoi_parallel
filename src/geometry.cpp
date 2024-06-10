#include "geometry.h"

float point::distance(const point& _a, const point& _b){
   return std::sqrt((std::abs(_a.x - _b.x))^2 + (std::abs(_a.y - _b.y))^2 );
};

point point::get_random(const col32& _col, const size_t& _rad){
   std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dis_wid(5,WIDTH - 5); // distribution in range [1, 6]
    std::uniform_int_distribution<std::mt19937::result_type> dis_hei(5,HEIGHT- 5); // distribution in range [1, 6]

    int x = dis_hei(rng);
    int y = dis_wid(rng);

   return std::forward<point>(point{x, y, _col, _rad});
}

