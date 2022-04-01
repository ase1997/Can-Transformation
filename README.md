# Can-Transformation

## Type: Academic Individual Assignment

## Assginment Description
NCSU ECE 555 (Computer Control of Robots) ROS Assignment
  - Re-order 12 coke cans in a desired poses on a table while visualizing on Gazeboo simulation tool

## Dependencies:
  - Ubuntu Linux 20.04 LTS (Virtual Box on Windows 10)
  - ROS Neotic 
  - Python3/C++11 or above
  
## Tasks
  - Write CMake and launch files to spawn 12 coke cans at random poses and a table at x-y-z (1,0,0) rotated 90 degress about z-axis and its center is at (1,0,1.05) in Gazebo

![ase1997](https://github.com/ase1997/Can-Transformation/blob/main/random_cans.png)
<p align="center">
Figure 1. Objects Spawn.
</p>

  - Write a code to transform 12 coke cans in the following desired poses
  
![ase1997](https://github.com/ase1997/Can-Transformation/blob/main/ordered_cans.png)
<p align="center">
Figure 2. Desired Outcome.
</p>

  - Simulate/visualize the process on Gazeboo

## Running Code
  - open a terminal
  - 'git clone' to a workspace
  - cd to that workspace and catkin_make
  - source devel/setup.bash
  - roslaunch robotics_module1a module1.launch
  - open another terminal and source devel/setup.bash
  - rosrun robotics_module1 setup_table_v2 or settup_table

## Authors
Khoa Do

## Reference
N/A

## Additional Notes
N/A
