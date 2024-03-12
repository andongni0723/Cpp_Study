#include <bits/stdc++.h>
using namespace std;
using lint = long long int;


int n, newX, newY, dir = 0;
//  3
//2   0
//  1.txt

int leftCount = 0, rightCount = 0, turnBackCount = 0;
pair<int, int> currentPos = make_pair(0, 0);

void CheckChangeDir(int absDir)
{
    switch (absDir)
    {
        case 0:
            switch (dir)
            {
                case 1:
                    leftCount++;
                    break;
                case 2:
                    turnBackCount++;
                    break;
                case 3:
                    rightCount++;
                    break;
            }
            dir = 0;
            break;

        case 1:
            switch (dir)
            {
                case 0:
                    rightCount++;
                    break;
                case 2:
                    leftCount++;
                    break;
                case 3:
                    turnBackCount++;
                    break;
            }
            dir = 1;
            break;
        case 2:
            switch (dir)
            {
                case 0:
                    turnBackCount++;
                    break;
                case 1:
                    rightCount++;
                    break;
                case 3:
                    leftCount++;
                    break;
            }
            dir = 2;
            break;
        case 3:
            switch (dir)
            {
                case 0:
                    leftCount++;
                    break;
                case 1:
                    turnBackCount++;
                    break;
                case 2 :
                    rightCount++;
                    break;
            }
            dir = 3;
            break;
    }
}

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n;


    for (int i = 0; i < n; i++)
    {
        cin >> newX >> newY;

        if(newX - currentPos.first > 0) // right
        {
            CheckChangeDir(0);
        }
        else if(newX - currentPos.first < 0) // left
        {
            CheckChangeDir(2);
        }
        else if(newY - currentPos.second > 0) // up
        {
            CheckChangeDir(3);
        }
        else if(newY - currentPos.second < 0) // down
        {
            CheckChangeDir(1);
        }
        else
        {
            cout << "Code Problem";
        }

        currentPos = make_pair(newX, newY);
    }

    cout << leftCount << " " << rightCount << " " << turnBackCount;
}



