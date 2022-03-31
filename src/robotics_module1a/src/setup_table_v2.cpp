#include <ros/ros.h>
#include <math.h>
#include <Eigen/Dense>
#include <tf/tf.h>
#include <tf2_eigen/tf2_eigen.h>
#include <std_srvs/Empty.h>
#include "gazebo_msgs/SetModelState.h"

using namespace std;

int main(int argc, char **argv)
{
	ros::init(argc, argv, "Assignment2");
	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient<gazebo_msgs::SetModelState>("/gazebo/set_model_state");
	
	float x = 1.0;
	float y = 0.0;
	float z = 1.05;
	float rad = 0.5236;
	float theta = 0.0;
	std::string objname[12] = {"coke_can1", "coke_can2", "coke_can3", "coke_can4", "coke_can5", "coke_can6", "coke_can7", "coke_can8", "coke_can9", "coke_can10", "coke_can11", "coke_can12"};
    
	for (int i=0; i<12; i++)
	{
		theta = rad*i;
		x = 1.0+0.2*cos(theta);
		y = -0.2*sin(theta);

		Eigen::Affine3d Tobj = Eigen::Affine3d::Identity();
		Tobj.translation() << x, y, z;
		Tobj.rotate(Eigen::AngleAxisd(1.571, Eigen::Vector3d::UnitY()));
		Tobj.rotate(Eigen::AngleAxisd(theta, Eigen::Vector3d::UnitX()));
		geometry_msgs::Pose obj_pose = tf2::toMsg(Tobj);
		
		gazebo_msgs::ModelState obj_modelstate;
		obj_modelstate.model_name = (std::string) objname[i];
		obj_modelstate.pose = obj_pose;
		
		gazebo_msgs::SetModelState srv;
		srv.request.model_state = obj_modelstate;
		client.call(srv);
		
		ros::Duration(0.1).sleep();
	}
	return 0;
}

