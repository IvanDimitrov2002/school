#ifndef PROCESS_H
#define PROCESS_H

#include "response.h"       

class Process{
    public:
        virtual Response* handleRequest(Request* req);
};

#endif