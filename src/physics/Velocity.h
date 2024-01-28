#ifndef VELOCITY
#define VELOCITY

#include "VectorQuantity.h"
#include <SFML/System/Vector2.hpp>

class Velocity : public VectorQuantity {
public:
  Velocity(sf::Vector2f &direction, float magnitude)
      : VectorQuantity(direction, magnitude) {}
};

#endif
