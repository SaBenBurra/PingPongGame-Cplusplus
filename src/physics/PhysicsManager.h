#ifndef PHYSICSMANAGER
#define PHYSICSMANAGER

#include "../Helpers.h"
#include "../game_elements/GameObject.h"
#include "Velocity.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>

class PhysicsManager {
public:
  static void setRandomVelocityToGameObject(GameObject *gameObject) {

    int valueX = Helpers::randomFloatBetween(-10, 10);
    int valueY = Helpers::randomFloatBetween(-10, 10);

    int magnitude = 60;
    sf::Vector2f direction(valueX, valueY);

    Velocity velocity(direction, magnitude);

    gameObject->physics.setVelocity(velocity);
  }

  static void renderPhysics(std::vector<GameObject> *gameObjects,
                            float timeDelta, sf::RenderWindow *window) {
    for (GameObject &gameObject : *gameObjects) {

      if (gameObject.physics.active) {
        sf::Vector2f vDirection = gameObject.physics.velocity.direction;

        float vMagnitude = gameObject.physics.velocity.magnitude;

        float offsetX = vMagnitude * vDirection.x * timeDelta;
        float offsetY = vMagnitude * vDirection.y * timeDelta;

        checkIfGameObjectOnEdge(&gameObject, window);

        gameObject.move(offsetX, offsetY);
      }
    }
  }

  static Velocity *ZeroVelocity() {
    return new Velocity(*new sf::Vector2f(0, 0), 0);
  }

  static Momentum *ZeroMomentum() {
    return new Momentum(*new sf::Vector2f(0, 0), 0);
  }
  static Force *ZeroForce() { return new Force(*new sf::Vector2f(0, 0), 0); }

  static GameObjectPhysics *ZeroPhysics() {

    return new GameObjectPhysics(*ZeroVelocity(), *ZeroForce(),
                                 *ZeroMomentum());
  }

  static void reflectVelocityX(Velocity *velocity) { velocity->reflectX(); }
  static void reflectVelocityY(Velocity *velocity) { velocity->reflectX(); }
  static void reflectVelocity(Velocity *velocity) {
    reflectVelocityX(velocity);
    reflectVelocityY(velocity);
  }

private:
  static void checkIfGameObjectOnEdge(GameObject *gameObject,
                                      sf::RenderWindow *window) {

    sf::Vector2f vDirection = gameObject->physics.velocity.direction;
    if (vDirection.x == 0 and vDirection.y == 0) {
      return;
    }
    sf::FloatRect bounds = gameObject->shape->getGlobalBounds();

    if (bounds.left + bounds.width > window->getSize().x) {
      gameObject->physics.velocity.direction.x =
          -1 * fabs(gameObject->physics.velocity.direction.x);
    }
    if (bounds.left < 0) {
      gameObject->physics.velocity.direction.x =
          fabs(gameObject->physics.velocity.direction.x);
    }
    if (bounds.top + bounds.height > window->getSize().y) {
      gameObject->physics.velocity.direction.y =
          -1 * fabs(gameObject->physics.velocity.direction.y);
    }
    if (bounds.top < 0) {
      gameObject->physics.velocity.direction.y =
          fabs(gameObject->physics.velocity.direction.y);
    }
  }
};

#endif
