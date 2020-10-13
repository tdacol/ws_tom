#ifndef CONSOLE_H
#define CONSOLE_H

#include "ros/ros.h"

#include <std_msgs/Bool.h>

class console
{

    ros::Publisher enable_disable_teleop_pub; 

public:

    console(ros::NodeHandle*);

    void disableTeleop(); 
    void enableTeleop(); 

};

#endif // CONSOLE_H
