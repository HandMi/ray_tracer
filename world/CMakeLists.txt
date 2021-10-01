add_library(world STATIC src/world.cpp)
target_include_directories(world PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(world shapes light)

add_executable(world_tests
               test/shading_test.cpp
               test/world_coloring_test.cpp
               test/world_intersection_test.cpp
               )
target_link_libraries(world_tests PRIVATE world utils Catch2::Catch2WithMain)
