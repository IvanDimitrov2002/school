#ifndef MEDIA_H
#define MEDIA_H

#include <string>

class Media{
    protected:
        std::string title;
        std::string author;
        double price;

    public:
        Media(){};

        Media(std::string title, std::string author, double price);

        Media(const Media& media);

        std::string getTitle();
        std::string getAuthor();
        double getPrice();

        void setTitle(std::string title);
        void setAuthor(std::string author);
        void setPrice(double price);

        virtual double calcPrice();
};

#endif