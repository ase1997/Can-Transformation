// module1_positions.cpp
// Fred Livingston (fjliving@ncsu.edu) 02-02-2022

#include <ros/ros.h>
#include "gazebo_msgs/SetModelState.h"

using namespace std;

int main(int argc,char **argv)
{
    // ROS Client
    ros::init(argc,argv,"lecture8"); 
    
    // ROS Service-Cient /gazebo/set_model_state
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<gazebo_msgs::SetModelState>("/gazebo/set_model_state");

    // Set Object Position
    geometry_msgs::Point obj_position;
    obj_position.x = 0.0;
    obj_position.y = 1.0;
    obj_position.z = 0.22;
    
    // Set Object Orientation
    geometry_msgs::Quaternion obj_orientation;
    obj_orientation.x = 0.0;
    obj_orientation.y = 0.0;
    obj_orientation.z = 0.0;
    obj_orientation.w = 1.0;

    // Object Pose (Position + Orientation)
    geometry_msgs::Pose obj_pose;
    obj_pose.position = obj_position;
    obj_pose.orientation = obj_orientation;

    // ModelState
    gazebo_msgs::ModelState obj_modelstate;
    obj_modelstate.model_name = (std::string) "coke_can3";
    obj_modelstate.pose = obj_pose;

    // gazebo service request
    gazebo_msgs::SetModelState srv;
    srv.request.model_state = obj_modelstate;
    
    if(client.call(srv))
    {
        ROS_INFO("service request success!!");
    }
    else
    {
        ROS_ERROR("Failed! Error msg:%s",srv.response.status_message.c_str());
    }
    return 0;
}
