#ifndef KNN_H
#define KNN_H

#include <map>
#include <algorithm>
#include "data_set.h"
#include "neighbor.h"
#include "result.h"

using namespace std;

class KNN
{
  public:

    KNN(int k);
    double analysisData(string dataTraineFile, string dataTestFile, string outputFile);

  private:

    void calculateDistance(Neighbor reference);
    vector<Neighbor> getNearestNeighbors();
    int determineMajority(vector<Neighbor> nearestNeighbors);

    vector<Neighbor> traineData, testData;
    int k;
    DataSet fileManager;
};

#endif

