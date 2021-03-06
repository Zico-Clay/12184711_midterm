#include "ros/ros.h"

#include "std_msgs/Float32.h"

const float SPEED_LIMIT = 60;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "speed_limit_node");

  ros::NodeHandle node_handle;

  ros::Publisher speed_limit = node_handle.advertise<std_msgs::Float32>("speed_limit", 10);

  ros::Rate pub_rate(10);

  ROS_INFO("Publishing SPEED_LIMIT...");

  while(ros::ok())
  {

    std_msgs::Float32 msg;

    msg.data = SPEED_LIMIT;

    speed_limit.publish(msg);

    pub_rate.sleep();
  }

}
