// Finding the number of connected components in an undirected graph

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int from, int to)
{

    int pi = from;
    int pivot_value = arr[to];

    for (int i = from; i < to; i++)
    {

        if (arr[i] < pivot_value)
        {
            int temp = arr[pi];
            arr[pi] = arr[i];
            arr[i] = temp;
            pi++;
        }
    }

    int temp = arr[to];
    arr[to] = arr[pi];
    arr[pi] = temp;

    return pi;
}

void quick_sort(vector<int> &arr, int from, int to)
{
    if (from < to)
    {
        int pivot_position = partition(arr, from, to);
        quick_sort(arr, from, pivot_position - 1);
        quick_sort(arr, pivot_position + 1, to);
    }
}

int main()
{
    vector<int> testingArray = {6, 3, 5, 2, 1, 4};

    quick_sort(testingArray, 0, testingArray.size() - 1);

    for (int i = 0; i < testingArray.size(); i++)
    {
        cout << testingArray.at(i) << " ";
    }
}