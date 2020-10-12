#include "mtml.h"

mtml::mtml(ros::NodeHandle* nh)
{
    mtml::current_pose_sub = nh->subscribe("/dvrk/MTML/position_cartesian_current", 1000, &mtml::currentPoseCallBack, this);
    // mtml::pose_goal_reached_sub = nh->subscribe("/dvrk/MTML/goal_reached", 1000, &mtml::poseGoalReachedCallBack, this);

    mtml::pose_pub = nh->advertise<geometry_msgs::Pose>("/dvrk/MTML/set_position_goal_cartesian",1000);
    // mtml::pose_goal_reached_pub = nh->advertise<std_msgs::Bool>("/dvrk/MTML/goal_reached",1000);
    mtml::enable_disable_teleop_pub = nh->advertise<std_msgs::Bool>("/dvrk/console/teleop/enable",1000);
}

void mtml::currentPoseCallBack(const geometry_msgs::PoseStampedConstPtr& msg)
{
    geometry_msgs::Pose pose_msg = msg->pose;
    tf::poseMsgToKDL(pose_msg, mtml::current_pose);
}

// void mtml::poseGoalReachedCallBack(const std_msgs::BoolPtr& msg)
// {
//     mtml::pose_goal_reached = msg->data;
// }

void mtml::disableTeleop()
{
    std_msgs::Bool msg;
    msg.data = false;
    mtml::enable_disable_teleop_pub.publish(msg);
}

void mtml::enableTeleop()
{
    std_msgs::Bool msg;
    msg.data = true;
    mtml::enable_disable_teleop_pub.publish(msg);
}

void mtml::setHomingPosition()
{
    ros::Time begin_time=ros::Time::now();

    mtml::disableTeleop();
    KDL::Frame homing_pose;
    homing_pose.p = mtml::homing_position;
    homing_pose.M = mtml::current_pose.M;
    geometry_msgs::Pose pose_msg;
    tf::PoseKDLToMsg(homing_pose, pose_msg);
    mtml::pose_pub.publish(pose_msg);
    ROS_INFO("mtml homing");

    while(ros::Time::now()-begin_time<ros::Duration(3.0)) {std::cout << (ros::Time::now()-begin_time).toSec() << std::endl;}

    // while(!mtml::pose_goal_reached) { std::cout << "wait" << std::endl; } //add time control, thread?
    // std_msgs::Bool bool_msg;
    // bool_msg.data = false;
    // mtml::pose_goal_reached_pub.publish(bool_msg);

    mtml::enableTeleop();
}

KDL::Frame mtml::getCurrentPose()
{
    return mtml::current_pose;
}


