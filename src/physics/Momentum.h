#ifndef MOMENTUM
#define MOMENTUM

#include "VectorQuantity.h"

class Momentum : public VectorQuantity {
public:
  Momentum(sf::Vector2f &direction, float magnitude)
      : VectorQuantity(direction, magnitude) {}
};

#endif
