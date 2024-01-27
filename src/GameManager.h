#include "game_elements/Ball.h"
#include "game_elements/Bat.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>

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

    while (window.isOpen()) {
      sf::Event event;

      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          window.close();
        }
      }

      window.clear(sf::Color::Black);

      Bat bat(50.f, 250.f, window.getSize());
      bat.shape->setFillColor(sf::Color::Yellow);
      bat.centerHorizontally();

      Ball ball(100.f, window.getSize());

      ball.shape->setFillColor(sf::Color::Red);
      ball.shape->move(500.f, 250.f);
      window.draw(*ball.shape);
      window.draw(*bat.shape);

      window.display();
    }
  }

private:
  sf::Font arialFont;
  sf::RenderWindow window;
};
