#include <iostream>
#include <string.h>
#include "knn.h"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc == 1)
    {
        cout << "You must pass some parameters. Run \"./KNN help\" to take some tips." << endl;
    }

    if(argc == 2 && strcmp(argv[1],"help") == 0)
    {
        cout << "This is a implemantation of KNN algorithm. Case of handwritten numbers." << endl << endl;
        cout << "[USAGE]: ./KNN [dataTraineFile] [dataTestFile] [outputFile]" << endl;
    }

    if(argc == 4)
    {
        string dataTraineFile = argv[1];
        string dataTestFile = argv[2];
        string outputFile = argv[3];

        KNN knn = KNN(5);

        double precision = knn.analysisData(dataTraineFile, dataTestFile, outputFile);

        cout << "Precision of this test data:  " << precision << "%" << endl << endl;
        cout << "You can view details of this execution in " << outputFile << endl;
    }

    return 0;
}

