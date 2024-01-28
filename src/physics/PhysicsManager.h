#ifndef PHYSICSMANAGER
#define PHYSICSMANAGER

#include "../Helpers.h"
#include "../game_elements/GameObject.h"
#include "Velocity.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <vector>

class PhysicsManager {
public:
  static void setVelocityToGameObject(GameObject gameObject,
                                      Velocity *velocity) {}

  static void setRandomVelocityToGameObject(GameObject *gameObject) {

    int valueX = Helpers::randomFloatBetween(0, 10);
    int valueY = Helpers::randomFloatBetween(0, 10);
    int magnitude = Helpers::randomFloatBetween(10, 20);

    sf::Vector2f direction(valueX, valueY);

    Velocity velocity(direction, magnitude);

    gameObject->physics.velocity = velocity;
  }

  static void renderPhysics(std::vector<GameObject> *gameObjects,
                            float timeDelta) {
    for (GameObject &gameObject : *gameObjects) {

      if (gameObject.physics.active) {
        sf::Vector2f vDirection = gameObject.physics.velocity.direction;

        float vMagnitude = gameObject.physics.velocity.magnitude;

        // timeDelta *= .1f;
        float offsetX = vMagnitude * vDirection.x * timeDelta;
        float offsetY = vMagnitude * vDirection.y * timeDelta;

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
};

#endif
