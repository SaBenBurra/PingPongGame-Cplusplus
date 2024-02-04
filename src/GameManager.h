#include "game_elements/GameObjectManager.h"
#include "physics/PhysicsManager.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <cstdlib>
#include <thread>

class GameManager {

public:
  GameManager *setup() {
    if (!arialFont.loadFromFile("src/assets/fonts/Arial.ttf"))
      std::cout << "FONT ERROR";

    window.create(sf::VideoMode(), "Ping Pong Game", sf::Style::Fullscreen);
    window.setVerticalSyncEnabled(true);

    return this;
  }

  void run() {
    gameObjectManager.createGameObjects(&window);

    physicsManager.setRandomVelocityToGameObject(
        &gameObjectManager.gameObjects[0]);

    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;

    while (window.isOpen()) {
      start = std::chrono::high_resolution_clock::now();
      window.clear(sf::Color::Black);

      windowSizeX = window.getSize().x;
      windowSizeY = window.getSize().y;

      GameObject *ball = &gameObjectManager.gameObjects[0];
      GameObject *bat = &gameObjectManager.gameObjects[1];

      sf::Event event;

      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
          float moveSpeed = 30.f;
          if (event.key.code == sf::Keyboard::Left)
            bat->shape->setPosition(bat->shape->getPosition().x - moveSpeed,
                                    bat->shape->getPosition().y);
          if (event.key.code == sf::Keyboard::Right)

            bat->shape->setPosition(bat->shape->getPosition().x + moveSpeed,
                                    bat->shape->getPosition().y);
        }
      }

      end = std::chrono::high_resolution_clock::now();
      float fps = (float)1e9 /
                  (float)std::chrono::duration_cast<std::chrono::nanoseconds>(
                      end - start)
                      .count();
      float timeDelta = 1 / fps;

      physicsManager.renderPhysics(&gameObjectManager.gameObjects, timeDelta,
                                   &window);

      if (ball->shape->getGlobalBounds().intersects(
              bat->shape->getGlobalBounds())) {
        ball->physics.velocity.direction.y =
            ball->physics.velocity.direction.y * -1;
      }
      gameObjectManager.drawGameObjects(&window);

      checkIfBallTouchsBottom();

      window.display();
    }
  }

private:
  GameObjectManager gameObjectManager;
  PhysicsManager physicsManager;
  sf::Font arialFont;
  sf::RenderWindow window;
  int windowSizeX;
  int windowSizeY;

  void checkIfBallTouchsBottom() {
    GameObject *ball = &gameObjectManager.gameObjects[0];
    sf::FloatRect bounds = ball->shape->getGlobalBounds();
    if (bounds.top + bounds.height >= window.getSize().y) {
      abort();
    }
  }
};
