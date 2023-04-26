#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <cmath>
#include <float.h>
#include <algorithm>

using namespace std;

int partition(vector<int> &arr, int from, int to, int value)
{
    for (int i = from; i <= to; i++)
    {
        if (arr.at(i) == value)
        {
            int temp = arr.at(to);
            arr.at(to) = arr.at(i);
            arr.at(i) = temp;
            break;
        }
    }

    int pi = from;
    int pivot_value = arr[to];

    for (int i = from; i < to; i++)
    {

        if (arr[i] <= pivot_value)
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
    return pi - from;
}

int find_median(vector<int> &array, int from, int size)
{
    sort(array.begin() + from, array.begin() + from + size);
    int median = array.at(from + size / 2);
    return median;
}

int quick_select(vector<int> &array, int from, int to, int k)
{
    int number_of_elements = to - from + 1;
    if (k < number_of_elements)
    {
        // Sorting every 5 elements and storing their median
        vector<int> medians;
        for (int i = 0; i < number_of_elements / 5; i++)
        {
            int median = find_median(array, from + 5 * i, 5);
            medians.push_back(median);
        }
        // Last Group
        if (number_of_elements % 5)
        {
            int median = find_median(array, from + 5 * (number_of_elements / 5), number_of_elements % 5);
            medians.push_back(median);
        }

        // Median of Medians
        int median_of_medians;
        if (medians.size() == 1)
        {
            median_of_medians = medians.at(0);
        }
        else
        {
            median_of_medians = quick_select(medians, 0, medians.size() - 1, medians.size() / 2);
        }

        // Partition at the median of medians
        int partition_index = partition(array, from, to, median_of_medians);

        if (k == partition_index)
        {
            return median_of_medians;
        }
        else if (k < partition_index)
        {
            return quick_select(array, from, partition_index + from - 1, k);
        }
        else
        {
            return quick_select(array, partition_index + 1, to, from + k - (partition_index + 1));
        }
    }
    return INT_MAX;
}

int main()
{
    vector<int> array = {5, 6, 2, 4, 5, 2, 4, 5};
    int nthNeeded = 3;
    cout << quick_select(array, 0, array.size() - 1, nthNeeded) << endl;
}