#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string t;
    vector<string> vec;
    //vector<string> newVec;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        vec.emplace_back(t);
    }

    sort(vec.begin(), vec.end(), [](auto const& s2, auto const& s1)
    {
        lint s1Sum = 0, s1XCount = 0, s2Sum = 0, s2XCount = 0;


        // Get string sum and X count
        for (char it : s1)
        {
            if(it == 'X')
                s1XCount++;
            else
                s1Sum += int(it - '0');
        }
        for(char it : s2)
        {
            if(it == 'X')
                s2XCount++;
            else
                s2Sum += int(it - '0');
        }

       // Compare
        return s2Sum * s1XCount < s1Sum * s2XCount;
    });

    lint currentScore = 0;
    lint currentXCount = 0;
    for (string s : vec)
    {
        for(char c : s)
        {
            if(c == 'X')
            {
                currentXCount++;
            }
            else
            {
                int num = int(c - '0');
                currentScore += num * currentXCount;
            }
        }
    }

    cout << currentScore;
}