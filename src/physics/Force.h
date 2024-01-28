#ifndef FORCE
#define FORCE

#include "VectorQuantity.h"
#include <SFML/System/Vector2.hpp>

class Force : public VectorQuantity {
public:
  Force(sf::Vector2f &direction, float magnitude)
      : VectorQuantity(direction, magnitude) {}
};

#endif
