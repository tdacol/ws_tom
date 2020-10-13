#include "bicoag.h"

bicoag::bicoag(ros::NodeHandle* nh)
{
    sub = nh->subscribe("/dvrk/footpedals/bicoag", 1000, &bicoag::callBack, this); 
}

void bicoag::callBack(const sensor_msgs::JoyConstPtr& msg)
{
    bicoag::data=msg->buttons[0];
    bicoag::new_data=true;
    if(bicoag::data)
        ROS_INFO("bicoag pressed");
    else
        ROS_INFO("bicoag released");
    
}

int bicoag::getBicoagData()
{
    return bicoag::data;
}

bool bicoag::getBicoagNewData()
{
    return bicoag::new_data;
}

void bicoag::setBicoagNewDataToFalse()
{
    bicoag::new_data=false;
}
