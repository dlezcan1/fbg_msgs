#ifndef TEST_CLASS_FBG_TALKER_H
#define TEST_CLASS_FBG_TALKER_H

#include <ros/ros.h>

#include "fbg_msgs/FBG.h"
#include "fbg_msgs/FBGstamped.h"



class TestFBGTalker
{
	public:
		TestFBGTalker(ros::NodeHandle &nodehandle, int num_AA); // Constructor
		void publish_random_signals();
		
	private:
		ros::NodeHandle nh_; // nodehandle
				
		/* FBG channel publishers */
		ros::Publisher pub_ch1;
		ros::Publisher pub_ch2;
		ros::Publisher pub_ch3;
		
		/* Needle parameters */
		int num_AA;
		
		// Functions
		void initialize_publishers();
		
	
};
#endif