#ifndef BICOAG_H
#define BICOAG_H

#include <iostream>

#include "ros/ros.h"
#include "sensor_msgs/Joy.h"

class bicoag
{
private:

    bool new_data=false;

    ros::NodeHandle nh;
    ros::Subscriber sub;

public:

    int data=0;

    bicoag()
    {
        sub = nh.subscribe("/dvrk/footpedals/bicoag", 1000, &bicoag::bicoagCallBack, this); // Metodo 3
        std::cout << "constructor called" << std::endl;
    }

    void bicoagCallBack(const sensor_msgs::JoyConstPtr& msg)
    {
        data=msg->buttons[0];
        new_data=true;
        ROS_INFO("I heard: [%d]", data);
    }

};

#endif // BICOAG_H
