add_library(camera STATIC src/camera.cpp)
target_include_directories(camera PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(camera core light world)

add_executable(camera_tests
               test/camera_pixel_size_test.cpp
               test/camera_ray_construction_test.cpp
               test/camera_render_test.cpp
               )
target_link_libraries(camera_tests PRIVATE camera utils Catch2::Catch2WithMain)
