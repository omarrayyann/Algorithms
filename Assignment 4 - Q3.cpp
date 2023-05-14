#include <iostream>
#include <vector>
using namespace std;

int *mem;

int max_profit(vector<int> low_strees_jobs, vector<int> high_stress_jobs, int i)
{
    if (i < 0)
    {
        return 0;
    }
    if (mem[i] != -1)
    {
        return mem[i];
    }
    int ans = max(low_strees_jobs.at(i) + max_profit(low_strees_jobs, high_stress_jobs, i - 1), high_stress_jobs.at(i) + max_profit(low_strees_jobs, high_stress_jobs, i - 2));
    mem[i] = ans;
    return ans;
}

int main()
{
    vector<int> low_stress_jobs = {10, 1, 10, 10};
    vector<int> high_stress_jobs = {5, 50, 5, 1};

    mem = new int[high_stress_jobs.size()];
    for (int i = 0; i < high_stress_jobs.size(); i++)
    {
        mem[i] = -1;
    }

    cout << max_profit(low_stress_jobs, high_stress_jobs, low_stress_jobs.size() - 1) << endl;

    cout << endl;
}
