#include "ros/forwards.h"
#include "ros/init.h"
#include "ros/rate.h"
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv) {
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Rate loop_rate(10);
  std_msgs::String msg;
  std::stringstream ss;
  int count = 0;
  while (ros::ok()) {
    ss<<"hello world !"<<count;
    msg.data = ss.str();
    ROS_INFO("i am helloPub, can u here me ?");
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
  return 0;
}