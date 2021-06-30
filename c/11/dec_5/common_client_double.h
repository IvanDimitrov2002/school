#ifndef COMMON_CLIENT_DOUBLE_H
#define COMMON_CLIENT_DOUBLE_H

#include "common_client.h"

class CommonClientDouble : public CommonClient {
    float usedPowerDay;
    float usedPowerNight;
    float rateDay;
    float rateNight;
    public:
        float calcBill();
};

#endif