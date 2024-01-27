#include "game_elements/Ball.h"
#include "game_elements/Bat.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>

int main() {
  sf::Font font;
  if (!font.loadFromFile("src/assets/fonts/Arial.ttf"))
    std::cout << "FONT ERROR";

  sf::RenderWindow window;

  window.create(sf::VideoMode(), "Ping Pong Game", sf::Style::Fullscreen);
  window.setVerticalSyncEnabled(true);

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
  return 0;
}
