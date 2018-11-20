#!/bin/sh
xterm -e "export ROBOT_INITIAL_POSE='-x 3.0 -y 5.0 -Y 1.0' && roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/workspace/catkin_ws/src/World/home_service.world" &
sleep 20
xterm -e "roslaunch turtlebot_gazebo gmapping_demo.launch" &
sleep 10
xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5
xterm -e "roslaunch turtlebot_teleop keyboard_teleop.launch"