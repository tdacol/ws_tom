#include "arm.h"

arm::arm(ros::NodeHandle* nh, std::string type) : arm_type(type)
{
    std::string arm_namespace = "/dvrk/" + arm::arm_type;

    arm::current_pose_sub = nh->subscribe(arm_namespace + "/position_cartesian_current", 1000, &arm::currentPoseCallBack, this); //?
    arm::current_state_sub = nh->subscribe(arm_namespace + "/current_state", 1000, &arm::currentStateCallBack, this); //?

    arm::pose_pub = nh->advertise<geometry_msgs::Pose>(arm_namespace + "/set_position_goal_cartesian", 1000);
}

void arm::currentPoseCallBack(const geometry_msgs::PoseStampedConstPtr& msg)
{
    geometry_msgs::Pose pose_msg = msg->pose;
    tf::poseMsgToKDL(pose_msg, arm::current_pose);
}

void arm::currentStateCallBack(const std_msgs::StringConstPtr& msg)
{
    arm::current_state = msg->data;
}

void arm::setHomingPosition()
{
    ros::Time begin_time=ros::Time::now();
    if(arm::current_state.compare("READY")==0)
    {
        ROS_INFO(("homing " + arm_type + " aborted, arm is not ready!").c_str()); //?
        return;
    }
    KDL::Frame homing_pose;
    homing_pose.p = arm::homing_position;
    homing_pose.M = arm::current_pose.M;
    geometry_msgs::Pose pose_msg;
    tf::PoseKDLToMsg(homing_pose, pose_msg);
    arm::pose_pub.publish(pose_msg);
    ROS_INFO(("homing " + arm_type).c_str()); //?
    while(ros::Time::now()-begin_time<ros::Duration(3.0)) {}
}

KDL::Frame arm::getCurrentPose()
{
    return arm::current_pose;
}

std::string arm::getCurrentState()
{
    return arm::current_state;
}

