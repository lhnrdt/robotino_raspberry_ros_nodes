/*
 * RobotinoCustomNode.cpp
 *
 *  Created on: 09.12.2011
 *      Author: indorewala@servicerobotics.eu
 */

#include "RobotinoCustomNode.h"

RobotinoCustomNode::RobotinoCustomNode()
	: nh_("~")
{
	nh_.param<std::string>("hostname", hostname_, "172.26.1.1" );
	nh_.param<double>("max_linear_vel", max_linear_vel_, 0.2 );
	nh_.param<double>("min_linear_vel", min_linear_vel_, 0.05 );
	nh_.param<double>("max_angular_vel", max_angular_vel_, 1.0 );
	nh_.param<double>("min_angular_vel", min_angular_vel_, 0.1 );

	com_.setName( "RobotinoCustomNode" );

	initModules();
}

RobotinoCustomNode::~RobotinoCustomNode()
{
}

void RobotinoCustomNode::initModules()
{
	com_.setAddress( hostname_.c_str() );

	// Set the ComIds
	omni_drive_.setComId( com_.id() );
	omni_drive_.setMaxMin(max_linear_vel_, min_linear_vel_, max_angular_vel_, min_angular_vel_ );
	com_.connectToServer( false );
}



bool RobotinoCustomNode::spin()
{
	ros::Rate loop_rate( 30 );

	while(nh_.ok())
	{
		curr_time_ = ros::Time::now();
		com_.processEvents();
		ros::spinOnce();
		loop_rate.sleep();
	}
	return true;
}

