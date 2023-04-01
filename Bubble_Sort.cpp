// Finding the number of connected components in an undirected graph

#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int> &array)
{
    for (int i = 0; i < array.size() - 1; i++)
    {
        for (int j = 0; j < array.size() - 1; j++)
        {
            if (array.at(j) > array.at(j + 1))
            {
                int temp = array.at(j);
                array.at(j) = array.at(j + 1);
                array.at(j + 1) = temp;
            }
        }
    }
}

int main()
{
    vector<int> testingArray = {6, 3, 5, 2, 1, 4};

    bubble_sort(testingArray);

    for (int i = 0; i < testingArray.size(); i++)
    {
        cout << testingArray.at(i) << " ";
    }
}