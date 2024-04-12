#include <ros/ros.h>
#include <nav_msgs/Path.h>
#include <geometry_msgs/PoseStamped.h>

int main(int argc, char** argv){
    ros::init(argc, argv, "visualization");
    ros::NodeHandle nh;

    ros::Publisher path_pub = nh.advertise<nav_msgs::Path>("/global_path", 10);
    ros::Rate rate(1);

    nav_msgs::Path path;
    path.header.frame_id = "map";

    for(int i = 0; i < 10; ++i){
        geometry_msgs::PoseStamped pose;
        pose.header.frame_id = "map";
        pose.pose.position.x = i;
        pose.pose.position.y = i;
        pose.pose.position.z = 0;
        path.poses.push_back(pose);
    }

    while (ros::ok()) 
    {
        path_pub.publish(path);
        rate.sleep();
    }
    
    return 0;

}

