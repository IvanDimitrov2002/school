#ifndef PROCESSAUTH_H
#define PROCESSAUTH_H

#include "process.h"

class ProcessAuth : public Process{
    public:
        Response* handleRequest(Request* req);
};

#endif