#include "ArmController.h"

namespace Arm {
    Controller::Controller(ros::NodeHandle *node) {
        this->node = node;

        stateSub = node->subscribe("/arm/joint_states", 1000, &Controller::handle, this);
        framePub = node->advertise<can_msgs::Frame>("/sent_messages", 1000);
    }

    void Controller::handle(sensor_msgs::JointStateConstPtr msg) {
        // TODO: Write handle
    }

    int Controller::getIdForJoint(ArmJoint joint) {
        return static_cast<int>(joint);
    }

    Controller::ArmJoint Controller::getJointForId(ArmJoint joint) {
        switch(joint) {
            case SHOULDER_YAW:
                return SHOULDER_YAW;
            case SHOULDER_PITCH:
                return SHOULDER_PITCH;
            case WRIST_PITCH:
                return WRIST_PITCH;
            case WRIST_ROLL:
                return WRIST_ROLL;
            case ELBOW:
                return ELBOW;
            default:
                return UNKNOWN;
        }
    }
};