#include <iostream>
#include <iomanip>
#include <ctime> 
using namespace std;

void Create(int** T, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** T, const int rowCount, const int colCount);
void SortRows(int** T, const int rowCount, const int colCount);
void SwapRows(int** T, const int row1, const int row2, const int colCount);
void CalcSumAndCount(int** T, const int rowCount, const int colCount, int& sum, int& count);

int main()
{
    srand((unsigned)time(NULL));

    const int Low = -17;
    const int High = 14;
    const int rowCount = 8;
    const int colCount = 5;

    int** T = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        T[i] = new int[colCount];

    Create(T, rowCount, colCount, Low, High);
    cout << "Original matrix:" << endl;
    Print(T, rowCount, colCount);

    SortRows(T, rowCount, colCount);
    cout << "Sorted matrix:" << endl;
    Print(T, rowCount, colCount);

    int sum = 0;
    int count = 0;
    CalcSumAndCount(T, rowCount, colCount, sum, count);

    cout << "Sum = " << sum << endl;
    cout << "Count of elements = " << count << endl;
    cout << "Modified matrix:" << endl;
    Print(T, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] T[i];
    delete[] T;

    return 0;
}

void Create(int** T, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            T[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** T, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(5) << T[i][j];
        cout << endl;
    }
    cout << endl;
}

void SortRows(int** T, const int rowCount, const int colCount)
{
    for (int i0 = 0; i0 < rowCount - 1; i0++)
    {
        for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
        {
            bool shouldSwap = false;
            if (T[i1][0] > T[i1 + 1][0])
            {
                shouldSwap = true;
            }
            else if (T[i1][0] == T[i1 + 1][0])
            {
                if (T[i1][1] > T[i1 + 1][1])
                {
                    shouldSwap = true;
                }
                else if (T[i1][1] == T[i1 + 1][1])
                {
                    if (T[i1][2] > T[i1 + 1][2])
                    {
                        shouldSwap = true;
                    }
                }
            }
            if (shouldSwap)
                SwapRows(T, i1, i1 + 1, colCount);
        }
    }
}

void SwapRows(int** T, const int row1, const int row2, const int colCount)
{
    for (int j = 0; j < colCount; j++)
    {
        int temp = T[row1][j];
        T[row1][j] = T[row2][j];
        T[row2][j] = temp;
    }
}

void CalcSumAndCount(int** T, const int rowCount, const int colCount, int& sum, int& count)
{
    sum = 0;
    count = 0;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            if (T[i][j] < 0 && !(T[i][j] % 4 == 0))
            {
                sum += T[i][j]; 
                count++;        
                T[i][j] = 0;
            }
        }
    }
}