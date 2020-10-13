#include "console.h"

console::console(ros::NodeHandle* nh)
{
    console::enable_disable_teleop_pub = nh->advertise<std_msgs::Bool>("/dvrk/console/teleop/enable", 1000);
}

void console::disableTeleop()
{
    std_msgs::Bool msg;
    msg.data = false;
    console::enable_disable_teleop_pub.publish(msg);
    ROS_INFO("teleop disabled");
}

void console::enableTeleop()
{
    std_msgs::Bool msg;
    msg.data = true;
    console::enable_disable_teleop_pub.publish(msg);
    ROS_INFO("teleop enabled");
}



