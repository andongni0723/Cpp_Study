#include <bits/stdc++.h>
using namespace std;
#define lint long long;
#define endl "\n"

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> people(1e4, 0);

        for(auto log : logs)
        {
            people[log[0]]++;
            people[log[1]]--;
        }


        int max_people = 0;
        int max_year = 1950;
        int n = 0;
        for (int i = 1950; i <= 2050; ++i)
        {
            n += people[i];
            if(n > max_people)
            {
                max_people = n;
                max_year = i;
            }
        }

        return max_year;
    }
};

// 0 1 0 0 -1
// 0 1 1 1 0