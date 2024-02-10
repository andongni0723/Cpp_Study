#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

lint sumDistance = 0;
lint currentPos = 0;
lint targetPos;
//lint repeatAddIndex = 0;
string inputS;
char readC;
string readNum;
bool isFirstRead = true;

pair<lint, lint> T(lint i) // indexAdd, addDistance;
{
    lint addDistance = 0;
    readNum = {inputS[i+1], inputS[i+2]};
    targetPos = stoi(readNum);
    if(isFirstRead)
    {
        currentPos = targetPos;
        addDistance = 0;
    }
    else
    {
        addDistance = abs(targetPos - currentPos);
        currentPos = targetPos;
    }
    isFirstRead = false;
    //i += 3;

    return make_pair(i + 3, addDistance);
}

pair<lint, lint> L(lint i) // indexAdd, addDistance
{
    lint repeatTime;
    pair<lint, lint> result;
    pair<lint, lint> inL;
    bool isLoop = true;

    // Set repeatTime
    readC =  inputS[i+1];
    readNum = {readC};
    repeatTime = stoi(readNum);

    while(isLoop)
    {
        readC = inputS[i + result.first];

        switch (readC)
        {
            case 'T':
                T(i);
                result.first += 3;
                break;
            case 'L':
                 inL =  L(i + result.first);
                 result.first += inL.first;
                 result.second += inL.second;
                break;
            case 'E':
                result.second *= repeatTime;
                result.first++;
                isLoop = false;
                break;
        }
    }

    return result;
}
int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);


    pair<lint, lint> get;
    cin >> inputS;

    for (lint i = 0; i < inputS.size();)
    {
        readC = inputS[i];
        switch (readC)
        {
            case 'T':
                get = T(i);

                i += get.first;
                sumDistance += get.second;
                break;
            case 'L':
                get = L(i);
                i += get.first;
                sumDistance += get.second;
                break;
        }

    }
    cout << sumDistance;
}