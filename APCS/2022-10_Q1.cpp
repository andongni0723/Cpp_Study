#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t1, t2;
    vector<pair<int, int>> vec;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t1 >> t2;
        vec.emplace_back(t1, t2);
    }

    pair<int, int> firstPair;
    int distance = 0;
    int maxDistance = 0;
    int minDistance = 100000;

    for (int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            firstPair = vec[i];
        }
        else
        {
            distance = abs(firstPair.first - vec[i].first) + abs(firstPair.second - vec[i].second);
            maxDistance = distance > maxDistance ? distance : maxDistance;
            minDistance = distance < minDistance ? distance : minDistance;
            firstPair = vec[i];
        }

    }

    cout << maxDistance << " " << minDistance;

}