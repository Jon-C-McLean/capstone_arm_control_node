cmake_minimum_required(VERSION 3.0.2)
project(arm_control)

find_package(catkin REQUIRED COMPONENTS
  can_msgs
  geometry_msgs
  roscpp
  rospy
  sensor_msgs
  socketcan_bridge
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS
  roscpp
  std_msgs
  sensor_msgs
  can_msgs
  geometry_msgs
  socketcan_bridge
)

include_directories(
  include/capstone_hwlib
  ${catkin_INCLUDE_DIRS}
)

add_library(
  hwlib
  include/capstone_hwlib/canio.c
  include/capstone_hwlib/motor.c
)
target_link_libraries(
  hwlib
  ${catkin_LIBRARIES}
)

add_executable(${PROJECT_NAME}
  src/main.cpp
)

target_link_libraries(
  ${PROJECT_NAME}
  ${catkin_LIBRARIES}
  hwlib
)