#include "test.hpp"  ///not used for now

TEST(Geometry, SANITY){
   ASSERT_EQ(true, true);
}

TEST(Geometry, distanceBetweenPoints){
   point p1{0,0};
   point p2{2,0};
   auto res = std::sqrt(2);
   auto dist = point::distance(p1, p2);
   ASSERT_EQ(std::trunc(dist), std::trunc(res));
}

