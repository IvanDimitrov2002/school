#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <vector>

class Request{
    private:
        std::string ip;
        std::string res;
        std::vector<std::string> args;
    public:
        Request(){};

        Request(std::string ip, std::string res, std::vector<std::string> args = std::vector<std::string>());

        Request(const Request& request);

        std::string getIp();
        std::string getRes();
        std::vector<std::string> getArgs();

        void setIp(std::string ip);
        void setRes(std::string res);
        void setArgs(std::vector<std::string> args);
};

#endif