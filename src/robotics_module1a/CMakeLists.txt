cmake_minimum_required(VERSION 2.8.3)
project(robotics_module1)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

# find dependecies
find_package(catkin REQUIRED COMPONENTS
  roscpp
  geometry_msgs
  #rospy
)
find_package(eigen_stl_containers REQUIRED)
find_package(tf2_eigen REQUIRED)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp geometry_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${tf2_eigen_INCLUDE_DIRS}
  )

include_directories(${eigen_stl_containers_INCLUDE_DIRS})


## Declare cpp executables
add_executable(my_controller src/pose_publisher.cpp)
add_dependencies(my_controller ${catkin_EXPORTED_TARGETS})
target_link_libraries(my_controller ${catkin_LIBRARIES})

## Declare cpp executables
add_executable(my_robot src/pose_subscriber.cpp)
add_dependencies(my_robot ${catkin_EXPORTED_TARGETS})
target_link_libraries(my_robot ${catkin_LIBRARIES})

## Declare cpp executables
add_executable(spawn_object_demo src/module1_positions.cpp)
add_dependencies(spawn_object_demo ${catkin_EXPORTED_TARGETS})
target_link_libraries(spawn_object_demo ${catkin_LIBRARIES})

## Declare cpp executables
add_executable(object_rotation_demo src/module1_rotations.cpp)
add_dependencies(object_rotation_demo ${catkin_EXPORTED_TARGETS})
target_link_libraries(object_rotation_demo ${catkin_LIBRARIES})

## Declare cpp executables
add_executable(turtlebot_rotation_demo src/rotate_turtlebot.cpp)
add_dependencies(turtlebot_rotation_demo ${catkin_EXPORTED_TARGETS})
target_link_libraries(turtlebot_rotation_demo ${catkin_LIBRARIES})

## Declare cpp executables
add_executable(can_rotation_demo src/rotate_can_example.cpp)
add_dependencies(can_rotation_demo ${catkin_EXPORTED_TARGETS})
target_link_libraries(can_rotation_demo ${catkin_LIBRARIES})

## Declare cpp executables
add_executable(can_transformation_demo src/can_transformation.cpp)
add_dependencies(can_transformation_demo ${catkin_EXPORTED_TARGETS})
target_link_libraries(can_transformation_demo ${catkin_LIBRARIES})

## Declare cpp executables
add_executable(setup_table src/setup_table.cpp)
add_dependencies(setup_table ${catkin_EXPORTED_TARGETS})
target_link_libraries(setup_table ${catkin_LIBRARIES})

## Declare cpp executables
add_executable(setup_table_v2 src/setup_table_v2.cpp)
add_dependencies(setup_table_v2 ${catkin_EXPORTED_TARGETS})
target_link_libraries(setup_table_v2 ${catkin_LIBRARIES})

