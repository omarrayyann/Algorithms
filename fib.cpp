#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

vector<int> mem;

int fib(int n)
{
    if (mem.at(n) != -1)
    {
        return mem[n];
    }
    if (n <= 2)
    {
        return 1;
    }
    else
    {
        int answer = fib(n - 1) + fib(n - 2);
        mem[n] = answer;
        return answer;
    }
}
int main()
{
    int n = 5;
    mem.resize(n + 1, -1);
    cout << fib(n) << endl;
}