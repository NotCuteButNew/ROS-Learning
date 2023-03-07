#include "ros/init.h"
#include "ros/node_handle.h"
#include "ros/ros.h"
#include "chap03/Person.h"

void BhCallback(const chap03::Person::ConstPtr& msg)
{
    ROS_INFO("Roger that,suspect information: name:%s\tsex:%d\tage:%d",msg->name.c_str(),msg->sex,msg->age);
    return ;
}

int main(int argc,char** argv)
{
    ros::init(argc,argv,"Bounty_Hunter");
    ros::NodeHandle n;
    ros::Subscriber Bh = n.subscribe("/Person_info",10,BhCallback);
    ros::spin();
    return 0;
}