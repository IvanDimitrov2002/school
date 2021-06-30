#include "response.h"

Response::Response(int status, std::string message){
    this->status = status;
    this->message = message;
}

Response::Response(const Response& response){
    this->status = response.status;
    this->message = response.message;
}

int Response::getStatus(){
    return status;
}

std::string Response::getMessage(){
    return message;
}

void Response::setStatus(int status){
    this->status = status;
}

void Response::setMessage(std::string message){
    this->message = message;
}