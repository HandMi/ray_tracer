add_library(light INTERFACE)
target_include_directories(light INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(light INTERFACE core)

add_executable(light_tests
               test/position_test.cpp
               test/ray_creation_test.cpp
               test/ray_transformation_test.cpp
               )
target_link_libraries(light_tests PRIVATE light Catch2::Catch2WithMain)

catch_discover_tests(light_tests)
