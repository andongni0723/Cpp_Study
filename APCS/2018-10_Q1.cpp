#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string t1;
    vector<pair<int, string>> vec;
    vector<string> string_vec;
    set<char> char_set;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> t1;
        char_set.clear();

        for(auto c : t1)
        {
            char_set.insert(c);
        }

        vec.emplace_back(char_set.size(), t1);
    }

    sort(vec.begin(), vec.end());

    int min;
    for(int i = 0; i < n; i++)
    {
        if( i == 0 ) min = vec[0].first;

        if(vec[i].first == min)
        {
            string_vec.emplace_back(vec[i].second);
        }
        else
        {
            break;
        }
    }

    sort(string_vec.begin(), string_vec.end());

    cout << string_vec[0];

    cout << endl;
}