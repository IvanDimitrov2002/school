#ifndef INDUSTRIAL_CLIENT_DOUBLE_H
#define INDUSTRIAL_CLIENT_DOUBLE_H

#include "industrial_client.h"

class IndustrialClientDouble : public IndustrialClient {
    float usedPowerDay;
    float usedPowerNight;
    float rateDay;
    float rateNight;
    public:
        float calcBill();
};

#endif