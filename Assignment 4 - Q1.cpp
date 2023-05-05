#include <iostream>
#include <stack>
using namespace std;

int **mem;

int p(int sum, int i, stack<int> current)
{
    if (mem[sum][i] != -1)
    {
        return mem[sum][i];
    }
    if (sum == 0)
    {
        return 1;
    }
    if (sum < 0 || i <= 0)
    {
        return 0;
    }
    int answer = p(sum, i - 1, current) + p(sum - i, i, current);
    mem[sum][i] = answer;
    return answer;
}

int main()
{
    int n = 3;
    mem = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        mem[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            mem[i][j] = -1;
        }
    }
    stack<int> current;
    cout << p(n, n - 1) << endl;
}
