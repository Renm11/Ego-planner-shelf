#include "ros/ros.h"
#include "std_msgs/String.h"
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PointStamped.h>
#include <visualization_msgs/Marker.h>

#include <iostream>
#include <cmath>//C语言是math.h
#include <vector>

// int flag=1;
int flagTarget=0;//是否到达目标点，0为未到达，1为到达
float target_position_x=0;//实时位置
float target_position_y=0;
float target_position_z=0;
float target_orientation_x=0;//实时朝向
float target_orientation_y=0;
float target_orientation_z=0;
float target_orientation_w=0;


void chatterCallback( const geometry_msgs::PoseStamped &msg)
{
    // ROS_INFO_STREAM("------------------");
    // realtime_position_x=msg.pose.position.x;
    // realtime_position_y=msg.pose.position.y;
    // realtime_position_z=msg.pose.position.z;
    // realtime_orientation_x=msg.pose.orientation.x;
    // realtime_orientation_y=msg.pose.orientation.y;
    // realtime_orientation_z=msg.pose.orientation.z;
    // realtime_orientation_w=msg.pose.orientation.w;

    if(abs(abs(msg.pose.position.x)-10)<1 && abs(abs(msg.pose.position.y)-10)<1)
        flagTarget=1;
    ROS_INFO("I heard is x: %f",msg.pose.position.x);
    ROS_INFO("I heard is y: %f",msg.pose.position.y);
    ROS_INFO("I heard is z: %f",msg.pose.position.z);
    ROS_INFO("I heard is flagTarget: %i",abs(flagTarget));
    // ROS_INFO("I heard is globalx: %f",realtime_position_x);
    ROS_INFO_STREAM("---------------------");
}

int checktarget(){

}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "searchGoal");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("/odom_visualization/pose", 1000, chatterCallback);

    ros::Publisher chatter_pub = n.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 1000);
    // ros::Publisher chatter_pub = n.advertise<visualization_msgs::Marker>("/ego_planner_node/goal_point", 1000);

    //

    ros::Rate loop_rate(10);
    //int count = 0;

        vector<geometry_msgs::PoseStamped> targetvector;

        geometry_msgs::PoseStamped myPoint1;
        geometry_msgs::PoseStamped myPoint2;    

        myPoint1.header.seq=1;
        myPoint1.header.frame_id = "world";
        myPoint1.header.stamp = ros::Time();
        myPoint1.pose.position.x = 10;//globalx+step;
        myPoint1.pose.position.y = 10;
        myPoint1.pose.position.z = 1.0;
        myPoint1.pose.orientation.x = 0;
        myPoint1.pose.orientation.y = 0;
        myPoint1.pose.orientation.z = 1;
        myPoint1.pose.orientation.w = 0;
        target_vector.push_back(myPoint1);

        myPoint1.header.seq=2;
        myPoint2.header.frame_id = "world";
        myPoint2.header.stamp = ros::Time();
        myPoint2.pose.position.x = -10;//globalx+step;
        myPoint2.pose.position.y = -10;
        myPoint2.pose.position.z = 1.0;
        myPoint2.pose.orientation.x = 0;
        myPoint2.pose.orientation.y = 0;
        myPoint2.pose.orientation.z = 1;
        myPoint2.pose.orientation.w = 0;
        target_vector.push_back(myPoint2);
        
        geometry_msgs::PoseStamped point;

        if(target_vector){}
            point=target_vector.front();
 
    	while (ros::ok())         
	{ 
        
        if(flagTarget)
            {
                chatter_pub.publish(myPoint2);
            }
        else{
                chatter_pub.publish(myPoint1);
            }
            // chatter_pub.publish(myPoint2);
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