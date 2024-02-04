#include "../physics/PhysicsManager.h"
#include "GameObject.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

class Ball : public GameObject {
public:
  Ball(float radius, sf::Vector2u windowSize, float positionX = 0,
       float positionY = 0)
      : GameObject(new sf::CircleShape(radius), *PhysicsManager::ZeroPhysics(),
                   windowSize, positionX, positionY) {}
};
