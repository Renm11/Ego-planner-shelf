#include "ros/ros.h"
#include "std_msgs/String.h"
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PointStamped.h>
#include <visualization_msgs/Marker.h>

#include <iostream>
#include <cmath>//C语言是math.h
#include <vector>
using namespace std;

int flagTarget=0;//是否到达目标点，0为未到达，1为到达
float realtime_position_x=0;//目标点位置
float realtime_position_y=0;
float realtime_position_z=0;
float realtime_orientation_x=0;//目标点朝向
float realtime_orientation_y=0;
float realtime_orientation_z=0;
float realtime_orientation_w=0;


void chatterCallback( const geometry_msgs::PoseStamped &msg)
{
    // ROS_INFO_STREAM("------------------");
    realtime_position_x=msg.pose.position.x;
    realtime_position_y=msg.pose.position.y;
    realtime_position_z=msg.pose.position.z;
    realtime_orientation_x=msg.pose.orientation.x;
    realtime_orientation_y=msg.pose.orientation.y;
    realtime_orientation_z=msg.pose.orientation.z;
    realtime_orientation_w=msg.pose.orientation.w;

    // if(abs(abs(msg.pose.position.x)-10)<1 && abs(abs(msg.pose.position.y)-10)<1)
    //     flagTarget=1;
    ROS_INFO("I heard is x: %f",realtime_position_x);
    ROS_INFO("I heard is y: %f",msg.pose.position.y);
    ROS_INFO("I heard is z: %f",msg.pose.position.z);
    // ROS_INFO("I heard is flagTarget: %i",abs(flagTarget));
    // ROS_INFO("I heard is globalx: %f",realtime_position_x);
    // ROS_INFO_STREAM("---------------------");
}

int checktarget(geometry_msgs::PoseStamped &point){
    if(abs(abs(point.pose.position.x)-realtime_position_x)<1 && abs(abs(point.pose.position.y)-realtime_position_y)<1){
        ROS_INFO_STREAM("-----dao damubiaodian----------");
        return 1;
    }
    else
        return 0;
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

        vector<geometry_msgs::PoseStamped> target_vector;

        geometry_msgs::PoseStamped myPoint1;
        geometry_msgs::PoseStamped myPoint2;
        geometry_msgs::PoseStamped myPoint3;
        geometry_msgs::PoseStamped myPoint4;      

        myPoint1.header.seq=1;
        myPoint1.header.frame_id = "world";
        myPoint1.header.stamp = ros::Time();
        myPoint1.pose.position.x = -10;//globalx+step;
        myPoint1.pose.position.y = 10;
        myPoint1.pose.position.z = 1.0;
        myPoint1.pose.orientation.x = 0;
        myPoint1.pose.orientation.y = 0;
        myPoint1.pose.orientation.z = 1;
        myPoint1.pose.orientation.w = 0;
        target_vector.insert(target_vector.begin(), myPoint1);

        myPoint1.header.seq=2;
        myPoint2.header.frame_id = "world";
        myPoint2.header.stamp = ros::Time();
        myPoint2.pose.position.x = 10;//globalx+step;
        myPoint2.pose.position.y = 10;
        myPoint2.pose.position.z = 1.0;
        myPoint2.pose.orientation.x = 0;
        myPoint2.pose.orientation.y = 0;
        myPoint2.pose.orientation.z = 1;
        myPoint2.pose.orientation.w = 0;
        target_vector.insert(target_vector.begin(), myPoint2);

        myPoint3.header.seq=3;
        myPoint3.header.frame_id = "world";
        myPoint3.header.stamp = ros::Time();
        myPoint3.pose.position.x = 10;//globalx+step;
        myPoint3.pose.position.y = -10;
        myPoint3.pose.position.z = 1.0;
        myPoint3.pose.orientation.x = 0;
        myPoint3.pose.orientation.y = 0;
        myPoint3.pose.orientation.z = 1;
        myPoint3.pose.orientation.w = 0;
        target_vector.insert(target_vector.begin(), myPoint3);

        myPoint4.header.seq=4;
        myPoint4.header.frame_id = "world";
        myPoint4.header.stamp = ros::Time();
        myPoint4.pose.position.x = -10;//globalx+step;
        myPoint4.pose.position.y = -10;
        myPoint4.pose.position.z = 1.0;
        myPoint4.pose.orientation.x = 0;
        myPoint4.pose.orientation.y = 0;
        myPoint4.pose.orientation.z = 1;
        myPoint4.pose.orientation.w = 0;
        target_vector.insert(target_vector.begin(), myPoint4);
        
        geometry_msgs::PoseStamped point;//临时中间点

        if(!target_vector.empty()){
            point=target_vector.back();//第一个点
            target_vector.pop_back();//在数组中删除第一个点
        }
        else{
            ROS_INFO_STREAM("point is over ");
        }
        int cout=1;
 
    	while (ros::ok())         
	{ 
        chatter_pub.publish(point);
        if(checktarget(point))//判断是否到达点
        {   
            ROS_INFO("The num is x: %i",cout);
            cout++;
            if(!target_vector.empty()){
                point=target_vector.back();//第一个点
                target_vector.pop_back();//在数组中删除第一个点
            }
             else{
                ROS_INFO_STREAM("point is over ");
             }
            //  flagTarget=0;//重新设定为未到达该点
        }
        
        ros::spinOnce(); 
        loop_rate.sleep(); 
	 }
       ros::spin();

    return 0;
}
