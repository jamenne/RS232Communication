#state required cmake version
cmake_minimum_required (VERSION 2.6)
#name the project
project (RS232)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")


#command to make LED2.cpp and name it LED
add_executable(RS232communicationMain RS232communicationMain.cpp RS232communication.cpp /home/xytable/src/XYTable/MotorControl.cpp)











