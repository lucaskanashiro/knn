#ifndef READ_DATA_SET_H
#define READ_DATA_SET_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "result.h"
#include "neighbor.h"

#define NUM_ATTR 16

using namespace std;

class DataSet
{
  public:
    
    DataSet();
    vector<Neighbor> build(string file_path);
    void writeResult(vector<Result> result, string outputFile);
};

#endif

