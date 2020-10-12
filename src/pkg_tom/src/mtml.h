#ifndef MTML_H
#define MTML_H

//various notes
//reading homing position: check robot status? ARM_HOMED (for very few ns)?
//renable teleop after master movement: check goal reached? it doesn't work (it is setted to true in some portion of the "labirintic" dVRK code)
//other interesting topics
//topic status: ?
//topic set base frame: ?
//topic set desire state: ?

#include "ros/ros.h"

#include <std_msgs/Bool.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Pose.h>
#include <tf_conversions/tf_kdl.h>

#include <kdl/frames.hpp>

class mtml
{

    // ros::Subscriber pose_goal_reached_sub;
    ros::Subscriber current_pose_sub;

    ros::Publisher pose_pub; //maybe not the best identifier name
    // ros::Publisher pose_goal_reached_pub;
    ros::Publisher enable_disable_teleop_pub;

    bool pose_goal_reached;
    KDL::Frame current_pose;
    const KDL::Vector homing_position{0.179812089165,0.0165389167399,0.411596749171}; //to be changed! Doesn't take into account the height of the master console. 
    //Ideal: read somewhere the homing value from config file. Better: consider local position and use transformation. !!!Check on the dVRK status (e.g. ready)!!!

public:

    mtml(ros::NodeHandle*);

    void currentPoseCallBack(const geometry_msgs::PoseStampedConstPtr&);
    // void poseGoalReachedCallBack(const std_msgs::BoolPtr&);

    void disableTeleop();
    void enableTeleop();
    void setHomingPosition();

    KDL::Frame getCurrentPose();
};

#endif // MTML_H
