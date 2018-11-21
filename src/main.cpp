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
#include "include/walker.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h"
/**
 *  @brief main function controls the motion of the turtlebot
 *  @param argc is the number of argument
 *  @param argv is the arguments
 *  @return None
 */
int main(int argc, char **argv) {
  ros::init(argc, argv, "walker");
  ros::NodeHandle n;
  ros::Subscriber getDistance;
  ros::Publisher setVel;
  geometry_msgs::Twist msg;
  // initial value of the msg
  msg.linear.x = 0.0;
  msg.linear.y = 0.0;
  msg.linear.z = 0.0;
  msg.angular.x = 0.0;
  msg.angular.y = 0.0;
  msg.angular.z = 0.0;
  // creating a walker object
  walker obj;
  // subscribing to the /scan topic
  getDistance = n.subscribe("/scan", 1000, &walker::walkerCallback, &obj);
  // advertising to control the velocity of the turtlebot
  setVel = n.advertise < geometry_msgs::Twist
      > ("/mobile_base/commands/velocity", 100);
  ros::Rate loop_rate(10);
  while (ros::ok()) {
    // if the robot close to collision, then change the course
    if (obj.checkDist == 1) {
      // stop the robot and changing the course
      msg.linear.x = 0;
      msg.angular.z = -1;
    } else {
      // moving at a constant speed
      msg.angular.z = 0;
      msg.linear.x = 0.1;
    }
    // publishing the robot velocity
    setVel.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
}

