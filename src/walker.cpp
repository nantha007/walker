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
 *  @file walker.cpp
 *  @brief A program for walker
 *  @author Nantha Kumar Sunder
 *  @copyright 2018
 */
#include "include/walker.h"
#include "sensor_msgs/LaserScan.h"
#include "geometry_msgs/Twist.h"
/**
 * @brief Subscriber Node for topic scan call back function
 * @param val dist vector from sensor_msgs
 * @return none
 */
void walker::walkerCallback(const sensor_msgs::LaserScan::ConstPtr& val) {
  float minValue;
  minValue = val->ranges[0];
  // Finding the min value of the val vector
  for (const auto& temp : val->ranges) {
    if (minValue > temp) {
      minValue = temp;
    }
  }
  dist = minValue;
  // if the distance is less than 1 then, robot has to be change course
  if (dist < 2) {
    checkDist = 1;
  } else {
    checkDist = 0;
  }
}
/**
 * @brief function to get the value of the distance
 * @param none 
 * @return dist
 */
float walker::getDist() {
  return dist;
}

