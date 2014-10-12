#include "neighbor.h"

Neighbor::Neighbor(){}

Neighbor::Neighbor(Instance instance)
{
    this->instance = instance;
}

void
Neighbor::calculateDistance(Neighbor neighbor)
{
    double distance=0.0;
    vector<int> localAttr, neighborAttr;

    localAttr = this->instance.getAttributes();
    neighborAttr = neighbor.getInstance().getAttributes();

    for(unsigned int i=0; i<localAttr.size(); i++)
        distance += pow((localAttr[i] - neighborAttr[i]), 2);
    
    this->distance = sqrt(distance);
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

