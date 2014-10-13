#include "knn.h"

KNN::KNN(int k)
{
    this->k = k;
}

double
KNN::analysisData(string dataTraineFile, string dataTestFile, string outputFile)
{
    vector<Result> result;
    int ok=0, fail=0;

    this->traineData = this->fileManager.build(dataTraineFile);
    this->testData = this->fileManager.build(dataTestFile);

    for(unsigned int i=0; i<this->testData.size(); i++)
    {
        vector<Neighbor> nearest;
        int predictedClassification;

        this->calculateDistance(this->testData[i]);
        nearest = this->getNearestNeighbors();
        predictedClassification = this->determineMajority(nearest);

        if(predictedClassification == this->testData[i].getInstance().getClassification())
            ok++;
        else
            fail++;

        result.push_back(Result(this->testData[i], predictedClassification));
    }

    this->fileManager.writeResult(result, outputFile);

    double precision = ok / (ok + fail);

    cout << "OK: "<< ok << "\tFail: " << fail << endl;
    cout << "PRECISION: " << precision << endl;

    return precision;
}

void
KNN::calculateDistance(Neighbor reference)
{
    for(unsigned int i=0; i<this->traineData.size(); i++)
        this->traineData[i].calculateDistance(reference);
}

bool
compare(Neighbor a, Neighbor b)
{
    return a.getDistance() < b.getDistance();
}

vector<Neighbor>
KNN::getNearestNeighbors()
{
    vector<Neighbor> nearest;

    sort(this->traineData.begin(), this->traineData.end(), compare);

    for(int i=0; i<this->k; i++)
    {
        cout << this->traineData[i].getInstance().getClassification() << "\tDist: " << this->traineData[i].getDistance()<< endl;
        nearest.push_back(this->traineData[i]);
    }

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

