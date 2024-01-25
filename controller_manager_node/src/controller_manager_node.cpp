

// ROS Includes
#include <ros/ros.h>
#include <controller_manager/controller_manager.h>
#include <hardware_interface/hardware_interface.h>

hardware_interface::RobotHW *robot_hw;
controller_manager::ControllerLoaderInterface *loader;
controller_manager::ControllerManager *manager;

const char *node_name = "controller_manager_node";

int main(int argc, char **argv)
{
    ros::init(argc, argv, node_name);
    ros::NodeHandle nh;
    ros::NodeHandle robotHwNh("~");

    robot_hw = new hardware_interface::RobotHW();
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