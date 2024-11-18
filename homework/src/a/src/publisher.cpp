//
// Created by ye on 24-11-15.
//
#include "multi_turtlebot3.h"
int main(int argc, char **argv){
  ros::init(argc, argv, "publisher");
  ros::NodeHandle nh;
  ros::Subscriber sub1 = nh.subscribe("/tb3_0/odom",1000,broadcastTf1);
  ros::Subscriber sub2 = nh.subscribe("/tb3_1/odom",1000,broadcastTf2);
  ros::spin();
  return 0;
}