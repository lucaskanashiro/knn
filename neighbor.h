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
    Neighbor(Instance instance, double distance);
    void calculateDistance(Neighbor neighbor);
    Instance getInstance();
    double getDistance();
    void cleanDistance();

  private:

    Instance instance;
    double distance;
};

#endif

