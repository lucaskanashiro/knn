#ifndef INSTANCE_H
#define INSTANCE_H

using namespace std;

#include <vector>

class Instance
{
  public:

    Instance();
    Instance(vector<int> attributes);
    Instance(vector<int> attributes, int classification);
    int getClassification();
    vector<int> getAttributes();

  private:

    vector<int> attributes;
    int classification;
};

#endif

