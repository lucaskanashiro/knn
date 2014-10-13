#ifndef NEIGHBOR_H
#define NEIGHBOR_H

#include "instance.h"

using namespace std;

class Neighbor
{
  public:

    Neighbor();
    Neighbor(Instance instance);
    Neighbor(Instance instance, double distance);
    Instance getInstance();
    double getDistance();

  private:

    Instance instance;
    double distance;
};

#endif

