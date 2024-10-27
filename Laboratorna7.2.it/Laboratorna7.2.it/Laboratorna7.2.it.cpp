#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
int findSumOfMaxInAllRows(int** a, const int rowCount, const int colCount);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand((unsigned)time(NULL));

    int Low = -41; 
    int High = 23; 
    int rowCount;
    int colCount;
    cout << "k = "; cin >> rowCount;
    cout << "n = "; cin >> colCount;

    int** a = new int* [rowCount];

    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);

    int sum = findSumOfMaxInAllRows(a, rowCount, colCount);
    cout << "Сума максимальних елементів по всіх рядках: " << sum << endl;

    Print(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int findSumOfMaxInAllRows(int** a, const int rowCount, const int colCount)
{
    int sum = 0;

    for (int i = 0; i < rowCount; i++)
    {
        int max = a[i][0];

        for (int j = 0; j < colCount; j++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
            }
        }

        sum += max;
    }

    return sum;
}
