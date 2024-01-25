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

#ifndef __CONTROLLER_MANAGER_ROBOT_HARDWARE_INTERFACE__H_
#define __CONTROLLER_MANAGER_ROBOT_HARDWARE_INTERFACE__H_

// ROS Includes
#include <ros/ros.h>
#include <controller_manager/controller_manager.h>
#include <hardware_interface/hardware_interface.h>

class RobotHWInterface : public hardware_interface::RobotHW
{
public:
    RobotHWInterface() = default;
    ~RobotHWInterface() = default;
    bool init(ros::NodeHandle & /*root_nh*/, ros::NodeHandle & /*robot_hw_nh*/)
    {
        ROS_INFO("Initialized RobotHWInterface.");
        return true;
    }
    void read(const ros::Time & /*time*/, const ros::Duration & /*period*/)
    {
        ROS_INFO("Read from RobotHWInterface.");
    }
    void write(const ros::Time & /*time*/, const ros::Duration & /*period*/)
    {
        ROS_INFO("Write from RobotHWInterface.");
    }
};

#endif // __CONTROLLER_MANAGER_ROBOT_HARDWARE_INTERFACE__H_
