# Walker

## Overview

The obstacle avoidance is implemented using walker algorithm. Robot moves forward, till he meets obstacle. If there is an obstacle in its way, it changes it's direction. 

## Dependencies

The following packages are needed to run this program:
* Ubuntu Xenial 16.04
* ROS Kinetic


## Instructions for creating catkin workspace

To create catkin workspace, open terminal and type the following commands
```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
catkin_make
```

## Instructions to setup catkin workspace

Once catkin workspace is created, open terminal and type the following commands to clone the repository.

``` 
cd ~/catkin_ws/src/
git clone --recursive https://github.com/nantha007/walker.git
```

Once repository is cloned, type the following commands to setup the repository.
```
cd ~/catkin_ws/
source devel/setup.bash
catkin_make
```


## Instructions to run the program using launch

Open terminal and type the following commands to run the program.

```
cd ~/catkin_ws/
source devel/setup.bash
catkin_make
roslaunch walker walker.launch
```

Open terminal and type the following commands to run the program to record.

```
cd ~/catkin_ws/
source devel/setup.bash
catkin_make
roslaunch walker walker.launch rec:=1
```

