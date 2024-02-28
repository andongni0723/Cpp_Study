#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

class Tree
{
public:
    lint pos;
    lint len;
    lint index;
    bool is_boundary;

    Tree(lint pos, lint len, lint index, int is_boundary = false)
    {
        this->pos = pos;
        this->len = len;
        this->index = index;
        this->is_boundary = is_boundary;
    }
};

lint n, right_boundary, t;
vector<Tree> vec;
stack<Tree> sta;
stack<Tree> sta1;

bool Chop(lint i)
{
    return vec[i].pos + vec[i].len <= vec[i+1].pos ||
           vec[i].pos - vec[i].len >= 0;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> right_boundary;

    vec.emplace_back(Tree(0, 0, 0, true));

    for (lint i = 1; i <= n; i++)
    {
        cin >> t;
        vec.emplace_back(Tree(t, -1, i));
    }
    for (lint i = 1; i <= n; i++)
    {
        cin >> t;
        vec[i].len = t;
    }

    vec.emplace_back(Tree(right_boundary, 0, n + 1, true));



    for (lint i = 1; i <= n; i++)
    {
        if(Chop(i))
        {

        }
    }
}