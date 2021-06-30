#include "process.h"

Response* Process::handleRequest(Request* req){
    std::string message = req->getRes().substr(1, req->getRes().find(".html") - 1);
    return new Response(200, "<html>" + message + "</html>");
}