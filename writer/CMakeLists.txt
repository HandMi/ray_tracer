add_library(ppmwriter STATIC src/ppm_writer.cpp include/ppm_writer.h)
target_include_directories(ppmwriter PUBLIC include)
target_link_libraries(ppmwriter core)