#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

vector<vector<int>> vec(100, vector<int>(100));
int y, x, t, result = 0;

void print_vec()
{
    cout << endl;
    for (int iy = 0; iy < y; iy++)
    {
        for (int ix = 0; ix < x; ix++)
        {
           cout << vec[iy][ix] << " ";
        }
        cout << endl;
    }
}

void Check_and_Process(int y, int x, int cy, int cx)
{
    int pointer = 1;
    while(true)
    {
        if(y < 0) break;
        else if(vec[y][x] != vec[cy][cx]) break;
        else if(vec[y][x] == vec[cy][cx])
        {
            result += vec[cy][cx];
            vec[y][x] = -1;
            vec[cy][cx] = -1;
            print_vec();
            break;
        }
        pointer++;
    }
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> y >> x;
    cout << endl;
    for (int iy = 0; iy < y; iy++)
    {
        for (int ix = 0; ix < x; ix++)
        {
            cin >> t;
            vec[iy][ix] = t;
        }
    }

    // [0,0] [0,1.txt]
    // [1.txt,0] [1.txt,1.txt]
    int pointer = 1;
    for (int iy = 0; iy < y; iy++)
    {
        for (int ix = 0; ix < x; ix++)
        {
            //up
            Check_and_Process(iy-pointer, ix, iy, ix);
            //down
            Check_and_Process(iy+pointer, ix, iy, ix);
            //left
            Check_and_Process(iy, ix-pointer, iy, ix);
            //right
            Check_and_Process(iy, ix+pointer, iy, ix);
        }
    }

    cout << result;
}