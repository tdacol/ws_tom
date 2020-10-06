#include <iostream>

#include "ros/ros.h"
#include "sensor_msgs/Joy.h"


int data;
bool new_data;

void bicoagCallBack(const sensor_msgs::JoyConstPtr& msg)
{
    data=msg->buttons[0];
    new_data=true;
    ROS_INFO("I heard: [%d]", data);
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "node_tom");
    ros::NodeHandle nh;
    ros::Rate loop_rate(1);
    ros::Subscriber bicoag_sub = nh.subscribe("/dvrk/footpedals/bicoag", 1000, bicoagCallBack);

    while(ros::ok())
    {
        loop_rate.sleep();
        ros::spinOnce();
    }

    return 0;
}
