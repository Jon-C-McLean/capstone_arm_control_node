#ifndef ARM_CONTROLLER_H
#define ARM_CONTROLLER_H

#include "ros/ros.h"
#include "sensor_msgs/JointState.h"
#include "can_msgs/Frame.h"

#include <hwlib/motor.h>

namespace Arm {
    class Controller {
        public:
            Controller(ros::NodeHandle *node);

            void handle(sensor_msgs::JointStateConstPtr msg);
        private:
            ros::NodeHandle *node;

            // Subscribers
            ros::Subscriber stateSub;

            // Publishers
            ros::Publisher framePub;

            enum ArmJoint {
                SHOULDER_YAW = 0,
                SHOULDER_PITCH = 1,
                WRIST_PITCH = 2,
                WRIST_ROLL = 3,
                ELBOW = 4,
                UNKNOWN = 5,
            };

            int getIdForJoint(ArmJoint joint);
            ArmJoint getJointForId(ArmJoint joint);
    };
};

#endif