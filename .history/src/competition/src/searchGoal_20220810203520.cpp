#include "ros/ros.h"
#include "std_msgs/String.h"
#include <geometry_msgs/PointStamped.h>

void chatterCallback(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("I heard x: [%s]", msg->data.c_str());
    ROS_INFO("I heard y: [%s]", msg->data.c_str());
    ROS_INFO("I heard z: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "searchGoal");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("/odovisualization/pose", 1000, chatterCallback);

    ros::Publisher chatter_pub = n.advertise<<geometry_msgs::PointStamped>("/clicked_point", 1000);
    ros::Rate loop_rate(10);
    int count = 0;
    while (ros::ok())
    {
        geometry_msgs::PointStamped myPoint;

    // 点的坐标 
        myPoint.point.x = 11.0;
        myPoint.point.y = 11.0;
        myPoint.point.z = 11.0;

    // frame id
        myPoint.header.frame_id = "map";
        //ROS_INFO("%s", msg.data.c_str());

        chatter_pub.publish(myPoint);
        ros::spinOnce();

        loop_rate.sleep();
        ++count;
    }

    return 0;
}
