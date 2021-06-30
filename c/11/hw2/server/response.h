#ifndef RESPONSE_H
#define RESPONSE_H

#include "request.h"

class Response{
    private:
        int status;
        std::string message;
    public:
        Response(){};

        Response(int status, std::string message);

        Response(const Response& response);

        int getStatus();
        std::string getMessage();

        void setStatus(int status);
        void setMessage(std::string message);
};

#endif