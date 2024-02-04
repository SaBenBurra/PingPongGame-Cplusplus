#include "../physics/PhysicsManager.h"
#include "Ball.h"
#include "Bat.h"
#include "GameObject.h"
#include <SFML/Graphics/RenderWindow.hpp>

class GameObjectManager {
public:
  std::vector<GameObject> gameObjects;

  void createGameObjects(sf::RenderWindow *window) {

    int windowSizeX = window->getSize().x;
    int windowSizeY = window->getSize().y;

    float batSizeY = windowSizeY / 100.f;
    Bat bat(windowSizeX / 8.f, batSizeY, window->getSize(), windowSizeX / 2.f,
            windowSizeY - batSizeY);

    bat.shape->setFillColor(sf::Color::Yellow);
    bat.centerHorizontally();
    bat.setPosY(windowSizeY - batSizeY);
    bat.physics.active = false;

    Ball ball(windowSizeX / 100.f, window->getSize(), 500.f, 250.f);
    ball.shape->setFillColor(sf::Color::Red);
    ball.physics.active = true;

    gameObjects.insert(gameObjects.end(), {ball, bat});
  }

  void drawGameObjects(sf::RenderWindow *window) {
    for (GameObject gameObject : gameObjects) {
      window->draw(*(gameObject.shape));
    }
  }
};
