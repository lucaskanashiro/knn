#ifndef RESULT_H
#define RESULT_H

#include "neighbor.h"

using namespace std;

class Result
{
  public:

    Result(Neighbor neighbor, int classification);
    Neighbor getNeighbor();
    int getClassification();

  private:

    Neighbor neighbor;
    int classification;
};

#endif

