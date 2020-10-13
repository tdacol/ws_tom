#ifndef ARM_H
#define ARM_H

//various notes
//reading homing position: check robot status? ARM_HOMED (for very few ns)?
//enable teleop after master movement: check goal reached? it doesn't work (it is setted to true in some portion of the "labirintic" dVRK code)
//other interesting topics
//topic status: ?
//topic set base frame: ?
//topic set desire state: ?

#include "ros/ros.h"

#include <std_msgs/Bool.h>
#include <std_msgs/String.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Pose.h>
#include <tf_conversions/tf_kdl.h>

#include <iostream>
#include <kdl/frames.hpp>

class arm
{

    ros::Subscriber current_pose_sub;
    ros::Subscriber current_state_sub;

    ros::Publisher pose_pub; 

    std::string current_state;
    KDL::Frame current_pose;

protected:

    std::string arm_type;
    KDL::Vector homing_position; 

public:

    arm(ros::NodeHandle*,std::string);

    void currentPoseCallBack(const geometry_msgs::PoseStampedConstPtr&);
    void currentStateCallBack(const std_msgs::StringConstPtr&);

    void setHomingPosition();

    KDL::Frame getCurrentPose();
    std::string getCurrentState();

};

#endif // ARM_H
