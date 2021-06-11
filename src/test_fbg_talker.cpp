#include <stdio.h>
#include <stdlib.h>
#include <ros/ros.h>
#include "fbg_msgs/FBG.h"
#include "fbg_msgs/FBGstamped.h"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "test_fbg_talker");

	ros::NodeHandle nh("/FBG");

	ros::Publisher fbg_ch1 = nh.advertise<fbg_msgs::FBG>("CH1", 1000);
	ros::Publisher fbg_ch2 = nh.advertise<fbg_msgs::FBGstamped>("CH2", 1000);
	ros::Rate loop_rate(10);
	
	int N_AA = 4; // number of simulated active areas

	while(ros::ok())
	{
		fbg_msgs::FBG msg_ch1;
		fbg_msgs::FBGstamped msg_ch2;
		// msg.signals = random_signal(N_AA);
		//random_signal(N_AA, msg.signals);
		for (int i = 0; i < N_AA; i++){
			msg_ch1.signals.push_back(std::rand() % 1500);
			msg_ch2.fbg.signals.push_back(std::rand() % 1500);
		}
		msg_ch2.header.stamp = ros::Time::now();
		msg_ch2.header.frame_id = "CH2";

		fbg_ch1.publish(msg_ch1);
		fbg_ch2.publish(msg_ch2);
		
		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;	
}	
