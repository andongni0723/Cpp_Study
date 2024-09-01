#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
using lint = long long int;
#define endl "\n"

vector<int> color;
vector<string> first;
vector<int> appCount((int)3e6);

lint diffCount = 0;
lint result = 0;

// 3 7
// 1 2 3 5 4 5 4

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    string t;
    cin >> m >> n;

    // int t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        first.emplace_back(t);
    }

    // discretization
    unordered_map<string, int> dict;
    int id = 0;
    for(auto it : first)
    {
        if(dict.find(it) == dict.end()) // not found
        {
            color.emplace_back(id);
            dict[it] = id;
            id++;
        }
        else // has found
        {
            color.emplace_back(dict[it]);
        }
    }




    // main
    int L = 0, R = 0;
    for (int i = 0; i < n; i++)
    {
        appCount[color[R]]++;
        if(appCount[color[R]] == 1)
            diffCount++;

        if(diffCount == m)
            result++;

        if(R < m-1)
            R++;
        else
        {
            R++;

            appCount[color[L]]--;
            if(appCount[color[L]] == 0)
                diffCount--;
            L++;
        }
    }

    cout << result;
}