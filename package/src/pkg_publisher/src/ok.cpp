#include "ok.h"
int main(int argc, char** argv) {
    ros::init(argc, argv, "car_controller");
    ros::NodeHandle nh;
    ros::Publisher cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 10);
    ros::Subscriber odom_sub = nh.subscribe("odom", 10, odomCallback);
    geometry_msgs::Twist cmd_vel_msg;
    ros::Rate loop_rate(100);
    while (ros::ok()) {
        if (current_x < 0.54) {
            // 朝 A 点运动
            cmd_vel_msg.linear.x = 0.1; // 设置前进速度
            cmd_vel_msg.angular.z = 0.0;
        } else if (current_yaw > 0.76) {
            // 转弯
            cmd_vel_msg.linear.x = 0.0;
            cmd_vel_msg.angular.z = -0.1; // 设置适当的转向速度
        } else if (current_y > -1.63) {
            // 到达 B 点，停止
            cmd_vel_msg.linear.x = 0.1;
            cmd_vel_msg.angular.z = 0.0;
        } else {
          cmd_vel_msg.linear.x = 0.0;
          cmd_vel_msg.angular.z = 0.0;
        }
        cmd_vel_pub.publish(cmd_vel_msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}