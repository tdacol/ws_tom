#include "bicoag.h"

bicoag::bicoag()
{
    sub = nh.subscribe("/dvrk/footpedals/bicoag", 1000, &bicoag::bicoagCallBack, this); // Metodo 3
    std::cout << "constructor called" << std::endl;
}

void bicoag::bicoagCallBack(const sensor_msgs::JoyConstPtr& msg)
{
    bicoag::data=msg->buttons[0];
    bicoag::new_data=true;
    ROS_INFO("I heard: [%d]", bicoag::data);
}

int bicoag::getBicoagData()
{
    return bicoag::data;
}
