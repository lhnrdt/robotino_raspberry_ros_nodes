/*
 * main.cpp
 *
 *  Created on: 09.12.2011
 *      Author: indorewala@servicerobotics.eu
 */

#include "RobotinoCustomNode.h"

#include <ros/ros.h>

int main(int argc, char** argv)
{
	ros::init(argc, argv, "robotino_custom_node");
	RobotinoCustomNode rn;
	rn.spin();
	return 0;
}
