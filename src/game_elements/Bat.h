#include "../physics/PhysicsManager.h"
#include "GameObject.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Window.hpp>
class Bat : public GameObject {
public:
  Bat(float sizeX, float sizeY, sf::Vector2u windowSize)
      : GameObject(new sf::RectangleShape(sf::Vector2f(sizeX, sizeY)),
                   *PhysicsManager::ZeroPhysics(), windowSize) {}
};
