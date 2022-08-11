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

    ros::Publisher chatter_pub = n.advertise<geometry_msgs::PointStamped>("/move_base_simple/goal", 1000);

    ros::Rate loop_rate(10);
    //int count = 0;
        geometry_msgs::PointStamped myPoint1;
        geometry_msgs::PointStamped myPoint2;
        chatter_pub.publish(myPoint1) ;

    // 点的坐标 
        myPoint2.header.frame_id = "map";
        myPoint2.Point.position.x = 3.0;
        myPoint2.pose.position.y = 3.0;
        myPoint2.pose.position.z = 1.0;
        myPoint2.pose.orientation.x=0;
        myPoint2.pose.orientation.y=0;
        myPoint2.pose.orientation.z=1;
        myPoint2.pose.orientation.w=0;

    // frame id
        
        chatter_pub.publish(myPoint2);
 
    // 	while (ros::ok()) 
	// { 
    //     // 广播
	// 	chatter_pub.publish(myPoint);
	//     ros::spinOnce(); 
	// 	loop_rate.sleep(); 
	//  }

    return 0;
}
