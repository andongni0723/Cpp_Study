// https://zerojudge.tw/ShowProblem?problemid=m370
#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int startPos, foodCount, t;
    vector<int> foodPos;
    cin >> startPos >> foodCount;
    for (int i = 0; i < foodCount; i++)
    {
        cin >> t;
        foodPos.emplace_back(t);
    }

    sort(foodPos.begin(), foodPos.end());

    int previousFood = foodPos[0];
    int leftCount = 0, rightCount = 0;
    for(int i = 0 ; i < foodCount; i++)
    {
        if(previousFood <= startPos && foodPos[i] >= startPos)
        {
            leftCount = i;
            rightCount = foodCount - leftCount;
            if(leftCount >= rightCount)
            {
                cout << leftCount << " " << foodPos[0];
            }
            else
            {
                cout << rightCount << " " << foodPos[foodCount-1];
            }

            break;
        }
        else if(foodPos[i] >= startPos)
        {
            cout << foodCount << " " << foodPos[foodCount-1];
            break;
        }
        else if(foodPos[i] <= startPos && i == foodCount - 1)
        {
            cout << foodCount << " " << foodPos[0];
        }
        previousFood = foodPos[i];
    }
}