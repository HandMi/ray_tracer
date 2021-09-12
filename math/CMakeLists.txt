add_library(math INTERFACE)
target_include_directories(math INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(math INTERFACE utils)

add_executable(math_tests
               test/matrix_creation_test.cpp
               test/matrix_determinant_test.cpp
               test/matrix_inversion_test.cpp
               test/matrix_multiplication_test.cpp
               test/matrix_submatrix_test.cpp
               test/matrix_transpose_test.cpp
               )
target_link_libraries(math_tests PRIVATE math Catch2::Catch2WithMain)

catch_discover_tests(math_tests)