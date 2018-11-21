#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "pick_objects");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);
  
  // set robot state in parameter server
  ros::param::set("/robot_state", "start_point");

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal pickup_goal;
  move_base_msgs::MoveBaseGoal dropoff_goal;


  // set up the frame parameters
  pickup_goal.target_pose.header.frame_id = "map";
  pickup_goal.target_pose.header.stamp = ros::Time::now();
  
  dropoff_goal.target_pose.header.frame_id = "map";
  dropoff_goal.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach pickup goal
  pickup_goal.target_pose.pose.position.x = 1.16;
  pickup_goal.target_pose.pose.position.y = 0.61;
  pickup_goal.target_pose.pose.orientation.w =0.99;
  
     
  // Define a position and orientation for the robot to reach drop off goal
  dropoff_goal.target_pose.pose.position.x = 0.4;
  dropoff_goal.target_pose.pose.position.y = 0.8;
  dropoff_goal.target_pose.pose.orientation.w = 0.99;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending pickup goal");
  ac.sendGoal(pickup_goal);
  
  

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Hooray, robot reached pickup goal");
    // set robot state in parameter server
 	 ros::param::set("/robot_state", "picked_up");
  }
  else {
    ROS_INFO("The robot failed to reached pickup goal for some reason");
  	// set robot state in parameter server
 	 ros::param::set("/robot_state", "fail_to_pickup");
  }
  
  // Wait for 5 seconds
  ros::Duration(5.0).sleep();
 
   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending dropoff goal");
  ac.sendGoal(dropoff_goal);
  
   // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
    ROS_INFO("Hooray, robot reached dropoff goal");
  	// set robot state in parameter server
  	ros::param::set("/robot_state", "dropped_off");
  }
  else {
    ROS_INFO("The robot failed to reached dropoff goal for some reason");
  	// set robot state in parameter server
 	 ros::param::set("/robot_state", "fail_to_dropoff");
  }
  
  

  return 0;
}