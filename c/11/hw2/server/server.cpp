#include "server.h"

const std::vector<std::vector<std::string>> Server::accounts {{"test", "1234"}, {"asd", "dsa"}, {"foo", "bar"}};

Server::Server(std::vector<std::string> paths, std::vector<Process*> processes){
    this->paths = paths;
    this->processes = processes;
}

Server::Server(const Server& server){
    this->paths = server.paths;
    this->processes = server.processes;
}

Server::~Server(){
    for(int i = 0; i < processes.size(); i++){
        delete processes[i];
    }
}

std::vector<std::string> Server::getPaths(){
    return paths;
}

std::vector<Process*> Server::getProcesses(){
    return processes;
}

void Server::setPaths(std::vector<std::string> paths){
    this->paths = paths;
}

void Server::setProcesses(std::vector<Process*> processes){
    this->processes = processes;
}

Response* Server::routeRequest(Request* req){
    for(int i = 0; i < paths.size(); i++){
        if(paths[i] == req->getRes()){
            return processes[i]->handleRequest(req);
        }
    }
    return new Response(404, "Not Found");
}