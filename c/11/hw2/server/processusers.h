#ifndef PROCESSUSERS_H
#define PROCESSUSERS_H

#include "process.h"

class ProcessUsers : public Process{
    public:
        Response* handleRequest(Request* req);
};

#endif