#include "ros/ros.h"
#include "fbg_msgs/FBG.h"
#include "fbg_msgs/TemperatureCompensate.h"

bool temperature_compensate(fbg_msgs::TemperatureCompensate::Request  &reg,
			    fbg_msgs::TemperatureCompensate::Response &res)
{
    int N_channels = reg.fbgs.size();

    for (int i = 0; i < N_channels; i++)
    {
	
    }
} //temperature_compensate
