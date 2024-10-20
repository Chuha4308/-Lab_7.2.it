#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>

using namespace std;

void CreateMatrix(int** a, const int n, const int Low, const int High);
void PrintMatrix(int** a, const int n);
void SwapMaxToDiagonal(int** a, const int n);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand((unsigned)time(NULL));

    int Low = -50;
    int High = 50;
    int n;
    cout << " n = ";
    cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];


    CreateMatrix(a, n, Low, High);
    PrintMatrix(a, n);


    SwapMaxToDiagonal(a, n);
    PrintMatrix(a, n);

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void CreateMatrix(int** a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void PrintMatrix(int** a, const int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void SwapMaxToDiagonal(int** a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        int maxIndex = i; 
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] > a[i][maxIndex])
                maxIndex = j; 
        }
        if (maxIndex != i) 
            swap(a[i][i], a[i][maxIndex]);
    }
}
