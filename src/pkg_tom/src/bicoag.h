#ifndef BICOAG_H
#define BICOAG_H

#include <iostream>

#include "ros/ros.h"
#include "sensor_msgs/Joy.h"

class bicoag
{
private:

    int data=0;
    bool new_data=false;

    ros::NodeHandle nh;
    ros::Subscriber sub;

public:

    bicoag();

    void bicoagCallBack(const sensor_msgs::JoyConstPtr&);

    int getBicoagData();
};

#endif // BICOAG_H
