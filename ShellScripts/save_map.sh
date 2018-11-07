#!/bin/sh
xterm -e "rosrun map_server map_saver -f $(rospack find wall_follower)/map/home_service_map" 
