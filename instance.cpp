#include "instance.h"

Instance::Instance(){}

Instance::Instance(vector<int> attributes)
{
    this->attributes = attributes;
}

Instance::Instance(vector<int> attributes, int classification)
{
    this->attributes = attributes;
    this->classification = classification;
}

int
Instance::getClassification()
{
    return this->classification;
}

vector<int>
Instance::getAttributes()
{
    return this->attributes;
}

