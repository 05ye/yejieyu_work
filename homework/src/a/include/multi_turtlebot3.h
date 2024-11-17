//
// Created by ye on 24-11-16.
//

#ifndef MULTI_YURTLEBOT3_H
#define MULTI_YURTLEBOT3_H

#include "ros/ros.h"
#include "tf2_ros/transform_broadcaster.h"
#include "tf2/LinearMath/Quaternion.h"
#include "geometry_msgs/TransformStamped.h"
#include <nav_msgs/Odometry.h>
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/Twist.h"
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <iostream>
#include <cmath>

void broadcastTf1(const nav_msgs::Odometry::ConstPtr& msg){
    static tf2_ros::TransformBroadcaster broadcaster;
    geometry_msgs::TransformStamped tfs;

    tfs.header.stamp = ros::Time::now();
    tfs.header.frame_id = "odom";
    tfs.child_frame_id = "tb3_0/base_footprint";

    tfs.transform.translation.x = msg->pose.pose.position.x;
    tfs.transform.translation.y = msg->pose.pose.position.y;
    tfs.transform.translation.z = msg->pose.pose.position.z;
    tfs.transform.rotation.w = msg->pose.pose.orientation.w;

    tfs.transform.rotation.x = msg->pose.pose.orientation.x;
    tfs.transform.rotation.y = msg->pose.pose.orientation.y;
    tfs.transform.rotation.z = msg->pose.pose.orientation.z;
    tfs.transform.rotation.w = msg->pose.pose.orientation.w;

    broadcaster.sendTransform(tfs);
}
void broadcastTf2(const nav_msgs::Odometry::ConstPtr& msg)
{
    static tf2_ros::TransformBroadcaster broadcaster;
    geometry_msgs::TransformStamped tfs;

    tfs.header.stamp = ros::Time::now();
    tfs.header.frame_id = "odom";
    tfs.child_frame_id = "tb3_1/base_footprint";

    tfs.transform.translation.x = msg->pose.pose.position.x;
    tfs.transform.translation.y = msg->pose.pose.position.y;
    tfs.transform.translation.z = msg->pose.pose.position.z;

    tfs.transform.rotation.x = msg->pose.pose.orientation.x;
    tfs.transform.rotation.y = msg->pose.pose.orientation.y;
    tfs.transform.rotation.z = msg->pose.pose.orientation.z;
    tfs.transform.rotation.w = msg->pose.pose.orientation.w;

    broadcaster.sendTransform(tfs);
}

#endif //MULTI_YURTLEBOT3_H
