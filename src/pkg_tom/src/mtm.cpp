#include "mtm.h"

mtm::mtm(ros::NodeHandle* nh, std::string type) : arm(nh,type)
{
    if(type.compare("MTML")==0)
        arm::homing_position={0.179812089165, 0.0165389167399, 0.411596749171};
    else if(type.compare("MTMR")==0)
        arm::homing_position={-0.179812089165, 0.0165389167399, 0.411596749171};
}




