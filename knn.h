#ifndef KNN_H
#define KNN_H

#include <map>
#include <algorithm>
#include <cmath>
#include "data_set.h"
#include "neighbor.h"
#include "result.h"

using namespace std;

class KNN
{
  public:

    KNN(int k);
    double analysisData(string dataTraineFile, string dataTestFile);

  private:

    double calculateDistance(Neighbor a, Neighbor b);
    vector<Neighbor> getNearestNeighbors(vector<Neighbor> allNeighbors);
    int determineMajority(vector<Neighbor> nearestNeighbors);
    int classificateData(Neighbor point, vector<Neighbor> neighbors);

    vector<Neighbor> traineData, testData;
    int k;
    DataSet fileManager;
};

#endif

