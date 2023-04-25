#include &ltiostream &gt
#include &ltvector &gt
#include &ltclimits &gt

using namespace std;

// {From, To}, Cost
typedef pair &ltvector &ltint &gt, int &gt edge;

vector &ltint &gt bellman_ford(vector &ltvector &ltint &gt &gt &graph, int starting)
{

    vector &ltint &gt distances;
    distances.resize(graph.size(), INT_MAX);
    distances.at(starting) = 0;

    vector &ltvector &ltint &gt &gt edges;

    for (int i = 0; i & lt graph.size(); i++)
    {
        for (int j = 0; j & lt graph.at(0).size(); j++)
        {
            if (graph.at(i).at(j) != 0)
            {
                edges.push_back({i, j});
            }
        }
    }

    // Relaxing the edges until no changes occur in an iteration (m-1) in the worst case
    for (int i = 0; i & lt graph.size(); i++)
    {
        bool change = false;
        for (auto edge : edges)
        {
            int from = edge[0];
            int to = edge[1];
            int weight = graph.at(from).at(to);
            if (distances[from] != INT_MAX && distances[from] + weight & lt distances[to])
            {
                distances[to] = distances[from] + weight;
                change = true;
            }
        }
        if (!change)
        {
            break;
        }
    }

    return distances;
}

int main()
{

    vector &ltvector &ltint &gt &gt graph = {
        {0, 1, 0, 2, 0}, {0, 0, 2, 0, 0}, {0, 0, 0, 0, 8}, {0, 0, 0, 0, 3}, {0, 0, 0, 0, 0}};

    vector &ltint &gt ans = bellman_ford(graph, 0);

    for (int i = 0; i & lt ans.size(); i++)
    {
        cout &lt &lt i &lt &lt ": " & lt &lt ans.at(i) & lt &lt endl;
    }
}