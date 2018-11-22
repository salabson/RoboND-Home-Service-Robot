# RoboND-Home-Service-Robot

### How to clone this repository
```
$ ~/catkin_ws/src

$ git clone https://github.com/salabson/RoboND-Home-Service.git
```

Import these packages now and install them in the src directory of your catkin workspace. Be sure to clone the full GitHub directory and not just the package itself.

1. **gmapping**: With the gmapping_demo.launch file, you can easily perform SLAM and build a map of the environment with a robot equipped with laser range finder sensors or RGB-D cameras.
2. **turtlebot_teleop**: With the keyboard_teleop.launch file, you can manually control a robot using keyboard commands.
3. **turtlebot_rviz_launchers**: With the view_navigation.launch file, you can load a preconfigured rviz workspace. You’ll save a lot of time by launching this file, because it will automatically load the robot model, trajectories, and map for you.
4. **turtlebot_gazebo**: With the turtlebot_world.launch you can deploy a turtlebot in a gazebo environment by linking the world file to it.

### Install ROS Navigation System
```
$ sudo apt-get update

$ sudo apt-get install ros-kinetic-navigation 
```
### Install xterm
```
$ sudo apt-get install xterm
```
### Build Catkin Workspace
```
$ ~/catkin_ws

$ catkin_make
```
### Source Development Folder
```
$ echo "source ~/catkin_ws/devel/setup.bash/" >> ~/.bashrc
$ source ~/.bashrc
```

### How to use this repository
First change to ShellScripts directory

` $ ~/catkin_ws/src/ShellScripts`

### Test slam (mapping with keyboard)
`$ ./test_slam.sh`

### Test slam (autonomous mapping)
`$ ./wall_follower.sh`

### Test navigation
`$ ./test_navigation.sh`

### Saving map
`$ ./save_map.sh`

### Pick objects
`$ ./pick_object.sh`

### Add markers
`$ ./add_markers.sh`

### Home service
`$ ./test_slam.sh`
