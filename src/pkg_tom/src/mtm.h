#ifndef MTM_H
#define MTM_H

#include "ros/ros.h"

#include <kdl/frames.hpp>
#include <iostream>

#include "arm.h"

class mtm : public arm
{
public:

    mtm(ros::NodeHandle*, std::string);

};

#endif // MTM_H
