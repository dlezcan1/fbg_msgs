#!/usr/bin/python

import rospy
import numpy as np
from fbg_msgs.msg import FBG
from fbg_msgs.srv import TemperatureCompensateResponse, TemperatureCompensate

def temperature_compensate(req):
	signals = np.array([fbg_signal for fbg_signals in req.fbgs])
	signal_aa = np.mean(signals, axis=0)
	res = TemperatureCompensateResponse()
	res.fbgs_Tcorr = []
	for fbg_signal in req.fbgs:
		fbg_signal_Tcorr = (np.array(fbg_signal) - signal_aa).tolist()
		res.fbgs_Tcorr.append(fbg_signal_Tcorr)
	
	return res

# temperature_compensate

if __name__ == "__main__":
	rospy.init_node('temp_corr_server')
	rospy.loginfo('Connected temp_corr_server')
	s = rospy.Service('temp_corr',TemperatureCompensate, temperature_compensate)
	rospy.spin()

