#ifndef NEIGHBOR_H
#define NEIGHBOR_H

#include <cmath>
#include "instance.h"

using namespace std;

class Neighbor
{
  public:

    Neighbor();
    Neighbor(Instance instance);
    void calculateDistance(Neighbor neighbor);
    Instance getInstance();
    double getDistance();

  private:

    Instance instance;
    double distance;
};

#endif

