#ifndef VEHICLE_HH
#define VEHICLE_HH

#include "./entity.hh"

class Vehicle : public Entity {
public:
  float speed;
  int seatCount;
  float acceleration;
  float weight;

  void accelerate();
};

#endif
