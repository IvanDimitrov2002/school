#include "processusers.h"
#include "server.h"

Response* ProcessUsers::handleRequest(Request* req){
    std::string usernames = "";
    for(int i = 0; i < Server::accounts.size(); i++){
        usernames += "\"" + Server::accounts[i][0] + "\", ";
    }
    usernames = usernames.substr(0, usernames.size()-2);
    return new Response(200, "[" + usernames + "]");
}