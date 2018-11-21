#include <iostream>
#include "walker.h"
#include "std_msgs/String.h"
#include "sensor_msgs/LaserScan.h"
#include "geometry_msgs/Twist.h"

void walker::walkerCallback(const sensor_msgs::LaserScan::ConstPtr& val) {
  float min = 10;
  for (const auto& temp : val->ranges) {
    if (min > temp) {
      min = temp;
    }
  }
  dist = min;
}
float walker::getDist(){
	return dist;
}
