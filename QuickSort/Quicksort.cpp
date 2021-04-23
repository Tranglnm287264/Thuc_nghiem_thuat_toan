#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <time.h>
using namespace std;
void quickSort(float[], int, int);
void Xuat(string, float[], int);

int main()
{
    clock_t start, end;
    double duration;
    int n = 1000000;
    float* a = new float[n];
    ifstream fi("10.txt");
    if (fi.fail())
    {
        cout << "mo file that bai";
        return 0;
    }
    for (int i = 0; i < n; i++)
        fi >> a[i];
    start = clock();
    quickSort(a, 0, n - 1);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    cout << duration;
    string fo("saptang.txt");
    Xuat(fo, a, n);
    delete[]a;
    return 0;
}

void quickSort(float arr[], int left, int right)
{
    int i = left, j = right;
    float pivot = arr[(left + right) / 2];
    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        quickSort(arr, left, j);
    if (right > i)
        quickSort(arr, i, right);
}
void Xuat(string filename, float a[], int n)
{
    ofstream fo(filename);
    for (int i = 0; i < n; i++)
        fo << a[i] << setw(10);
}