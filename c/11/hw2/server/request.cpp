#include "request.h"

Request::Request(std::string ip, std::string res, std::vector<std::string> args){
    this->ip = ip;
    this->res = res;
    this->args = args;
}

Request::Request(const Request& request){
    this->ip = request.ip;
    this->res = request.res;
    this->args = request.args;
}

std::string Request::getIp(){
    return ip;
}

std::string Request::getRes(){
    return res;
}

std::vector<std::string> Request::getArgs(){
    return args;
}

void Request::setIp(std::string ip){
    this->ip = ip;
}

void Request::setRes(std::string res){
    this->res = res;
}

void Request::setArgs(std::vector<std::string> args){
    this->args = args;
}