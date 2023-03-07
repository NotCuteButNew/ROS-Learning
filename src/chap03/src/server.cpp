#include "chap03/AddTwoInts.h"
#include "ros/init.h"
#include "ros/node_handle.h"
#include "ros/ros.h"
#include "ros/service_server.h"

typedef chap03::AddTwoInts adt;

bool add(adt::Response &res, const adt::Request &req) {
  res.sum = req.a + req.b;
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.sum);
}
int main(int argc, char **argv) {
  ros::init(argc, argv, "server");
  ros::NodeHandle n;
  ros::ServiceServer service = n.advertiseService("add_two_ints", add);
  ros::spin();
  return 0;
}
