#include "chap03/Person.h"
#include "ros/init.h"
#include "ros/node_handle.h"
#include "ros/publisher.h"
#include "ros/rate.h"
#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "personPub");
  ros::NodeHandle n;
  ros::Publisher police = n.advertise<chap03::Person>("/Person_info", 10);
  ros::Rate loop_rate(1);
  chap03::Person person_msg;
  person_msg.age = 18;
  person_msg.name = "Tom";
  person_msg.sex = person_msg.male;
  while (ros::ok()) {
    police.publish(person_msg);
    ROS_INFO("Arrest this person: name:%s\tsex:%d\tage:%d",person_msg.name.c_str(),person_msg.sex,person_msg.age);
    loop_rate.sleep();
    ros::spin();
  }
  return 0;
}