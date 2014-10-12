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
    vector<int> attr;
    vector<Neighbor> neighbors;

    while(getline(file, line))
    {
        cout << line << endl;
        stringstream stream(line);
        int value, classification;

        while(stream >> value)
        {
            attr.push_back(value);
            stream.ignore(1);
        }

        //for(unsigned int i=0; i<attr.size(); i++)
        //{
        //    cout << attr[i] << endl;
        //}

        classification = attr.back();
        attr.pop_back();

        neighbor = Neighbor(Instance(attr, classification));
        neighbors.push_back(neighbor);
    }
    
    return neighbors;
}

void
DataSet::writeResult(vector<Result> result, string outputFile)
{
    ofstream output;

    output.open(outputFile.c_str());

    for(unsigned int i=0; i<result.size(); i++)
        output << "Instance " << i+1 << ": " << result[i].getClassification() << endl;

    output.close();
}


