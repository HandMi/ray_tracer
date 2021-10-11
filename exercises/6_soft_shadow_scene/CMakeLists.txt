add_executable(soft_shadow_scene main.cpp)
target_link_libraries(soft_shadow_scene PUBLIC camera ppmwriter shapes world)
