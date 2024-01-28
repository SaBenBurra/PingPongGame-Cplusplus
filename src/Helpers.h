#ifndef HELPERS
#define HELPERS

#include <cstdlib>
#include <ctime>
#include <iostream>

class Helpers {
public:
  static float randomFloatBetween(float minValue, float maxValue) {
    static bool seedSet = false;
    if (!seedSet) {
      std::srand(static_cast<unsigned int>(std::time(nullptr)));
      seedSet = true;
    }

    float randomValue =
        minValue + static_cast<float>(std::rand()) /
                       (static_cast<float>(RAND_MAX / (maxValue - minValue)));

    return randomValue;
  }
};

#endif
