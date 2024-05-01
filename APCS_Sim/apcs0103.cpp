#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";


vector<vector<int>> tree((int)1e6, vector<int>());
vector<int> parent((int)1e6, -1); // index = node-number, value = node's parent
vector<int> node_index((int)1e6, -1); // index = node-number, value = node's index in its parent's vector

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // input
    int k, t;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;

        for (int j = 0; j < k; j++)
        {
            cin >> t;
            tree[i].emplace_back(t);
            parent[t] = i;
            node_index[t] = tree[i].size() - 1;
        }
    }

    // check root node
    int current_node = 1;
    for (int i = 1; i <= n; i++)
    {
        if(parent[i] == -1)
        {
            current_node = i;
            break;
        }
    }

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        char code = s[i];

        if(code == 'P')
        {
            if(parent[current_node] != -1) // check has parent
            {
                current_node = parent[current_node];
            }
            else
                break;
        }
        else if(code == 'C')
        {
            i++;
            int num = s[i] - '0';
            if(tree[current_node].size() > 0) // check final index > 0
            {
                current_node = tree[current_node][num-1];
            }
            else
                break;
        }
        else if(code == 'R')
        {
            if(node_index[current_node] + 1 < tree[parent[current_node]].size()) // check out of range
            {
                current_node = tree[parent[current_node]][node_index[current_node] + 1];
            }
            else
                break;
        }
        else if(code == 'L')
        {
            if(node_index[current_node] - 1 > -1) // check final index > 0
            {
                current_node = tree[parent[current_node]][node_index[current_node] - 1];
            }
            else
                break;
        }
    }

    cout << current_node;
}