#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

class tile
{
public:
    char type;
    vector<int> exit; //
    //      up-0
    //left-2       right-3
    //      down-1

    void build_road()
    {
        switch (type)
        {
            case 'X':
                // let exit[] is {1, 1, 1, 1};
                exit = {1, 1, 1, 1};
                break;
            case 'I':
                exit = {1, 1, 0, 0};
                break;
            case 'H':
                exit = {0, 0, 1, 1};
                break;
            case 'L':
                exit = {1, 0, 0, 1};
                break;
            case '7':
                exit = {0, 1, 1, 0};
                break;
            case 'F':
                exit = {0, 1, 0, 1};
                break;
            case 'J':
                exit = {1, 0, 1, 0};
                break;

        }
    }
};

int n, m;
char t;
vector<vector<tile>> vec(600, vector<tile>(600, tile())); // y x
vector<vector<bool>> visited(600, vector<bool>(600, false));

// -1,-1 -1,0 -1,1
// 0,-1  0,0   0,1
// 1,-1  1,0   1,1

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

// return room size
int bfs(int y, int x)
{
    queue<pair<int, int>> que;
    que.push({y, x});
    visited[y][x] = true;

    int result = 0;
    while(!que.empty())
    {
        tile t = vec[que.front().first][que.front().second]; que.pop();

        for (int i = 0; i < 4; i++)
        {
            int cy = dy[i] + y;
            int cx = dx[i] + x;

            if (cy < 0 || cy >= n || cx < 0 || cx >= m) continue;
            if(!visited[cy][cx])
            {
                if(t.exit[i] && vec[cy][cx].exit[i])
                {
                    que.push({cy, cx});
                    visited[cy][cx] = true;
                    result++;
                }
            }
        }
    }

    return 0;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> m;
    for (int iy = 0; iy < n; iy++)
    {
        for (int ix = 0; ix < m; ix++)
        {
            cin >> vec[iy][ix].type;
            vec[iy][ix].build_road();
        }
    }

    int maxResult = 0;
    for (int iy = 0; iy < n; iy++)
        for (int ix = 0; ix < m; ix++)
            if (!visited[iy][ix])
                maxResult = max(maxResult, bfs(iy, ix));

    cout << maxResult;

}