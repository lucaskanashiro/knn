#include "data_set.h"

DataSet::DataSet(){}

vector<Neighbor>
DataSet::build(string file_path)
{
    ifstream file(file_path.c_str());

    if(!file.is_open())
    {
        cout << "Impossible to open the file!!!" << endl;
        exit(-1);
    }

    string line;
    Neighbor neighbor;
    vector<Neighbor> neighbors;


    while(getline(file, line))
    {
        if(line.empty())
            continue;

        stringstream stream(line);
        int value, classification;
        vector<int> attr;

        while(stream >> value)
        {
            attr.push_back(value);

            if(stream.peek() == ',')
                stream.ignore();
        }

        classification = attr.back();
        attr.pop_back();

        neighbor = Neighbor(Instance(attr, classification));
        neighbors.push_back(neighbor);
    }
    
    return neighbors;
}

void
DataSet::writeResult(vector<Result> result)
{
    ofstream output;

    output.open("result.txt");

    for(unsigned int i=0; i<result.size(); i++)
        output << "Instance " << i+1 << ": " << result[i].getClassification() << endl;

    output.close();
}


