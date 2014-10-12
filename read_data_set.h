#ifndef READ_DATA_SET_H
#define READ_DATA_SET_H

#include <iostream>
#include "instance.h"

using namespace std;

class ReadDataSet
{
  public:
    
    ReadDataSet(String file_path);
    vector<Instance> buildInstances();

  private:

    String file_path;
}

#endif

