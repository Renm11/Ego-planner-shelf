#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "listener");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

    ros::spin();

    return 0;
}

#1.获取里程计

#2.识别目标点，穿梭


rostopic pub /clicked_point geometry_msgs/PointStamped \ '{header: {frame_id: "map"},point: {x: 7.79252910614,y: -0.434817790985,z: 0.00178050994873}}'

rostopic pub /clicked_point geometry_msgs/PointStamped \ '{header: {frame_id: "map"},point: {x: 8.09252910614,y: -0.434817790985,z: 0.00178050994873}}'
