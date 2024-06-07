set(SOURCES
   main.cpp
   )

add_executable(${PROJECT_NAME}
   ${SOURCES}
   )
target_include_directories(${PROJECT_NAME}
   PUBLIC
   ${INC}
   )


