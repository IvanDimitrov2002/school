#ifndef BOOK_H
#define BOOK_H

#include "media.h"

class Book : public Media{
    public:
        using Media::Media;
};

#endif