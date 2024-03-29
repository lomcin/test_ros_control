/*
MIT License

Copyright (c) 2024 Lucas Maggi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

// ROS Includes
#include <ros/ros.h>
#include <controller_manager/controller_manager.h>
#include <hardware_interface/hardware_interface.h>

// Controller Manager Node package includes
#include <RobotHWInterface.hpp>
#include <DummyRobotHWInterface.hpp>

hardware_interface::RobotHW *robot_hw;
controller_manager::ControllerLoaderInterface *loader;
controller_manager::ControllerManager *manager;

const char *node_name = "controller_manager_node";

int main(int argc, char **argv)
{
    ros::init(argc, argv, node_name);
    ros::NodeHandle nh;
    ros::NodeHandle robotHwNh("~");

    robot_hw = new DummyRobotHWInterface();
    manager = new controller_manager::ControllerManager(robot_hw, robotHwNh);
    ros::Rate rate(100);
    ros::Time ts = ros::Time::now();

    while (ros::ok())
    {
        ros::spinOnce();
        ros::Duration d = ros::Time::now() - ts;
        ts = ros::Time::now();

        robot_hw->read(ts, d);
        manager->update(ts, d);
        robot_hw->write(ts, d);
        rate.sleep();
        ROS_INFO("[%s] ros loop ping.", node_name);
    }
    // delete loader;
    delete robot_hw;
    delete manager;

    return 0;
}