#include "ros/ros.h"
#include "std_msgs/String.h"
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PointStamped.h>
#include <visualization_msgs/Marker.h>

int flag=1;
float globalx=0;
float globaly=0;
float globalz=0;

void chatterCallback(const geometry_msgs::PoseStamped &msg)
{

    if (flag==1)
    {
        globalx=msg.pose.position.x;
        globaly=msg.pose.position.y;
        globalz=msg.pose.position.z;
        flag=0;
    }
    
    // globalx=msg.pose.position.x;
    // globaly=msg.pose.position.y;
    // globalz=msg.pose.position.z;
    ROS_INFO("I heard is x: %f",msg.pose.position.x);
    ROS_INFO("I heard is y: %f",msg.pose.position.y);
    ROS_INFO("I heard is z: %f",msg.pose.position.z);
    ROS_INFO("I heard is globalx: %f",globalx);
    ROS_INFO_STREAM("------------------");
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "searchGoal");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("/odom_visualization/pose", 1000, chatterCallback);

    // ros::Publisher chatter_pub = n.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 1000);
    ros::Publisher chatter_pub = n.advertise<visualization_msgs::Marker>("/ego_planner_node/goal_point", 1000);

    //

    ros::Rate loop_rate(10);
    //int count = 0;
        visualization_msgs::Marker myPoint1;
        // geometry_msgs::PoseStamped myPoint2;
        // chatter_pub.publish(myPoint1) ;
         // chatter_pub.publish(myPoint2);
        //等高走十米
        int a=1;
        int step=-1;
 
    	while (ros::ok()) 
	{ 
        // 广播
        // myPoint2.header.frame_id = "world";
        // myPoint2.header.stamp = ros::Time();
        // myPoint2.pose.position.x = globalx+step;
        // myPoint2.pose.position.y = 0;
        // myPoint2.pose.position.z = 1.0;
        // myPoint2.pose.orientation.x = 0;
        // myPoint2.pose.orientation.y = 0;
        // myPoint2.pose.orientation.z = 1;
        // myPoint2.pose.orientation.w = 0;
        myPoint1.header.frame_id = "world";
        myPoint1.header.stamp = ros::Time();
        myPoint1.header.seq = 0;
        myPoint1.pose.position.x = 4;//globalx+step;
        myPoint1.pose.position.y = 0;
        myPoint1.pose.position.z = 1.0;
        myPoint2.pose.orientation.x = 0;
        myPoint1.pose.orientation.y = 0;
        myPoint2.pose.orientation.z = 1;
        myPoint2.pose.orientation.w = 0;
		if (a==1)
        {
        chatter_pub.publish(myPoint1);
        }
	    ros::spinOnce(); 
		loop_rate.sleep(); 
	 }
    //   ros::spin();

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