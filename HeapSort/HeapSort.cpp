#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <time.h>
#include <algorithm>
#include <vector>
using namespace std;
void Xuat(string, float[], int);
void heapify(float[], int, int);
void heapSort(float[], int);

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
    heapSort(a, n);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    cout << duration;
    string fo("saptang.txt");
    Xuat(fo, a, n);
    delete[]a;
    return 0;
}

void heapify(float arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(float arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void Xuat(string filename, float a[], int n)
{
    ofstream fo(filename);
    for (int i = 0; i < n; i++)
        fo << a[i] << setw(10);
}