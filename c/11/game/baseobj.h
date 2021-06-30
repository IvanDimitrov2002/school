#ifndef BASEOBJ_H
#define BASEOBJ_H

class BaseObj{
    int pos;
    int model;
    public:
        BaseObj();
        int getPos();
        int getModel();
        void render();
        void update();
};

#endif