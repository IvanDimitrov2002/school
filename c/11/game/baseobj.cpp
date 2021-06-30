#include "baseobj.h"

BaseObj::BaseObj(){};
void BaseObj::render(){};
void BaseObj::update(){};
int BaseObj::getPos(){
    return pos;
};
int BaseObj::getModel(){
    return model;
};