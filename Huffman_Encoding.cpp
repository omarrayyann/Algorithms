#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

unordered_map<char, string> encodingMap;

class Node
{
public:
    string key;
    int value;
    Node *parent;
    Node *left;
    Node *right;
    Node(string key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

typedef pair<Node *, int> pd;

struct encoding
{
    constexpr bool operator()(
        pair<Node *, int> const &a,
        pair<Node *, int> const &b)
        const noexcept
    {
        return a.second > b.second;
    }
};

void labeling(Node *root, string current)
{
    if (root == NULL)
    {
        return;
    }
    else if (root->key.length() == 1)
    {
        encodingMap[root->key[0]] = current;
    }
    labeling(root->left, current + "0");
    labeling(root->right, current + "1");
}

vector<string> huffman_encoding(vector<char> values, vector<int> frequencies)
{
    priority_queue<pd, vector<pd>, encoding> PQ;

    for (int i = 0; i < values.size(); i++)
    {
        Node *node = new Node(string(1, values.at(i)), frequencies.at(i));
        PQ.push(make_pair(node, frequencies.at(i)));
    }

    while (PQ.size() > 1)
    {
        Node *a = PQ.top().first;
        PQ.pop();
        Node *b = PQ.top().first;
        PQ.pop();
        string newKey = a->key + b->key;
        int newFrequency = a->value + b->value;
        Node *newNode = new Node(newKey, newFrequency);
        newNode->left = a;
        newNode->right = b;
        a->parent = newNode;
        b->parent = newNode;
        PQ.push(make_pair(newNode, newFrequency));
    }

    Node *root = PQ.top().first;

    labeling(root, "");
}

int main()
{
    vector<char> values = {'A', 'B', 'C', 'D'};
    vector<int> frequencies = {75, 2, 22, 31};
    vector<string> encoding = huffman_encoding(values, frequencies);
    for (int i = 0; i < values.size(); i++)
    {
        cout << values.at(i) << ": " << encodingMap[values.at(i)] << endl;
    }
}