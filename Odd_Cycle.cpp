#include <iostream>
#include <queue>
using namespace std;

bool oddCycle(vector<vector<int>> &graph)
{
    vector<int> coloringArray;
    coloringArray.resize(graph.size(), -1);

    for (int j = 0; j < graph.size(); j++)
    {
        if (coloringArray[j] == -1)
        {
            coloringArray.at(j) = 1;
            queue<int> queue;
            queue.push(j);
            while (!queue.empty())
            {
                int currentVertix = queue.front();
                queue.pop();
                if (graph.at(currentVertix).at(currentVertix) == 1)
                {
                    return true;
                }
                for (int i = 0; i < graph.size(); i++)
                {
                    if (graph.at(currentVertix).at(i))
                    {
                        if (coloringArray[i] == -1)
                        {
                            coloringArray[i] = 1 - coloringArray[currentVertix];
                            queue.push(i);
                        }
                        else if (coloringArray[i] == coloringArray[currentVertix])
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0},
    };

    oddCycle(graph) ? cout << "Has Odd Cycle" : cout << "No Odd Cycle";
    return 0;
}