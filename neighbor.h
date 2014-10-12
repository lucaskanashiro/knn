#ifndef NEIGHBOR_H
#define NEIGHBOR_H

#include "instance.h"

using namespace std;

class Neighbor
{
  public:

    Neighbor(Instance instance);
    void calculateDistance(Neighbor neighbor);

  private:

    Instance instance;
    double distance;
}

#endif

