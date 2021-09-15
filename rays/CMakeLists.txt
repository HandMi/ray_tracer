add_library(rays INTERFACE)
target_include_directories(rays INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(rays INTERFACE core)

add_executable(ray_tests
               test/position_test.cpp
               test/ray_creation_test.cpp
               test/ray_transformation_test.cpp
               )
target_link_libraries(ray_tests PRIVATE rays Catch2::Catch2WithMain)

catch_discover_tests(ray_tests)
