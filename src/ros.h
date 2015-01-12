/**
 * Create a typedef for convenient frequent reference to the ROS NodeHandle object.
 */

#ifndef _ROS_H_
#define _ROS_H_

#include "ros/node_handle.h"
#include "Atmega1284PHardware.h"

namespace ros
{
	typedef ros::NodeHandle_<Atmega1284PHardware> NodeHandle;
}

#endif
