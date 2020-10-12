#include <iostream>
#include <kdl/frames.hpp>

#include "ros/ros.h"
#include "sensor_msgs/Joy.h"

#include "bicoag.h"
#include "mtml.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "node_tom");

    ros::NodeHandle nh;

    bicoag bicoag_obj(&nh);
    mtml mtml_obj(&nh);

    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        if(bicoag_obj.getBicoagData()&&bicoag_obj.getBicoagNewData()) //maybe not the best solution, alternative will be to have a data member seq to be used for the control condition
        {
            bicoag_obj.setBicoagNewDataToFalse(); 
            mtml_obj.setHomingPosition();
        }
        loop_rate.sleep();
        ros::spinOnce();
    }

    return 0;
}
