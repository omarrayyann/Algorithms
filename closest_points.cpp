#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <cmath>
#include <float.h>
#include <algorithm>

using namespace std;

float distance(vector<float> p1, vector<float> p2)
{
    float deltaX = p1[0] - p2[0];
    float deltaY = p1[1] - p2[1];
    return sqrtf(deltaX * deltaX + deltaY * deltaY);
}

// To be used in the base case
vector<vector<float>> brute_force(vector<vector<float>> points, int from, int to)
{
    float minDistance = FLT_MAX;
    vector<vector<float>> closest_points;
    vector<float> minPoint;
    for (int i = from; i < to; i++)
    {
        for (int j = i + 1; j <= to; j++)
        {
            if (distance(points.at(i), points.at(j)) < minDistance)
            {
                minDistance = distance(points.at(i), points.at(j));
                closest_points.clear();
                closest_points = {points.at(i), points.at(j)};
            }
        }
    }

    return closest_points;
}

vector<vector<float>> closest_split_pair(vector<vector<float>> &points, float distance_from_split, int from, int to)
{

    // Sorted Points
    vector<vector<float>> xSortedPoints(points.begin() + from, points.begin() + to + 1);
    vector<vector<float>> ySortedPoints(points.begin() + from, points.begin() + to + 1);
    sort(xSortedPoints.begin(), xSortedPoints.end(),
         [](const std::vector<float> &a, const std::vector<float> &b)
         {
             return a[0] < b[0];
         });
    sort(ySortedPoints.begin(), ySortedPoints.end(),
         [](const std::vector<float> &a, const std::vector<float> &b)
         {
             return a[1] < b[1];
         });

    // The vector<float> splitting the left and right parts
    vector<float> boundary_point = xSortedPoints.at((from + to) / 2);

    // Getting the points within the bar of width "distance_from_split" from each end
    vector<vector<float>> sortedY_bar;
    for (auto edge : ySortedPoints)
    {
        if ((edge[0] <= boundary_point[0] + distance_from_split) && (edge[0] >= boundary_point[0] - distance_from_split))
        {
            sortedY_bar.push_back(edge);
        }
    }

    // We only need to compare it with the neighboring 7 points
    float closest_points_distance = FLT_MAX;
    vector<vector<float>> closest_points;
    for (int i = 0; i < sortedY_bar.size(); i++)
    {
        for (int j = i + 1; j < sortedY_bar.size(); j++)
        {
            if (distance(sortedY_bar.at(i), sortedY_bar.at(j)) < closest_points_distance)
            {
                closest_points_distance = distance(sortedY_bar.at(i), sortedY_bar.at(j));
                closest_points.clear();
                closest_points = {sortedY_bar.at(i), sortedY_bar.at(j)};
            }
        }
    }

    return closest_points;
}
vector<vector<float>> find_closest_points(vector<vector<float>> &points, int from, int to)
{

    int number_of_points = to - from + 1;

    if (number_of_points < 4)
    {
        return brute_force(points, from, to);
    }

    int middle = (from + to) / 2;

    vector<vector<float>> l_points = find_closest_points(points, from, middle);

    float l_distance = distance(l_points.at(0), l_points.at(1));
    vector<vector<float>> r_points = find_closest_points(points, middle + 1, to);

    float r_distance = distance(r_points.at(0), r_points.at(1));
    vector<vector<float>> m_points = closest_split_pair(points, min(l_distance, r_distance), from, to);
    float m_distance = distance(m_points.at(0), m_points.at(1));

    if (l_distance <= r_distance)
    {
        if (l_distance < m_distance)
        {
            return l_points;
        }
        else
        {
            return m_points;
        }
    }
    else if (r_distance < m_distance)
    {
        return r_points;
    }
    else
    {
        return m_points;
    }
}

int main()
{
    vector<vector<float>> points = {
        {-2, 60}, {-2, 0}, {1, 8}, {3, 90}, {56, 2}, {4, 99}};

    vector<vector<float>> closest_points = find_closest_points(points, 0, points.size() - 1);

    cout << "(" << closest_points.at(0)[0] << ", " << closest_points.at(0)[1] << ") and "
         << "(" << closest_points.at(1)[0] << ", " << closest_points.at(1)[1] << ")" << endl;
    cout << "Distance Apart: " << distance(closest_points.at(0), closest_points.at(1)) << endl;
}