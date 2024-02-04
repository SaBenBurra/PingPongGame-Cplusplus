#ifndef VELOCITY
#define VELOCITY

#include "VectorQuantity.h"
#include <SFML/System/Vector2.hpp>

class Velocity : public VectorQuantity {
public:
  Velocity(sf::Vector2f &direction, float magnitude)
      : VectorQuantity(direction, magnitude) {}

public:
  void reflectX() { direction.x = -1 * direction.x; }
  void reflectY() { direction.y = -1 * direction.y; }
  friend class PhysicsManager;
};

#endif
