#include <iostream>
using namespace std;

int **dynamic2DArray(int rows, int columns);
void delete2DArr(int **arr, int rows);

int main()
{
    int **heapArr = dynamic2DArray(12, 12);
    delete2DArr(heapArr, 12);
    return 0;
}

int **dynamic2DArray(int rows, int columns)
{
    int **new2DArr = new int *[rows];
    for (int row = 0; row < rows; row++)
    {
        new2DArr[row] = new int[columns];
    }
    int counter = 1;
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            new2DArr[row][column] = counter++;
        }
    }
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            cout << new2DArr[row][column] << "\t";
        }
        cout << endl;
    }
    return new2DArr;
}

void delete2DArr(int **arr, int rows)
{
    for (int row = 0; row < rows; row++)
    {
        delete[] arr[row];
        arr[row] = nullptr;
        cout << "Row " << row << " has been deleted" << endl;
    }
    delete[] arr;
    arr = nullptr;
    cout << "Your dynamic 2D Array has been deleted";
}

// TEST CASE OUTPUT
// 1       2       3       4       5       6       7       8       9       10      11      12
// 13      14      15      16      17      18      19      20      21      22      23      24
// 25      26      27      28      29      30      31      32      33      34      35      36
// 37      38      39      40      41      42      43      44      45      46      47      48
// 49      50      51      52      53      54      55      56      57      58      59      60
// 61      62      63      64      65      66      67      68      69      70      71      72
// 73      74      75      76      77      78      79      80      81      82      83      84
// 85      86      87      88      89      90      91      92      93      94      95      96
// 97      98      99      100     101     102     103     104     105     106     107     108
// 109     110     111     112     113     114     115     116     117     118     119     120
// 121     122     123     124     125     126     127     128     129     130     131     132
// 133     134     135     136     137     138     139     140     141     142     143     144
// Row 0 has been deleted
// Row 1 has been deleted
// Row 2 has been deleted
// Row 3 has been deleted
// Row 4 has been deleted
// Row 5 has been deleted
// Row 6 has been deleted
// Row 7 has been deleted
// Row 8 has been deleted
// Row 9 has been deleted
// Row 10 has been deleted
// Row 11 has been deleted
// Your dynamic 2D Array has been deleted