set(TEST_SOURCES
   main.cpp
   test.hpp
   test_geometry.cpp
   )

add_executable(geometry_test
   ${TEST_SOURCES}
   )

target_include_directories(geometry_test
   PUBLIC
   ${INC}
   )

find_package(GTest CONFIG REQUIRED)

target_link_libraries(geometry_test
   geometry
   GTest::gtest
   )
