#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n, t1, t2;
    vector<pair<lint, lint>> vec;
    map<lint, string> firstAnsMap;
    map<lint, string> secondAnsMap;
    cin >> n;
    for (lint i = 0; i < n; i++)
    {
        cin >> t1 >> t2;
        vec.emplace_back(t1, t2);
    }

    bool isFind = false;
    sort(vec.begin(), vec.end());
    for (lint i = 0; i < n; i++)
    {
        for (lint j = i+1; j < n; j++)
        {
            if(vec[j].second <= vec[i].second)
            {
                //cout << "1.txt" << " ";
                firstAnsMap[vec[i].first] = '1';
                isFind = true;
                break;
            }
        }

        if(!isFind)
            firstAnsMap[vec[i].first] = '0';
            //cout << "0" << " ";

        isFind = false;
    }

    cout << endl;
    isFind = false;
    for (lint i = n-1; i > -1; i--)
    {
        for (lint j = i-1; j > -1; j--)
        {
            if(vec[j].second >= vec[i].second)
            {
                //cout << "1.txt" << " ";
                secondAnsMap[vec[i].first] = '1';
                isFind = true;
                break;
            }
        }

        if(!isFind)
            secondAnsMap[vec[i].first] = '0';
            //cout << "0" << " ";

        isFind = false;
    }


    for (auto it : vec)
    {
        cout << firstAnsMap[it.first] << " ";
    }

    cout << endl;

    for (auto it : vec)
    {
        cout << secondAnsMap[it.first] << " ";
    }

}