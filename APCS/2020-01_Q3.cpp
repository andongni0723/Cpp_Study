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

lint n, right_boundary, t, result = 0, highestTree = 0;
vector<Tree> vec;
stack<Tree> sta; // left
queue<Tree> que; // right



bool chopC(Tree t)
{
    Tree rightTree = que.front();
    Tree leftTree = sta.top();
    return t.pos + t.len <= rightTree.pos ||
           t.pos - t.len >= leftTree.pos;
}


int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> right_boundary;

    vec.emplace_back(Tree(0, 0, 0, true));
    sta.push(Tree(0, 0, 0, true));

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

    for (int i = 1; i <= n; i++)
    {
        que.push(vec[i]);
    }

    vec.emplace_back(Tree(right_boundary, 0, n + 1, true));
    que.push(Tree(right_boundary, 0, n + 1, true));



    for (lint i = 1; i <= n; i++)
    {
       Tree currentTree = que.front(); que.pop();
       if(chopC(currentTree))
       {
           result++;
           highestTree = max(highestTree, currentTree.len);

           // check before tree which can't chop
           currentTree = sta.top();
           if(currentTree.is_boundary) continue;

           sta.pop();
           while(true)
           {
               if(chopC(currentTree))
               {
                   result++;
                   highestTree = max(highestTree, currentTree.len);

                   currentTree = sta.top();
                   if(currentTree.is_boundary) break;
                   sta.pop();
               }
               else
               {
                   sta.push(currentTree);
                   break;
               }
           }

       }
       else
       {
           sta.push(currentTree);
       }
    }

    cout << result << endl << highestTree;
}