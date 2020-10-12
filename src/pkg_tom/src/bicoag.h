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

    ros::Subscriber sub;

public:

    bicoag(ros::NodeHandle*);

    void callBack(const sensor_msgs::JoyConstPtr&);

    int getBicoagData();
    bool getBicoagNewData();
    void setBicoagNewDataToFalse();
};

#endif // BICOAG_H
