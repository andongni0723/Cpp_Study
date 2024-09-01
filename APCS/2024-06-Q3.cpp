#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

string k, s;
vector<string> combine;
unordered_set<string> split;
int l;

void f(string current, string k)
{
    if(current.size() >= l)
    {
        combine.emplace_back(current);
        return;
    }

    for(auto c : k)
    {
        f(current + c, k);
    }
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k >> l >> s;
    f("", k);

    for (int i = 0; i <= s.size() - l; i++)
    {
        split.insert(s.substr(i, l));
    }
    for(auto it : combine)
    {
        if(split.find(it) == split.end())
        {
            cout << it;
            break;
        }
    }
}
