#include <iostream>

#include "ros/ros.h"
#include "sensor_msgs/Joy.h"

#include "bicoag.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "node_tom");

    bicoag bicoag_obj;

    ros::Rate loop_rate(1);

    while(ros::ok())
    {
        std::cout << bicoag_obj.getBicoagData() << std::endl;
        loop_rate.sleep();
        ros::spinOnce();
    }

    return 0;
}
