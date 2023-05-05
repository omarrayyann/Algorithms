#include <iostream>
using namespace std;

int **mem;

int p(int sum, int i)
{
    if (sum == 0)
    {
        return 1;
    }
    if (sum < 0 || i <= 0)
    {
        return 0;
    }
    if (mem[sum][i] != -1)
    {
        return mem[sum][i];
    }
    int answer = p(sum, i - 1) + p(sum - i, i);
    mem[sum][i] = answer;
    return answer;
}

int main()
{
    int n = 4;
    mem = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        mem[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            mem[i][j] = -1;
        }
    }
    cout << p(n, n - 1) << endl;
}
