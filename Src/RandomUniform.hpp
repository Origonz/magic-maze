#ifndef MMAZE_RANDOMUNIFORM_HPP
#define MMAZE_RANDOMUNIFORM_HPP
#include <random>
#include <iostream>

using namespace std;

namespace MMaze {
  class RandomUniform {
  private:
    default_random_engine generator;
  public:
    RandomUniform() {
      std::random_device rd ;
      generator.seed(rd());
    }
    
    int generer(int max) {
      uniform_int_distribution<int> distribution(0, max);
      return distribution(generator);
    }
  };

  extern RandomUniform rd;
}

#endif
