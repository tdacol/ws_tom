#include "bicoag.h"

bicoag::bicoag(ros::NodeHandle* nh)
{
    sub = nh->subscribe("/dvrk/footpedals/bicoag", 1000, &bicoag::callBack, this); // Metodo 3
//    std::cout << "constructor called" << std::endl;
}

void bicoag::callBack(const sensor_msgs::JoyConstPtr& msg)
{
    bicoag::data=msg->buttons[0];
    bicoag::new_data=true;
    ROS_INFO("bicoag: [%d]", bicoag::data);
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
