#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n, t, cost,minCost = 0, sum = 0;
    cin >> n;
    vector<lint> nums;
    vector<lint> previousSum;
    for (lint i = 0; i < n; i++)
    {
       cin >> t;
       nums.push_back(t);
    }

    sort(nums.begin(), nums.end());

    for (auto it : nums)
    {
        sum += it;
        previousSum.push_back(sum);
    }
    //cout << "a";

    for (lint i = 0; i < n; i++)
    {
        cost = 0;

        // before i
        if(i != 0)
        {
            cost += nums[i] * (i) - previousSum[i - 1];
        }

        // after i
        if(i != n-1)
        {
            cost += (previousSum[n-1] - previousSum[i]) - nums[i] * (n - i - 1);
        }

            minCost = cost < minCost || i == 0 ? cost : minCost;
        //cout << i << " " << cost << endl;
    }

    cout << minCost;
}