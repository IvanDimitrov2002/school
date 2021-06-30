#include "processauth.h"
#include "server.h"

Response* ProcessAuth::handleRequest(Request* req){
    for(int i = 0; i < Server::accounts.size(); i++){
        if(req->getArgs()[0] == Server::accounts[i][0] && req->getArgs()[1] == Server::accounts[i][1]){
            return new Response(200, "OK");
        }
    }
    return new Response(403, "Unauthorized");
}