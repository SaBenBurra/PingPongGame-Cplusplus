#ifndef VECTORQUANTITY
#define VECTORQUANTITY

#include <SFML/System/Vector2.hpp>

class VectorQuantity {
public:
  sf::Vector2f direction;
  float magnitude;

  VectorQuantity(const sf::Vector2f &direction, float magnitude)
      : direction(direction), magnitude(magnitude) {}
};

#endif
