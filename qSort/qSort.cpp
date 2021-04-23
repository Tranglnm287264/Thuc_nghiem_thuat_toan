#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <time.h>
#include <algorithm>
using namespace std;
void Xuat(string, float[], int);
int compare(const void*, const void*);


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
    qsort(a, 1000000, sizeof(*a), compare);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    cout << duration;
    string fo("saptang.txt");
    Xuat(fo, a, n);
    delete[]a;
    return 0;
}

int compare(const void* p, const void* q)
{
    float x = *(const float*)p;
    float y = *(const float*)q;
    if (x < y)
        return -1;
    else if (x > y)
        return 1;
    return 0;
    return (x > y) - (x < y);
}

void Xuat(string filename, float a[], int n)
{
    ofstream fo(filename);
    for (int i = 0; i < n; i++)
    {
        fo << a[i] << setw(10);
    }
}