// rotate_can.cpp
// Fred Livingston (fjliving@ncsu.edu) 02-02-2022

#include <ros/ros.h>
#include <math.h>
#include <tf/tf.h>
#include <std_srvs/Empty.h>
#include "gazebo_msgs/SetModelState.h"

#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)

using namespace std;

int main(int argc, char **argv)
{
    // ROS Client
    ros::init(argc, argv, "lecture8");

    // ROS Service-Cient /gazebo/set_model_state
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<gazebo_msgs::SetModelState>("/gazebo/set_model_state");

    float x = 0.0;
    float y = 0.0;
    float z = 0.5;    

    // Set Object Position
    geometry_msgs::Point obj_position;
    obj_position.x = x;
    obj_position.y = y;
    obj_position.z = z;

    // Set Object Orientation
    geometry_msgs::Quaternion obj_orientation;
    obj_orientation.x = 0.0;
    obj_orientation.y = 0.0;
    obj_orientation.z = 0.0;
    obj_orientation.w = 1.0;

    // Pause Physics Engine
    ros::ServiceClient pauseGazebo = n.serviceClient<std_srvs::Empty>("/gazebo/pause_physics");
    std_srvs::Empty pauseSrv;
    pauseGazebo.call(pauseSrv);

    int angle_deg = 0;
    while (ros::ok())
    {
        // ROS_INFO("Theta (deg) %d", angle_deg);

        float theta_rads = degToRad(angle_deg);
       
        //  ---- Method 1 ----
        obj_orientation = tf::createQuaternionMsgFromRollPitchYaw(0, 0, theta_rads);

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

        client.call(srv);

        ros::Duration(0.1).sleep(); // Sleep for one second

        angle_deg = (angle_deg > 350)? 0 : (angle_deg + 10); 
    }

    return 0;
}
