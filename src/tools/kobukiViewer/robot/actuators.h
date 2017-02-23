#ifndef ACTUATORS_H
#define ACTUATORS_H

#include <QMutex>

#include <Ice/Ice.h>
#include <IceUtil/IceUtil.h>

#include <jderobot/types/cmdvel.h>
#include <jderobot/comm/motorsClient.hpp>

class Actuators
{
public:
    Actuators(Ice::CommunicatorPtr ic);
    
    float getMotorV();
    float getMotorW();
    float getMotorL();

    //SETS
    void setMotorV(float motorV);
    void setMotorW(float motorW);
    void setMotorL(float motorL);
    void setMotorSTOP();

private:

    QMutex mutex;

    Ice::CommunicatorPtr ic;

    // ICE INTERFACES
    JdeRobotComm::MotorsClient* motorsClient;

};
#endif // ACTUATORS_H
