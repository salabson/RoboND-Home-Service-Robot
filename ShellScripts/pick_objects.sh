#!/bin/sh
xterm -e "export ROBOT_INITIAL_POSE='-x -6.0 -y 1.5 -Y 1.57079633' && roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/workspace/catkin_ws/src/World/home_service.world" &
sleep 5
xterm -e "roslaunch turtlebot_gazebo amcl_demo.launch map_file:=/home/workspace/catkin_ws/src/wall_follower/map/home_service_map.yaml" &
sleep 5
xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5
xterm -e "rosrun pick_objects pick_objects" 
