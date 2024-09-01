#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> vec;
    unordered_set<string> hash;
    int n, result = 0;
    string t;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        vec.emplace_back(t);
        hash.insert(t);
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < vec[i].size() / 2 + 1; j++)
        {
            // find head
            string head = vec[i].substr(0, j);
            string tail = vec[i].substr(vec[i].size() - j);

            if(head != tail)
                continue;

            string middle = vec[i].substr(j,vec[i].size() - j - j);

            if(hash.find(middle) != hash.end()) // has found
            {
                result++;
            }

        }
    }

    cout << result;
}