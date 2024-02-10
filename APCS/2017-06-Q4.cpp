#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

lint n, k, p;
vector<lint> vec;

bool cmp(vector<lint> v, lint r)
{
    lint start = v[0];
    lint distance = start - 1;

    //cout << r << ": " << endl;
    for (lint i = 0; i < k; i++)
    {
        auto index = upper_bound(v.begin(), v.end(), distance) - v.begin();
        if (index == v.size()) return true;

//        cout << distance << " "<<  index << endl;

        distance = v[index];

        distance += r; // 增加一個直徑

    }

    return distance >= v[n-1];
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> k;
    for (lint i = 0; i < n; i++)
    {
        cin >> p;
        vec.emplace_back(p);
    }

    sort(vec.begin(), vec.end());

//    for(auto it : vec)
//    {
//        cout << it << " ";
//    }cout << endl;

    lint L = 0, R = 2 * vec[n-1];
    while(L <= R)
    {
        lint mid = (L + R) >> 1;
        if(cmp(vec, mid))
        {
            R = mid - 1;
        }
        else
        {
            L = mid + 1;
        }
    }

    cout << L;
}