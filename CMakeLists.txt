
cmake_minimum_required(VERSION 3.10)
project(ImageFilters)
set(CMAKE_CXX_STANDARD 20)

find_package(PNG REQUIRED)

find_package(TBB REQUIRED)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")
add_executable(image_filters ${SOURCES}
       src/png_utils.cpp
)
target_link_libraries(image_filters PRIVATE PNG::PNG)
target_link_libraries(image_filters PRIVATE TBB::tbb)