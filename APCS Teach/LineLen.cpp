#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n, t1, t2;
    vector<pair<lint, lint>> lineList;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t1 >> t2;
        lineList.emplace_back(t1, t2);
    }

    sort(lineList.begin(), lineList.end());

    lint sum = 0;
    pair<lint, lint> currentLine = make_pair(0, 0);
    for(auto it : lineList)
    {
        if(it.first <= currentLine.second &&
           currentLine.second >= it.second)
        {
            currentLine = currentLine;
        }
        else if(it.first <= currentLine.second &&
                it.second > currentLine.second)
        {
            currentLine = make_pair(currentLine.first, it.second);

        }
        else
        {
            sum += currentLine.second - currentLine.first;
            currentLine = make_pair(it.first, it.second);
        }
    }

    sum += currentLine.second - currentLine.first;

    cout << sum;
}