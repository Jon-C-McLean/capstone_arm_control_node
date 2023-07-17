#include "ros/ros.h"
#include "arm/ArmController.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "arm_control");
    ros::NodeHandle nh;

    Arm::Controller controller(&nh);

    ros::spin();

    return 0;
}