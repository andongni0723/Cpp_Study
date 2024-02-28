#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

struct vector_hasher
{
    auto operator()(lint const& data) const
    {
        lint ret = 20231127;
        ret ^= data + 0x9e3779b9;
        return ret;
    }
};

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n, arrivalTime, leavingTime, maxLeavingTime = 0, currentCustomer = 0, maxCustomer = 0;
    unordered_map<lint, lint, vector_hasher> customers;       // <arrivalTime, leavingTime>
    unordered_map<lint, lint, vector_hasher> leavingTimesMap; // <leavingTime, leaving people count in same time>
    cin >> n;

    // Put input data to customers map
    for (lint i = 0; i < n; i++)
    {
        cin >> arrivalTime >> leavingTime;
        maxLeavingTime = leavingTime > maxLeavingTime ? leavingTime : maxLeavingTime;
        customers[arrivalTime] = leavingTime;
    }

    for (lint i = 0; i < maxLeavingTime; i++)
    {
        if(customers.find(i) != customers.end()) // Some people have arrival now
        {
            leavingTimesMap[customers[i]] += 1; // leaving customer count in same time
            currentCustomer++;
        }

        if(leavingTimesMap.find(i) != customers.end()) // Some people have leaving now
        {
            currentCustomer -= leavingTimesMap[i]; // Get leaving customer count in same time
        }

        maxCustomer = currentCustomer > maxCustomer ? currentCustomer : maxCustomer;
    }

    cout << maxCustomer;
}