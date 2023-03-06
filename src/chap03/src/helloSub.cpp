#include "ros/node_handle.h"
#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCalkBack(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("helloSub: %s",msg->data.c_str());
}


int main(int argc,char** argv)
{
    ros::init(argc,argv,"listener");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("chatter",100,chatterCalkBack);
    ros::spin();
    return 0;
}