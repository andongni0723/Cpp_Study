#include <bits/stdc++.h>
#include <unordered_set>
#include <vector>
using namespace std;
using lint = long long int;
#define endl "\n"

lint stringTolint(string s)
{
    int result = 0;
    for(auto c:s)
    {
        result += c;
    }

    return result;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);


    int m, n;
    bool isFind = false;
    // vector<string> find;
    // unordered_set<string> unSet;
    vector<string> find;
    map<lint, string> idToStringMap;
    unordered_set<lint> unSet;
    cin >> m >> n;

    string t; lint id;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> t;
        id = stringTolint(t);
        idToStringMap[id] = t;
        unSet.insert(id);
    }

    for(int i = 0 ; i < m ; i++)
    {
        cin >> t;
        id = stringTolint(t);
        if(unSet.find(id) != unSet.end())
        {
            find.emplace_back(idToStringMap[id]);
            isFind = true;
        }
    }

    cout << (isFind ? "YES" : "NO") << endl;

    for(auto it : find)
    {
        cout << it << endl;
    }
}
