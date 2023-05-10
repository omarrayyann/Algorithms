#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

vector<vector<int>> mem;

int minimumEditDistance(string &a, string &b, int i, int j)
{
    if (mem.at(i).at(j) != -1)
    {
        return mem.at(i).at(j);
    }
    if (a.length() - i == 0 || b.length() - j == 0)
    {
        int answer = max(a.length() - i, b.length() - j);
        mem.at(i).at(j) = answer;
        return answer;
    }
    if (a[i] == b[j])
    {
        int answer = minimumEditDistance(a, b, i + 1, j + 1);
        mem.at(i).at(j) = answer;
        return answer;
    }
    else
    {
        int answer = min(1 + minimumEditDistance(a, b, i + 1, j + 1), 1 + minimumEditDistance(a, b, i, j + 1));
        answer = min(answer, 1 + minimumEditDistance(a, b, i + 1, j));
        mem.at(i).at(j) = answer;
        return answer;
    }
}

int minDistance(string word1, string word2)
{
    if (word1.length() > word2.length())
    {
        vectorfint > temp(word1.length() + 1, -1);
        mem.resize(word1.length() + 1, temp);
        return minimumEditDistance(word2, word1, 0, 0);
    }
    vector<int> temp(word2.length() + 1, -1);
    mem.resize(word2.length() + 1, temp);
    return minimumEditDistance(word1, word2, 0, 0);
}