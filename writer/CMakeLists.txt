add_library(ppmwriter STATIC src/ppm_writer.cpp)
target_include_directories(ppmwriter PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(ppmwriter core)

add_executable(writer_tests
               test/ppm_writer_test.cpp
               )
target_link_libraries(writer_tests PRIVATE ppmwriter Catch2::Catch2WithMain)

catch_discover_tests(writer_tests)