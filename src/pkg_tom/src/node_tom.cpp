#include <iostream>
#include <thread>

#include <kdl/frames.hpp>

#include "ros/ros.h"
#include "sensor_msgs/Joy.h"

#include "console.h"
#include "mtm.h"
#include "bicoag.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "node_tom");

    ros::NodeHandle nh;

    console console_obj(&nh);
    mtm mtml_obj(&nh, "MTML");
    mtm mtmr_obj(&nh, "MTMR");
    bicoag bicoag_obj(&nh);

    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        if(bicoag_obj.getBicoagData() && bicoag_obj.getBicoagNewData()) 
        {            
            console_obj.disableTeleop();
            loop_rate.sleep();
            bicoag_obj.setBicoagNewDataToFalse();
            std::thread thread(&mtm::setHomingPosition, mtml_obj);
            mtmr_obj.setHomingPosition();
            thread.join();
            console_obj.enableTeleop();
        }
        loop_rate.sleep();
        ros::spinOnce();
    }

    return 0;
}
