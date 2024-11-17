//
// Created by ye on 24-11-15.
//
#include "multi_turtlebot3.h"

int main(int argc, char **argv){
  ros::init(argc, argv, "subcriber");
  ros::NodeHandle n;

  tf2_ros::Buffer buffer;
  tf2_ros::TransformListener Listener(buffer);

  ros::Publisher pub=n.advertise<geometry_msgs::Twist>("tb3_1/cmd_vel", 1000);
  ros::Rate loop_rate=ros::Rate(10);
  while(ros::ok()){
    try
    {
      geometry_msgs::TransformStamped tfs = buffer.lookupTransform("tb3_1/base_link", "tb3_0/base_link", ros::Time(0));

      geometry_msgs::Twist cmd_vel;

      if ((fabs(tfs.transform.translation.x)+fabs(tfs.transform.translation.y)) > 0.3) {
        cmd_vel.linear.x = 0.5 * sqrt(pow(tfs.transform.translation.x,2) + pow(tfs.transform.translation.y,2));
        cmd_vel.angular.z = 2* atan2(tfs.transform.translation.y,tfs.transform.translation.x);
      } else {
        cmd_vel.linear.x = 0.0;
        cmd_vel.angular.z = 0.0;
      }
      pub.publish(cmd_vel);
   }
    catch (tf2::TransformException &ex) {
        ROS_WARN("%s", ex.what());
    }
    ros::spinOnce();
    loop_rate.sleep();
    }
    return 0;
  }