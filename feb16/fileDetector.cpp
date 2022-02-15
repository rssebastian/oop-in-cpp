// Name: Ryan Sebastian
// Course: CIS25
// Description: File detector, prints if an argument name of a file exists
// within the current directory

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        ifstream inputFile;
        inputFile.open(argv[i]);

        if (inputFile)
        {
            cout << "FILE FOUND: \t" << argv[i] << endl;
            inputFile.close();
        }
        else
        {
            cout << "FILE NOT FOUND: " << argv[i] << endl;
        }
    }
}