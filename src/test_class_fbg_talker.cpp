#include <stdio.h>
#include "test_class_fbg_talker.hpp"

TestFBGTalker::TestFBGTalker(ros::NodeHandle &nodehandle, int num_AA):nh_(nodehandle)
{
	this->num_AA  = num_AA;
	
	this->initialize_publishers();
	ROS_INFO("TestFBGTalker is initalized");
	
	
	
} // constructor

void TestFBGTalker::initialize_publishers()
{
	this->pub_ch1 = nh_.advertise<fbg_msgs::FBGstamped>("CH1", 10);
	this->pub_ch2 = nh_.advertise<fbg_msgs::FBGstamped>("CH2", 10);
	this->pub_ch3 = nh_.advertise<fbg_msgs::FBGstamped>("CH3", 10);

} // initalize_publishers

void TestFBGTalker::publish_random_signals()
{
	// Initialize the messages to be published
	fbg_msgs::FBGstamped msg_ch1;
	fbg_msgs::FBGstamped msg_ch2;
	fbg_msgs::FBGstamped msg_ch3;
	
	// Generate the random signals
	for (int i = 0; i < this->num_AA; i++)
	{
		msg_ch1.fbg.signals.push_back(std::rand() % 1500);
		msg_ch2.fbg.signals.push_back(std::rand() % 1500);
		msg_ch3.fbg.signals.push_back(std::rand() % 1500);
	
	} // for
	
	// Add the timestamps
	msg_ch1.header.stamp = ros::Time::now();
	msg_ch2.header = msg_ch1.header;
	msg_ch3.header = msg_ch1.header;
	
	// publish the topic
	pub_ch1.publish(msg_ch1);
	pub_ch2.publish(msg_ch2);
	pub_ch3.publish(msg_ch3);

} // publish_random_signals

int main(int argc, char** argv)
{
	ros::init(argc, argv, "TestFBGTalker");
	ros::NodeHandle nh;
	ros::Rate loop_rate(10);
		
	int num_AA = 5;
	
	TestFBGTalker fbgtalker(nh, num_AA);
	
	// publish topics
	while (ros::ok())
	{
		fbgtalker.publish_random_signals();
		ros::spinOnce();
		loop_rate.sleep();
		
	} // while
	
}// main