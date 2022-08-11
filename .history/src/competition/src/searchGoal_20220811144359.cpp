#include "ros/ros.h"
#include "std_msgs/String.h"
#include <geometry_msgs/PoseStamped.h>

float x=0;
float y=0;
float z=0;

void chatterCallback(const geometry_msgs::PoseStamped &msg)
{
    ROS_INFO("I heard x: %f",msg.pose.position.x);
    ROS_INFO("I heard y: %f",msg.pose.position.y);
    ROS_INFO("I heard z: %f",msg.pose.position.z);
    ROS_INFO_STREAM("------------------");
    x

}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "searchGoal");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("/odom_visualization/pose", 1000, chatterCallback);

    ros::Publisher chatter_pub = n.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 1000);

    ros::Rate loop_rate(10);
    //int count = 0;
        // geometry_msgs::PointStamped myPoint1;
        geometry_msgs::PoseStamped myPoint2;
        // chatter_pub.publish(myPoint1) ;

    // 点的坐标 
        myPoint2.header.frame_id = "world";
        myPoint2.header.stamp = ros::Time();
        myPoint2.pose.position.x = -1.0;
        myPoint2.pose.position.y = -1.0;
        myPoint2.pose.position.z = 1.0;
        myPoint2.pose.orientation.x = 0;
        myPoint2.pose.orientation.y = 0;
        myPoint2.pose.orientation.z = 1;
        myPoint2.pose.orientation.w = 0;
        
        // chatter_pub.publish(myPoint2);
        // chatter_pub.publish(myPoint2);
        int a=1;
 
    	while (ros::ok()) 
	{ 
        // 广播
		if (a==1)
        {
        chatter_pub.publish(myPoint2);
        }
	    ros::spinOnce(); 
		loop_rate.sleep(); 
	 }
      ros::spin();

    return 0;
}

    // tf_body_laser = geometry_msgs.msg.TransformStamped()
    // tf_body_laser.header.frame_id = "body"
    // tf_body_laser.header.stamp = rospy.Time(0)
    // tf_body_laser.child_frame_id = "laser"
    // tf_body_laser.transform.translation.x = 0.8
    // tf_body_laser.transform.translation.y = -0.2
    // tf_body_laser.transform.translation.z = 0.3
    // tf_body_laser.transform.rotation.w = 1
    // tf_body_laser.transform.rotation.x = 0
    // tf_body_laser.transform.rotation.y = 0
    // tf_body_laser.transform.rotation.z = 0