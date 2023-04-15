#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int **mem;

bool subset_sum(vector<int> values, int sum, int i)
{
    if (sum < 0 || i < 0)
    {
        return false;
    }
    else if (sum == 0)
    {
        return true;
    }
    if (mem[i][sum] == -1)
    {
        bool answer = subset_sum(values, sum - values.at(i), i - 1) || subset_sum(values, sum, i - 1);
        mem[i][sum] = answer;
        return answer;
    }
    else
    {
        return mem[i][sum];
    }
}

int main()
{
    vector<int> values = {2, 4, 5, 1, 4};
    int target = 5;
    mem = new int *[values.size() + 1];
    for (int i = 0; i < values.size() + 1; i++)
    {
        mem[i] = new int[target + 1];
        for (int j = 0; j < target + 1; j++)
        {
            mem[i][j] = -1;
        }
    }
    cout << subset_sum(values, target, values.size() - 1) << endl;
}