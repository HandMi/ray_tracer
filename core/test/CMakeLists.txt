add_executable(canvas_tests
               canvas/canvas_test.cpp
               )
target_link_libraries(canvas_tests PRIVATE core Catch2::Catch2WithMain)

add_executable(transformation_tests
               transformations/transform_chaining_test.cpp
               transformations/transform_rotation_test.cpp
               transformations/transform_scaling_test.cpp
               transformations/tuple_shearing_test.cpp
               transformations/tuple_rotation_test.cpp
               transformations/tuple_scaling_test.cpp
               transformations/tuple_translation_test.cpp
               )
target_link_libraries(transformation_tests PRIVATE core Catch2::Catch2WithMain)

add_executable(tuple_tests
               tuple/color_operator_test.cpp
               tuple/tuple_function_test.cpp
               tuple/tuple_matrix_multiplication_test.cpp
               tuple/tuple_operator_test.cpp
               )

target_link_libraries(tuple_tests PRIVATE core Catch2::Catch2WithMain)
catch_discover_tests(canvas_tests)
catch_discover_tests(transformation_tests)
catch_discover_tests(tuple_tests)