#ifndef SERVER_H
#define SERVER_H

#include "response.h"
#include "process.h"

class Server{
    private:
        std::vector<std::string> paths;
        std::vector<Process*> processes;

    public:
        static const std::vector<std::vector<std::string>> accounts;

        Server(){};

        Server(std::vector<std::string> paths, std::vector<Process*> processes);

        Server(const Server& server);

        ~Server();

        std::vector<std::string> getPaths();
        std::vector<Process*> getProcesses();

        void setPaths(std::vector<std::string> paths);
        void setProcesses(std::vector<Process*> processes);

        Response* routeRequest(Request* req);
};

#endif