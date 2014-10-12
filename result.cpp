#include "result.h"

Result::Result(Neighbor neighbor, int classification)
{
    this->neighbor = neighbor;
    this->classification = classification;
}

Neighbor
Result::getNeighbor()
{
    return this->neighbor;
}

int
Result::getClassification()
{
    return this->classification;
}

