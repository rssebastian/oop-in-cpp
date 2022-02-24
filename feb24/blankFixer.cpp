// Name: Ryan Sebastian
// Course: CIS 25 - OOP in C++
// Description: Prompts user for a file within the current directory to be added
// replacing two or more blanks with a single one

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

string makeTempFileTitle();
void copyFromTemp(fstream &tempFile, fstream &userFile);
void writeToTemp(fstream &userFile, fstream &tempFile);

int main()
{
    string toBeEdited;
    string tempFileTitle = makeTempFileTitle();
    fstream userFile;
    fstream tempFile;

    cout << "Which file would you like to edit?\n";
    cin >> toBeEdited;

    tempFile.open(tempFileTitle, ios::out);
    userFile.open(toBeEdited, ios::in);
    writeToTemp(userFile, tempFile);

    userFile.clear();
    userFile.close();
    tempFile.close();

    tempFile.open(tempFileTitle, ios::in);
    userFile.open(toBeEdited, ios::out);
    copyFromTemp(tempFile, userFile);

    tempFile.clear();
    tempFile.close();
    userFile.close();

    const char *c = tempFileTitle.c_str();
    remove(c);

    return 0;
}

string makeTempFileTitle()
{
    ifstream tempCheck;
    string tempFileTitle = "temp";
    tempCheck.open(tempFileTitle + ".txt");

    while (tempCheck)
    {
        tempCheck.close();
        tempFileTitle += "1";
        tempCheck.open(tempFileTitle + ".txt");
    }
    return tempFileTitle + ".txt";
}

void writeToTemp(fstream &userFile, fstream &tempFile)
{
    if (userFile)
    {
        char lastChar;
        char currentChar;
        while (!userFile.eof())
        {
            userFile.get(currentChar);
            if (lastChar == ' ' && currentChar == ' ')
            {
                continue;
            }
            else
            {
                tempFile.put(currentChar);
                lastChar = currentChar;
            }
        }
    }
    else
    {
        cout << "Could not open file!\n";
    }
}

void copyFromTemp(fstream &tempFile, fstream &userFile)
{
    if (tempFile)
    {
        while (!tempFile.eof())
        {
            string currentLine;
            getline(tempFile, currentLine);
            userFile << currentLine << '\n';
        }
    }
    else
    {
        cout << "Problem copying from buffer\n";
    }
}