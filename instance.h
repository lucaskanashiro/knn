#ifndef INSTANCE_H
#define INSTANCE_H

using namespace std;

#include <vector>
#include "attribute.h"

class Instace
{
  public:

    Instance(vector<Attribute> attributes);
    Instance(vector<Attribute> attributes, int classification);
    int getClassification();

  private:

    vector<Attribute> attributes;
    int classification;
}

#endif

