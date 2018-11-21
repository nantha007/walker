/**
 * MIT License
 * Copyright (c) 2018 Nantha Kumar Sunder
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
/**
 *  @file main.cpp
 *  @brief A program to create a node walker to control turtlebot
 *  @author Nantha Kumar Sunder
 *  @copyright 2018
 */
#include "walker.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "walker");
  ros::NodeHandle n;
  ros::Duration(5).sleep();
  ros::Subscriber getDistance;
  ros::Publisher setVel;
  geometry_msgs::Twist msg;
    msg.linear.x = 0.0;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;
    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = 0.0;
  walker obj;
  getDistance = n.subscribe("/scan", 1000, &walker::walkerCallback, &obj);
  setVel = n.advertise < geometry_msgs::Twist
      > ("/mobile_base/commands/velocity", 100);
ros::Rate loop_rate(2);
  while (ros::ok()) {
    if (obj.getDist() < 1){
	msg.linear.x = 0;
        msg.angular.x = 1;
    } else {
        msg.angular.x = 0;
        msg.linear.x = 1;
    }
    setVel.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }

}
