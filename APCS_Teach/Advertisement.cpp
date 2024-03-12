#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

class board
{
public:

    //    [0] [1.txt]
    //-1.txt   1.txt   2

    lint height;
    lint left;
    lint right;

    lint area()
    {
        return (right - 1 - left) * height;
    }

    board(lint height, lint left = -1, lint right = -1)
    {
        this->height = height;
        this->left = left;
        this->right = right;
    }
};

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n, t;
    cin >> n;


    vector<board> vec;
    stack<pair<lint, lint>> sta; // num , index
//    stack<pair<lint, lint>> sta1;

    sta.emplace(0, 0);

    for (lint i = 0; i < n; i++)
    {
        cin >> t;
        vec.emplace_back(board(t));
    }

    for (lint i = 0; i < n; i++)
    {
        for (lint j = 1; j <= i + 1; j++)
        {
            if(sta.top().first >= vec[i].height)
            {
                vec[sta.top().second - 1].right = i + 1;
                sta.pop();
            }
            else
            {
                vec[i].left = sta.top().second;
                sta.emplace(vec[i].height, i+1);
                break;
            }
        }
    }

    while(sta.size() > 1)
    {
        vec[sta.top().second - 1].right = n + 1;
        sta.pop();
    }


    lint max_area = 0;
    for (int i = 0; i < n; i++)
    {
        max_area = vec[i].area() > max_area ? vec[i].area() : max_area;

    }

    cout << max_area;
}