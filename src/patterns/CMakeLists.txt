add_library(patterns STATIC src/stripe.cpp)
target_include_directories(patterns PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(patterns core shapes)

add_executable(pattern_tests
               test/stripe_pattern_test.cpp
               )
target_link_libraries(pattern_tests PRIVATE patterns utils Catch2::Catch2WithMain)

catch_discover_tests(pattern_tests)