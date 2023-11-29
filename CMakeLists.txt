cmake_minimum_required(VERSION 3.27)
project(FinalProject)

set(CMAKE_CXX_STANDARD 20)

# Add your source files
file(GLOB_RECURSE SOURCES "FinalProject/*.cpp" "FinalProject/*.h")

# Add OpenCV include and link directories
set(OpenCV_DIR "C:/opencv/build")  # Adjust the path accordingly
find_package(OpenCV 4.8 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Add your executable
add_executable(FinalProject ${SOURCES})
target_link_libraries(FinalProject ${OpenCV_LIBS})