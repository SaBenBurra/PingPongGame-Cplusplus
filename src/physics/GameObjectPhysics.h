#ifndef GAMEOBJECTPHYSICS
#define GAMEOBJECTPHYSICS

#include "Force.h"
#include "Momentum.h"
#include "Velocity.h"

class GameObjectPhysics {

private:
  Force force;
  Momentum momentum;

  void setVelocity(Velocity velocity) { this->velocity = velocity; }
  void setForce(Force force) { this->force = force; }
  void setMomentum(Momentum momentum) { this->momentum = momentum; }

  friend class PhysicsManager;

public:
  Velocity velocity;
  bool active = false;
  bool hasGravity = false;
  int g = 10;
  bool hasCollider = false;

  GameObjectPhysics(Velocity &velocity, Force &force, Momentum &momentum)
      : velocity(velocity), force(force), momentum(momentum) {}

  Velocity getVelocity() { return velocity; }
  Force getForce() { return force; }
  Momentum getMomentum() { return momentum; }
};

#endif
