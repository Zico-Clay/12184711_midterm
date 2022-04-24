#include "ros/ros.h"

#include "std_msgs/Float32.h"

float SPEED;
float PLATE_NUMBER = 4768;
ros::Publisher speed_check;


void subCallback(const std_msgs::Float32::ConstPtr& speed_limit)
{

  ros::NodeHandle callback_node_handle;

  if (callback_node_handle.getParam("speed", SPEED))
  {
    std_msgs::Float32 over_speed_msg;
    
    if (SPEED > speed_limit->data)
    {
      over_speed_msg.data = PLATE_NUMBER;
      speed_check.publish(over_speed_msg);
      
    }
  }
  else
  {
    ROS_WARN("No value set for speed parameter.");
  }


}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "speed_check_node");

  ros::NodeHandle node_handle;

  speed_check = node_handle.advertise<std_msgs::Float32>("speed", 10);

  ros::Subscriber speed_limit = node_handle.subscribe("speed_limit", 10, subCallback);

  ros::spin();

  return 0;
}
