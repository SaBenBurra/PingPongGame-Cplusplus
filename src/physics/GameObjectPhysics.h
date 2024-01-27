#include "Force.h"
#include "Momentum.h"
#include "Velocity.h"

class GameObjectPhysics {
  bool active = false;
  bool hasGravity = false;
  bool mass;
  int g;
  bool hasCollider;

  Velocity velocity;
  Force force;
  Momentum momentum;
};
