#include <bits/stdc++.h>
using namespace std;
using lint = long long;

bool isFirst = true;
lint currentPos = 0;
queue<char> q;

lint T()
{
    lint inSum = 0;
    char c1 = q.front();
    q.pop();
    char c2 = q.front();
    q.pop();

    string s = {c1, c2};
    lint targetPos = stoi(s);

    if(isFirst)
    {
        currentPos = targetPos;
        isFirst = false;
    }
    else
    {
        inSum = abs(targetPos - currentPos);
        currentPos = targetPos;
    }


    return inSum;
}

lint L()
{
    lint inSum = 0;
    char c;
    bool isLoop = true;

    // Set repeat time
    c = q.front();
    q.pop();

    string s = {c};
    int repeatTime = stoi(s);
    while(isLoop)
    {
        c = q.front();
        q.pop();
        switch(c)
        {
            case 'T':
                inSum += T();
                break;
            case 'L':
                inSum += L();
                break;
            case 'E':
                inSum += repeatTime * L(); // TODO:
                isLoop = false;
                break;
        }
    }
    return inSum;
}


int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    string n;

    lint sum = 0;
    cin >> n;
    for (lint i = 0; i < n.size(); i++)
    {
        q.push(n[i]);
    }

    char c;
    while(!q.empty())
    {
        c = q.front();
        q.pop();
        switch(c)
        {
            case 'T':
                sum += T();
                break;
            case 'L':
                sum += L();
                break;
        }
    }

    cout << sum;
}
