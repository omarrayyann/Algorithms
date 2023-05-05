#include <iostream>
#include <stack>
using namespace std;

int p(int sum, int i, stack<int> current)
{
    if (sum == 0)
    {
        return 1;
    }
    if (sum < 0 || i <= 0)
    {
        return 0;
    }
    int ans1 = p(sum, i - 1, current);
    // int ans2 = p(sum - i, i - 1, current);
    int ans3 = p(sum - i, i, current);
    return ans1 + ans3;
}

int main()
{
    int n = 3;
    stack<int> current;
    cout << p(n, n - 1, current) << endl;
}
