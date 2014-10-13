#include "neighbor.h"

Neighbor::Neighbor(){}

Neighbor::Neighbor(Instance instance)
{
    this->instance = instance;
    this->distance = 0.0;
}

Neighbor::Neighbor(Instance instance, double distance)
{
    this->instance = instance;
    this->distance = distance;
}

Instance
Neighbor::getInstance()
{
    return this->instance;
}

double
Neighbor::getDistance()
{
    return this->distance;
}

