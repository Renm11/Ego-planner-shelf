#include "ros/ros.h"
#include "std_msgs/String.h"
#include <geometry_msgs/PointStamped.h>

// void chatterCallback(const geometry_msgs::PointStamped &msg)
// {
//     ROS_INFO("I heard x: [%s]", msg.point.x);
//     ROS_INFO("I heard y: [%s]", msg.point.y);
//     ROS_INFO("I heard z: [%s]", msg.point.z);
// }

int main(int argc, char **argv)
{
    ros::init(argc, argv, "searchGoal");
    ros::NodeHandle n;

   // ros::Subscriber sub = n.subscribe("/odovisualization/pose", 1000, chatterCallback);

    ros::Publisher chatter_pub = n.advertise<geometry_msgs::PointStamped>("/clicked_point", 1000);

    ros::Rate loop_rate(10);
    int count = 0;
    while (ros::ok())
    {

        //ROS_INFO("%s", msg.data.c_str());

        chatter_pub.publish(myPoint);
        ros::spinOnce();

        loop_rate.sleep();
        ++count;
    }
    	while (ros::ok()) 
	{ 
        // 广播
		pub.publish(myPoint);
	    ros::spinOnce(); 
		loop_rate.sleep(); 
	 } 
	retur

    return 0;
}
