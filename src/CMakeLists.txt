set(SOURCES
   main.cpp
   )

set(GEOMETRY_SOURCES
   geometry.cpp
   ${INC}/geometry.h
   )

set(CANVAS_SOURCES
   canvas.cpp
   ${INC}/canvas.h
   )

add_library(geometry
   ${GEOMETRY_SOURCES}
   )  

add_library(canvas
   ${CANVAS_SOURCES}
   )

target_include_directories(geometry
   PUBLIC
   ${INC}
   )

target_include_directories(canvas
   PUBLIC
   ${INC}
   )

add_executable(${PROJECT_NAME}
   ${SOURCES}
   )

target_include_directories(${PROJECT_NAME}
   PUBLIC
   ${INC}
   )

target_link_libraries(canvas
   geometry)

target_link_libraries(${PROJECT_NAME}
   canvas
   )
