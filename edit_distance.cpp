#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

unordered_map<string, int> cost;

int minimumEditDistance(string a, string b)
{

    if (cost.find(a + "-" + b) != cost.end())
    {
        return cost.find(a + "-" + b)->second;
    }

    if (a == "" || b == "")
    {
        int ans = max(b.length(), a.length());
        string key = a + "-" + b;
        cost[key] = ans;
        return ans;
    }
    else
    {
        // replacing
        int replacingCost = 0;
        if (a[a.length() - 1] == b[b.length() - 1])
        {
            replacingCost = minimumEditDistance(a.substr(0, a.length() - 1), b.substr(0, b.length() - 1));
        }
        else
        {
            replacingCost = minimumEditDistance(a.substr(0, a.length() - 1), b.substr(0, b.length() - 1)) + 1;
        }

        // inserting
        int insertingCost = 0;
        insertingCost = minimumEditDistance(a, b.substr(0, b.length() - 1)) + 1;

        // deleting
        int deletingCost = 0;
        deletingCost = minimumEditDistance(a.substr(0, a.length() - 1), b) + 1;

        int ans = min(replacingCost, deletingCost);
        ans = min(ans, insertingCost);

        string key = a + "-" + b;
        cost[key] = ans;
        return ans;
    }
}

int main()
{

    string a = "SP";
    string b = "P";

    cout << "Minimum: " << minimumEditDistance(a, b) << endl;
}