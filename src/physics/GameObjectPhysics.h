#ifndef GAMEOBJECTPHYSICS
#define GAMEOBJECTPHYSICS

#include "Force.h"
#include "Momentum.h"
#include "Velocity.h"

class GameObjectPhysics {
public:
  bool active = false;
  bool hasGravity = false;
  int g = 10;
  bool hasCollider = false;

  Velocity velocity;
  Force force;
  Momentum momentum;

  GameObjectPhysics(Velocity &velocity, Force &force, Momentum &momentum)
      : velocity(velocity), force(force), momentum(momentum) {}
};

#endif
