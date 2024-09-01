#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

vector<vector<int>> vec(110, vector<int>(110));
vector<vector<bool>> visited(110, vector<bool>(110, false));
bool isEnd = false;
pair<int, int> currentPos;

lint diffCount = 0;


// 0,0 0,1 0,2
// 1,0 1,1 1,2
int y[] = {1, 0, -1, 0};
int x[] = {0, 1, 0, -1};
int n, m;


void walk(pair<int, int> inPos)
{
    int minTarget = (int)1e9; // Warning
    pair<int, int> resultPos;
    visited[inPos.first][inPos.second] = true;
    diffCount += vec[inPos.first][inPos.second];

    for (int i = 0; i < 4; i++)
    {
        int targetY = inPos.first + y[i];
        int targetX = inPos.second + x[i];
        if(targetY < 0 || targetY >= n ||
            targetX < 0 || targetX >= m)
            continue;

        if(visited[targetY][targetX])
            continue;

        // visited[targetY][targetX] = true;
        if(vec[targetY][targetX] < minTarget)
        {
            minTarget = vec[targetY][targetX];
            resultPos = make_pair(targetY, targetX);
        }
    }

    if(minTarget == (int)1e9)
        isEnd = true;
    else
        currentPos = resultPos;


}
int main()
{
    cin >> n >> m;


    int t;
    int startMin = (int)1e9;
    for (int iy = 0; iy < n; iy++)
    {
        for (int ix = 0; ix < m; ix++)
        {
            cin >> t;
            vec[iy][ix] = t;

            if(t < startMin) // min
            {
                currentPos = make_pair(iy, ix);
                startMin = t;
            }
        }
    }

    while (!isEnd)
        walk(currentPos);

    cout << diffCount;
}
