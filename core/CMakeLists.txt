add_library(core INTERFACE)
target_include_directories(core INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

add_executable(core_tests
               test/canvas_test.cpp
               test/color_operator_test.cpp
               test/tuple_operator_test.cpp
               test/tuple_function_test.cpp
               )
target_link_libraries(core_tests PRIVATE core Catch2::Catch2WithMain)

catch_discover_tests(core_tests)