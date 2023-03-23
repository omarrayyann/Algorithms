// Finding the number of connected components in an undirected graph

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int from, int to, int middle)
{

    vector<int> newArray;
    int currentFrom = from;
    int currentTo = middle + 1;

    while (currentTo <= middle && currentFrom <= to)
    {
        if (arr.at(currentTo) < arr.at(currentFrom))
        {
            newArray.push_back(arr.at(currentTo));
            currentTo++;
        }
        else
        {
            newArray.push_back(arr.at(currentFrom));
            currentFrom++;
        }
    }

    while (currentTo <= middle)
    {
        newArray.push_back(arr.at(currentTo));
        currentTo++;
    }

    while (currentFrom <= to)
    {
        newArray.push_back(arr.at(currentFrom));
        currentFrom++;
    }

    int index = from;
    for (int i = 0; i < newArray.size(); i++)
    {
        arr.at(index) = newArray.at(i);
        index++;
    }
}

void merge_sort(vector<int> &arr, int from, int to)
{

    if (from < to)
    
    {
        int middle = (from + to) / 2;
        merge_sort(arr, from, middle);
        merge_sort(arr, middle + 1, to);
        merge(arr, from, to, middle);
    }
}

int main()
{
    vector<int> testingArray = {4, 3, 7, 2, 1, 3, 5, 6};

    merge_sort(testingArray, 0, testingArray.size() - 1);
    for (int i = 0; i < testingArray.size(); i++)
    {
        cout << testingArray.at(i) << ", ";
    }
}