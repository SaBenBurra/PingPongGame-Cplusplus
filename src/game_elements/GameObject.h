#ifndef GAMEOBJECT_
#define GAMEOBJECT_

#include "../physics/GameObjectPhysics.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <iostream>

class GameObject {
public:
  sf::Shape *shape;
  float positionX, positionY;
  float windowSizeX;
  float windowSizeY;
  GameObjectPhysics physics;

  GameObject(sf::Shape *shape, GameObjectPhysics &physics,
             sf::Vector2u windowSize, float positionX, float positionY)
      : physics(physics) {
    this->shape = shape;
    this->positionX = positionX;
    this->positionY = positionY;
    this->shape->setPosition(positionX, positionY);

    sf::FloatRect bounds = shape->getLocalBounds();
    shape->setOrigin(bounds.width / 2.f, bounds.height / 2.f);

    windowSizeX = windowSize.x;
    windowSizeY = windowSize.y;
  }

  void move(float offsetX, float offsetY) {
    positionX += offsetX;
    positionY += offsetY;
    shape->setPosition(positionX, positionY);
  }
  void moveToCoordinate(float x, float y) {
    positionX = x;
    positionY = y;
    shape->setPosition(x, y);
  }

  void centerVertically() {
    positionX = shape->getPosition().x;

    if (shape->getPosition().x > windowSizeX * 9999999)
      positionX = 0;

    shape->setPosition(positionX, windowSizeY / 2.f);
  }

  void centerHorizontally() {
    positionY = shape->getPosition().y;

    if (shape->getPosition().y > windowSizeY * 9999999)
      positionY = 0;

    shape->setPosition(windowSizeX / 2.f, positionY);
  }

  void center() {
    centerVertically();
    centerHorizontally();
  }

  void setPosX(float x) { shape->setPosition(x, shape->getPosition().y); }

  void setPosY(float y) { shape->setPosition(shape->getPosition().x, y); }
};

#endif
