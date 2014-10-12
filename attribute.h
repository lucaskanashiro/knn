#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

using namespace std;

class Attribute
{
  public:

    Attribute(String name);
    void setValue(int value);

  private:

    String name;
    int value;
}

#endif

