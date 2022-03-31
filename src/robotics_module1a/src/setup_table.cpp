// can_transformation.cpp
// Fred Livingston (fjliving@ncsu.edu) 02-02-2022

#include <ros/ros.h>
#include <math.h>
#include <Eigen/Dense>
#include <tf/tf.h>
#include <tf2_eigen/tf2_eigen.h>
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

    // all cans' x, y, z and angles' rotation were calculated by hand 
    // my code is obviously not optimzed for not using object-oriented programming but it does the job...
    
    // can 1
    float x1 = 0.8;
    float y1 = 0.0;
    float z1 = 1.07;  
    
    // can 2
    float x2 = 0.82679;
    float y2 = 0.1;
    float z2 = 1.06; 
    
    // can 3
    float x3 = 0.9;
    float y3 = 0.17321;
    float z3 = 1.06;    
      
    // can 4
    float x4 = 1;
    float y4 = 0.2;
    float z4 = 1.06;  
    
    // can 5
    float x5 = 1.1;
    float y5 = 0.17321;
    float z5 = 1.06;      
    
    // can 6
    float x6 = 1.17321;
    float y6 = 0.1;
    float z6 = 1.06;    
    
    // can 7
    float x7 = 1.2;
    float y7 = 0.0;
    float z7 = 1.06;  
    
    // can 8
    float x8 = 1.17321;
    float y8 = -0.1;
    float z8 = 1.06;   
    
    // can 9 
    float x9 = 1.1;
    float y9 = -0.17321;
    float z9 = 1.06;  
    
    // can 10
    float x10 = 1;
    float y10 = -0.2;
    float z10 = 1.06;  
    
    // can 11
    float x11 = 0.9;
    float y11 = -0.17321;
    float z11 = 1.06; 
    
    // can 12
    float x12 = 0.82679;
    float y12 = -0.1;
    float z12 = 1.06;
    
    // Pause Physics Engine
    ros::ServiceClient pauseGazebo = n.serviceClient<std_srvs::Empty>("/gazebo/pause_physics");
    std_srvs::Empty pauseSrv;
    pauseGazebo.call(pauseSrv);

// angle of rotation about Y then X axis for  12 cans
    int angleY1_deg = -90;
    //int angleX1_deg = 0;
    int angleY2_deg = -90;
    int angleX2_deg = -30;
    int angleY3_deg = -90;
    int angleX3_deg = -60;
    //int angleY4_deg = 0;
    int angleX4_deg = -90;
    int angleY5_deg = -90;
    int angleX5_deg = -120;
    int angleY6_deg = -90;
    int angleX6_deg = -150;
    int angleY7_deg = 90;
    //int angleX7_deg = 0;
    int angleY8_deg = -90;
    int angleX8_deg = -210;
    int angleY9_deg = -90;
    int angleX9_deg = -240;
    //int angleY10_deg = 0;
    int angleX10_deg = 90;
    int angleY11_deg = -90;
    int angleX11_deg = -300;
    int angleY12_deg = -90;
    int angleX12_deg = -330;
    while (ros::ok())
    {
    // convert degree to rad for all cans' angles
        float thetaY1_rads = degToRad(angleY1_deg);
        //float thetaX1_rads = degToRad(angleX1_deg);
        float thetaY2_rads = degToRad(angleY2_deg);
        float thetaX2_rads = degToRad(angleX2_deg);
        float thetaY3_rads = degToRad(angleY3_deg);
        float thetaX3_rads = degToRad(angleX3_deg);
        //float thetaY4_rads = degToRad(angleY4_deg);
        float thetaX4_rads = degToRad(angleX4_deg);
        float thetaY5_rads = degToRad(angleY5_deg);
        float thetaX5_rads = degToRad(angleX5_deg);
        float thetaY6_rads = degToRad(angleY6_deg);
        float thetaX6_rads = degToRad(angleX6_deg);
        float thetaY7_rads = degToRad(angleY7_deg);
        //float thetaX7_rads = degToRad(angleX7_deg);
        float thetaY8_rads = degToRad(angleY8_deg);
        float thetaX8_rads = degToRad(angleX8_deg);
        float thetaY9_rads = degToRad(angleY9_deg);
        float thetaX9_rads = degToRad(angleX9_deg);
        //float thetaY10_rads = degToRad(angleY10_deg);
        float thetaX10_rads = degToRad(angleX10_deg);
        float thetaY11_rads = degToRad(angleY11_deg);
        float thetaX11_rads = degToRad(angleX11_deg);
        float thetaY12_rads = degToRad(angleY12_deg);
        float thetaX12_rads = degToRad(angleX12_deg);



        //  ---- can 1 ----
        Eigen::Affine3d Tcan1 = Eigen::Affine3d::Identity();
        Tcan1.translation() << x1, y1, z1;
        Tcan1.rotate(Eigen::AngleAxisd(thetaY1_rads, Eigen::Vector3d::UnitY()));
        geometry_msgs::Pose can1_pose = tf2::toMsg(Tcan1);
        // can 1 state
        gazebo_msgs::ModelState can1_state;
        can1_state.model_name = (std::string) "coke_can1";
        can1_state.pose = can1_pose;
        // gazebo service request 1
        gazebo_msgs::SetModelState srv1;
        srv1.request.model_state = can1_state;
        client.call(srv1);
        
        
        
        //  ---- can 2 ----
        Eigen::Affine3d Tcan2 = Eigen::Affine3d::Identity();
        Tcan2.translation() << x2, y2, z2;
        Tcan2.rotate(Eigen::AngleAxisd(thetaY2_rads, Eigen::Vector3d::UnitY()));
        Tcan2.rotate(Eigen::AngleAxisd(thetaX2_rads, Eigen::Vector3d::UnitX()));
        geometry_msgs::Pose can2_pose = tf2::toMsg(Tcan2);
        // can 2 state
        gazebo_msgs::ModelState can2_state;
        can2_state.model_name = (std::string) "coke_can2";
        can2_state.pose = can2_pose;
        // gazebo service request 2
        gazebo_msgs::SetModelState srv2;
        srv2.request.model_state = can2_state;
        client.call(srv2);
        
        
        
        //  ---- can 3 ----
        Eigen::Affine3d Tcan3 = Eigen::Affine3d::Identity();
        Tcan3.translation() << x3, y3, z3;
        Tcan3.rotate(Eigen::AngleAxisd(thetaY3_rads, Eigen::Vector3d::UnitY()));
        Tcan3.rotate(Eigen::AngleAxisd(thetaX3_rads, Eigen::Vector3d::UnitX()));
        geometry_msgs::Pose can3_pose = tf2::toMsg(Tcan3);
        // can 3 state
        gazebo_msgs::ModelState can3_state;
        can3_state.model_name = (std::string) "coke_can3";
        can3_state.pose = can3_pose;
        // gazebo service request 3
        gazebo_msgs::SetModelState srv3;
        srv3.request.model_state = can3_state;
        client.call(srv3);
        
        
        
        //  ---- can 4 ----
        Eigen::Affine3d Tcan4 = Eigen::Affine3d::Identity();
        Tcan4.translation() << x4, y4, z4;
        Tcan4.rotate(Eigen::AngleAxisd(thetaX4_rads, Eigen::Vector3d::UnitX()));
        geometry_msgs::Pose can4_pose = tf2::toMsg(Tcan4);
        // can 4 state
        gazebo_msgs::ModelState can4_state;
        can4_state.model_name = (std::string) "coke_can4";
        can4_state.pose = can4_pose;
        // gazebo service request 4
        gazebo_msgs::SetModelState srv4;
        srv4.request.model_state = can4_state;
        client.call(srv4);
        
        
        
        //  ---- can 5 ----
        Eigen::Affine3d Tcan5 = Eigen::Affine3d::Identity();
        Tcan5.translation() << x5, y5, z5;
        Tcan5.rotate(Eigen::AngleAxisd(thetaY5_rads, Eigen::Vector3d::UnitY()));
        Tcan5.rotate(Eigen::AngleAxisd(thetaX5_rads, Eigen::Vector3d::UnitX()));
        geometry_msgs::Pose can5_pose = tf2::toMsg(Tcan5);
        // can 5 state
        gazebo_msgs::ModelState can5_state;
        can5_state.model_name = (std::string) "coke_can5";
        can5_state.pose = can5_pose;
        // gazebo service request 5
        gazebo_msgs::SetModelState srv5;
        srv5.request.model_state = can5_state;
        client.call(srv5);
        
        
        
        //  ---- can 6 ----
        Eigen::Affine3d Tcan6 = Eigen::Affine3d::Identity();
        Tcan6.translation() << x6, y6, z6;
        Tcan6.rotate(Eigen::AngleAxisd(thetaY6_rads, Eigen::Vector3d::UnitY()));
        Tcan6.rotate(Eigen::AngleAxisd(thetaX6_rads, Eigen::Vector3d::UnitX()));
        geometry_msgs::Pose can6_pose = tf2::toMsg(Tcan6);
        // can 6 state
        gazebo_msgs::ModelState can6_state;
        can6_state.model_name = (std::string) "coke_can6";
        can6_state.pose = can6_pose;
        // gazebo service request 6
        gazebo_msgs::SetModelState srv6;
        srv6.request.model_state = can6_state;
        client.call(srv6);
        
        
        
        //  ---- can 7 ----
        Eigen::Affine3d Tcan7 = Eigen::Affine3d::Identity();
        Tcan7.translation() << x7, y7, z7;
        Tcan7.rotate(Eigen::AngleAxisd(thetaY7_rads, Eigen::Vector3d::UnitY()));
        geometry_msgs::Pose can7_pose = tf2::toMsg(Tcan7);
        // can 7 state
        gazebo_msgs::ModelState can7_state;
        can7_state.model_name = (std::string) "coke_can7";
        can7_state.pose = can7_pose;
        // gazebo service request 7
        gazebo_msgs::SetModelState srv7;
        srv7.request.model_state = can7_state;
        client.call(srv7);
        
        
        
        //  ---- can 8 ----
        Eigen::Affine3d Tcan8 = Eigen::Affine3d::Identity();
        Tcan8.translation() << x8, y8, z8;
        Tcan8.rotate(Eigen::AngleAxisd(thetaY8_rads, Eigen::Vector3d::UnitY()));
        Tcan8.rotate(Eigen::AngleAxisd(thetaX8_rads, Eigen::Vector3d::UnitX()));
        geometry_msgs::Pose can8_pose = tf2::toMsg(Tcan8);
        // can 8 state
        gazebo_msgs::ModelState can8_state;
        can8_state.model_name = (std::string) "coke_can8";
        can8_state.pose = can8_pose;
        // gazebo service request 8
        gazebo_msgs::SetModelState srv8;
        srv8.request.model_state = can8_state;
        client.call(srv8);
        
        
        
        //  ---- can 9 ----
        Eigen::Affine3d Tcan9 = Eigen::Affine3d::Identity();
        Tcan9.translation() << x9, y9, z9;
        Tcan9.rotate(Eigen::AngleAxisd(thetaY9_rads, Eigen::Vector3d::UnitY()));
        Tcan9.rotate(Eigen::AngleAxisd(thetaX9_rads, Eigen::Vector3d::UnitX()));
        geometry_msgs::Pose can9_pose = tf2::toMsg(Tcan9);
        // can 9 state
        gazebo_msgs::ModelState can9_state;
        can9_state.model_name = (std::string) "coke_can9";
        can9_state.pose = can9_pose;
        // gazebo service request 9
        gazebo_msgs::SetModelState srv9;
        srv9.request.model_state = can9_state;
        client.call(srv9);
        
        
        
        //  ---- can 10 ----
        Eigen::Affine3d Tcan10 = Eigen::Affine3d::Identity();
        Tcan10.translation() << x10, y10, z10;
        Tcan10.rotate(Eigen::AngleAxisd(thetaX10_rads, Eigen::Vector3d::UnitX()));
        geometry_msgs::Pose can10_pose = tf2::toMsg(Tcan10);
        // can 10 state
        gazebo_msgs::ModelState can10_state;
        can10_state.model_name = (std::string) "coke_can10";
        can10_state.pose = can10_pose;
        // gazebo service request 10
        gazebo_msgs::SetModelState srv10;
        srv10.request.model_state = can10_state;
        client.call(srv10);
        
        
        
        //  ---- can 11 ----
        Eigen::Affine3d Tcan11 = Eigen::Affine3d::Identity();
        Tcan11.translation() << x11, y11, z11;
        Tcan11.rotate(Eigen::AngleAxisd(thetaY11_rads, Eigen::Vector3d::UnitY()));
        Tcan11.rotate(Eigen::AngleAxisd(thetaX11_rads, Eigen::Vector3d::UnitX()));
        geometry_msgs::Pose can11_pose = tf2::toMsg(Tcan11);
        // can 11 state
        gazebo_msgs::ModelState can11_state;
        can11_state.model_name = (std::string) "coke_can11";
        can11_state.pose = can11_pose;
        // gazebo service request 11
        gazebo_msgs::SetModelState srv11;
        srv11.request.model_state = can11_state;
        client.call(srv11);
        
        
        
        //  ---- can 12 ----
        Eigen::Affine3d Tcan12 = Eigen::Affine3d::Identity();
        Tcan12.translation() << x12, y12, z12;
        Tcan12.rotate(Eigen::AngleAxisd(thetaY12_rads, Eigen::Vector3d::UnitY()));
        Tcan12.rotate(Eigen::AngleAxisd(thetaX12_rads, Eigen::Vector3d::UnitX()));
        geometry_msgs::Pose can12_pose = tf2::toMsg(Tcan12);
        // can 12 state
        gazebo_msgs::ModelState can12_state;
        can12_state.model_name = (std::string) "coke_can12";
        can12_state.pose = can12_pose;
        // gazebo service request 12
        gazebo_msgs::SetModelState srv12;
        srv12.request.model_state = can12_state;
        client.call(srv12);
     


        ros::Duration(0.1).sleep(); // Sleep for one second
    }

    return 0;
}
