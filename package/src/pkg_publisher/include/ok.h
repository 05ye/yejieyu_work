#ifndef OK_H
#define OK_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>

double current_x = 0.0;
double current_y = 0.0;
double current_yaw = 0.0;

void odomCallback(const nav_msgs::Odometry::ConstPtr& msg) {
    current_x = msg->pose.pose.position.x;
    current_y = msg->pose.pose.position.y;
    current_yaw = msg->pose.pose.orientation.w;
    ROS_INFO("x: %.2f, y: %.2f,w: %.2f", current_x, current_y, current_yaw);
}

#endif //OK_H
