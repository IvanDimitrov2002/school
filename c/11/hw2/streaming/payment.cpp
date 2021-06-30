#include "payment.h"

Payment::Payment(std::string startDate, std::string endDate, std::vector<Media*> media, double bill, bool isPaid){
    period.first = startDate;
    period.second = endDate;
    this->media = media;
    this->bill = bill;
    this->isPaid = isPaid;
}

Payment::Payment(const Payment& payment){
    this->period = payment.period;
    this->media = payment.media;
    this->bill = payment.bill;
    this->isPaid = payment.isPaid;
}

std::pair<std::string, std::string> Payment::getPeriod(){
    return period;
}

std::vector<Media*> Payment::getMedia(){
    return media;
}

double Payment::getBill(){
    return bill;
}

bool Payment::getIsPaid(){
    return isPaid;
}

void Payment::setPeriod(std::pair<std::string, std::string> period){
    this->period = period;
}

void Payment::setMedia(std::vector<Media*> media){
    this->media = media;
}

void Payment::setBill(double bill){
    this->bill = bill;
}

void Payment::setPaid(bool isPaid){
    this->isPaid = isPaid;
}