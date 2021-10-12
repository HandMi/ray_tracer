add_library(light STATIC src/point_light.cpp src/square_light.cpp)
target_include_directories(light PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(light PUBLIC core shapes world)

add_executable(light_tests
               test/material_lighting_test.cpp
               test/point_light_intensity_test.cpp
               test/position_test.cpp
               test/ray_creation_test.cpp
               test/ray_transformation_test.cpp
               test/soft_shadow_test.cpp
               )
target_link_libraries(light_tests PRIVATE light utils Catch2::Catch2WithMain)

catch_discover_tests(light_tests)
