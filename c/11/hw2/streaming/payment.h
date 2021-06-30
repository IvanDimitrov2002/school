#ifndef PAYMENT_H
#define PAYMENT_H

#include <utility>
#include <vector>
#include <string>
#include "media.h"

class Payment{
    private:
        std::pair<std::string, std::string> period;
        std::vector<Media*> media;
        double bill;
        bool isPaid = false;
    public:
        Payment(){};

        Payment(std::string startDate, std::string endDate, std::vector<Media*> media, double bill, bool isPaid);

        Payment(const Payment& payment);

        std::pair<std::string, std::string> getPeriod();
        std::vector<Media*> getMedia();
        double getBill();
        bool getIsPaid();

        void setPeriod(std::pair<std::string, std::string> period);
        void setMedia(std::vector<Media*> media);
        void setBill(double bill);
        void setPaid(bool isPaid);
};

#endif