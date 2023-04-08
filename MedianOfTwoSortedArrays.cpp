#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int median(vector<int> array, int from)
{
    int size = array.size() - from;
    if (size % 2 == 0)
    {
        int ans = (array.at((size / 2) + from) + array.at(size / 2 - 1 + from)) / 2;

        return (array.at((size / 2) + from) + array.at(size / 2 - 1 + from)) / 2;
    }
    else
    {
        int ans = array.at(size / 2 + from);
        return array.at(size / 2 + from);
    }
}

// Median of two ordered arrays in logn (in-place)
int findingMedian(vector<int> &A, vector<int> &B, int startingA, int startingB, int length)
{
    if (length == 1)
    {
        return (A.at(startingA) + B.at(startingB)) / 2;
    }
    else if (length == 2)
    {
        return (max(A.at(startingA), B.at(startingB)) + min(A.at(startingA + 1), B.at(startingB + 1))) / 2;
    }
    else
    {
        if (median(A, startingA) == median(B, startingB))
        {
            return median(A, startingA);
        }
        else if (median(A, startingA) < median(B, startingB))
        {
            if (length % 2 == 0)
            {
                return findingMedian(A, B, startingA + length / 2 - 1, startingB, length - (length / 2) + 1);
            }
            else
            {
                return findingMedian(A, B, startingA + length / 2, startingB, length - (length / 2));
            }
        }
        else
        {
            if (length % 2 == 0)
            {
                return findingMedian(A, B, startingA, startingB + length / 2 - 1, length - (length / 2) + 1);
            }
            else
            {
                return findingMedian(A, B, startingA, startingB + length / 2, length - (length / 2));
            }
        }
    }
}

int main()
{
    vector<int> A = {2, 4, 5, 16, 20, 40, 43, 50};
    vector<int> B = {1, 3, 15, 21, 27, 28, 29, 35};

    cout << "Median: " << findingMedian(A, B, 0, 0, A.size());
}