cmake_minimum_required(VERSION 3.10)

project(cv-hw2-m10815822)

set(OpenCV_DIR "C:\\opencv\\build")
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(hw2-m10815822
    src/hw2-m10815822.cpp
    src/projectivegeometry.cpp
)

target_link_libraries(hw2-m10815822 ${OpenCV_LIBS})
