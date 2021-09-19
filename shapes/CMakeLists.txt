add_library(shapes STATIC src/material.cpp src/sphere.cpp)
target_include_directories(shapes PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(shapes light)

add_executable(shapes_tests
               test/hit_test.cpp
               test/intersection_test.cpp
               test/material_lighting_test.cpp
               test/sphere_normal_test.cpp
               test/sphere_transformation_test.cpp
               )
target_link_libraries(shapes_tests PRIVATE shapes Catch2::Catch2WithMain)

catch_discover_tests(shapes_tests)
