#!/bin/sh
xterm -e "export ROBOT_INITIAL_POSE='-x -6.0 -y Y 1.57079633' && roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/workspace/catkin_ws/src/World/home_service.world" &
sleep 10
xterm -e "roslaunch turtlebot_gazebo gmapping_demo.launch" &
sleep 10
xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5
xterm -e "rosrun wall_follower wall_follower"