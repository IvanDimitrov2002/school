#ifndef COMMON_CLIENT_SINGLE_H
#define COMMON_CLIENT_SINGLE_H

#include "common_client.h"

class CommonClientSingle : public CommonClient {
    float usedPower;
    float rate;
    public:
        float calcBill();
};

#endif