#ifndef KNN_H
#define KNN_H

#include <cmath>
#include "read_data_set.h"
#include "neighbor.h"

using namespace std;

class KNN
{
  public:

    KNN(int k);
    double analysisData(vector<Neighbor> traineData, vector<Neighbor> testData, int numRuns);

  private:

    void calculateDistance(Neighbor reference);
    vector<Neighbor> getNearestNeighbors(Neighbor reference);
    int determineMajority(vector<Neighbor> nearestNeighbors);

    vector<Neighbor> traineData, testData;
    double precision;
    int k, numRuns;
}

#endif

