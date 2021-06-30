#include "server.h"
#include "processauth.h"
#include "processusers.h"
#include <iostream>

int main(){
    std::vector<std::string> paths;
    paths.push_back("/login.html");
    paths.push_back("/home.html");
    paths.push_back("/api/login");
    paths.push_back("/api/get_users");
    std::vector<Process*> processes;
    processes.push_back(new Process());
    processes.push_back(new Process());
    processes.push_back(new ProcessAuth());
    processes.push_back(new ProcessUsers());
    Server server = Server(paths, processes);
    std::vector<std::string> args;
    args.push_back("test");
    args.push_back("1234");
    Request* req1 = new Request("192.168.0.106", "/login.html");
    Request* req2 = new Request("192.168.0.106", "/api/login", args);
    Request* req3 = new Request("192.168.0.106", "/api/get_users");
    Response* res1 = server.routeRequest(req1);
    Response* res2 = server.routeRequest(req2);
    Response* res3 = server.routeRequest(req3);
    std::cout << res1->getStatus() << " " << res1->getMessage() << std::endl;
    std::cout << res2->getStatus() << " " << res2->getMessage() << std::endl;
    std::cout << res3->getStatus() << " " << res3->getMessage() << std::endl;
    delete req1;
    delete req2;
    delete req3;
    delete res1;
    delete res2;
    delete res3;
    return 0;
}