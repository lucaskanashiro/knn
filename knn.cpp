#include "knn.h"

KNN::KNN(int k)
{
    this->k = k;
}

double
KNN::analysisData(string dataTraineFile, string dataTestFile)
{
    this->traineData = this->fileManager.build(dataTraineFile);
    this->testData = this->fileManager.build(dataTestFile);

    vector<Result> result;
    int ok=0, fail=0;

    for(unsigned int j=0; j<this->testData.size(); j++)
    {
        int predictedClassification = classificateData(this->testData[j], this->traineData);

        if(predictedClassification == this->testData[j].getInstance().getClassification())
            ok++;
        else
            fail++;

        result.push_back(Result(this->testData[j], predictedClassification));

        cout << ".";
    }

    cout << endl << endl;

    this->fileManager.writeResult(result);

    double precision = (ok / (ok + fail))*100;

    cout << "TOTAL INSTANCES: " << ok+fail << endl;
    cout << "OK: "<< ok << "\tFail: " << fail << endl;

    return precision;
}

int 
KNN::classificateData(Neighbor point, vector<Neighbor> neighbors)
{
    double distance;
    vector<Neighbor> neigh, nearest;

    for (unsigned int i=0; i<neighbors.size(); i++){

        distance = this->calculateDistance(point, neighbors[i]);

        if(distance == 0)
            return neighbors[i].getInstance().getClassification();

        Neighbor n = Neighbor(neighbors[i].getInstance(), distance);

        neigh.push_back(n);
    }

    nearest = this->getNearestNeighbors(neigh);

    int predictedClassification = this->determineMajority(nearest);

    return predictedClassification;
}

double
KNN::calculateDistance(Neighbor a, Neighbor b)
{
    double distance=0.0;
    vector<int> attrA, attrB;

    attrA = a.getInstance().getAttributes();
    attrB = b.getInstance().getAttributes();

    for(unsigned int i=0; i<attrA.size(); i++)
        distance += pow((attrA[i]-attrB[i]), 2);

    return sqrt(distance);
}

bool
compare(Neighbor a, Neighbor b)
{
    return a.getDistance() < b.getDistance();
}

vector<Neighbor>
KNN::getNearestNeighbors(vector<Neighbor> allNeighbors)
{
    vector<Neighbor> nearest;

    sort(allNeighbors.begin(), allNeighbors.end(), compare);

    for(int i=0; i<this->k; i++)
        nearest.push_back(allNeighbors[i]);

    return nearest;
}

int
KNN::determineMajority(vector<Neighbor> nearestNeighbors)
{
    map<int,int> count;
    pair<int,int> champion;
    int aux=-1;

    for(unsigned int i=0; i<nearestNeighbors.size(); i++)
        count[ nearestNeighbors[i].getInstance().getClassification() ]++;

    map<int,int>::iterator it = count.begin();

    for(;it != count.end(); ++it)
    {
        cout << it->first << " -> " << it->second << endl;
        if(it->second > aux)
        {
            champion = *it;
            aux = it->second;
        }
    }

    return champion.first;
}

