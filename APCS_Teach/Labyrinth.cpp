#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

class grid
{
public:
    char grid_type;
    int distance;
    bool is_visited;

    grid(char grid_type = 'x', int distance = -1)
    {
        this->grid_type = grid_type;
        this->distance = distance;
    }
};

int y, x, current_distance = 0;
char t;
pair<int, int> a_pos; // y x
pair<int, int> b_pos; // y x
vector<vector<grid>> grids((int)1000 + 10, vector<grid>((int)1000 + 10, grid()));


// [0,0] [0,1.txt]
// [1.txt,0] [1.txt,1.txt]

int dir_y[4] = {-1, 1, 0, 0};
int dir_x[4] = {0, 0, -1, 1};
void bfs(pair<int, int> pos)
{
    queue<pair<int, int>> que;

    // initial push
    que.emplace(pos);

    // initial visited, distance
    grids[pos.first][pos.second].is_visited = true;
    grids[pos.first][pos.second].distance = current_distance;

    while(!que.empty())
    {
        // front pop
        pair<int, int> current_pos = que.front();
        que.pop();

        current_distance++;

        // for i in front.connects
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> current_find_pos =
                    make_pair(current_pos.first + dir_y[i], current_pos.second + dir_x[i]);

            if((current_find_pos.first < 0 || current_find_pos.first >= y) ||
               (current_find_pos.second < 0 || current_find_pos.second >= x))
                continue;

            // if not visited
            if(grids[current_find_pos.first][current_find_pos.second].grid_type != '#' &&
               !grids[current_find_pos.first][current_find_pos.second].is_visited)
            {
                // visited = true, distance set
                grids[current_find_pos.first][current_find_pos.second].is_visited = true;
                grids[current_find_pos.first][current_find_pos.second].distance = current_distance;

                // push i
                que.emplace(current_find_pos);
            }
        }
    }
}

void test_out_vector()
{
    for (int iy = 0; iy < y; iy++)
    {
        for (int ix = 0; ix < x; ix++)
        {
            cout << grids[iy][ix].grid_type;
        }
        cout << endl;
    }
}

void test_out_vector_distance()
{
    for (int iy = 0; iy < y; iy++)
    {
        for (int ix = 0; ix < x; ix++)
        {
            if(grids[iy][ix].grid_type != '#')
                cout << grids[iy][ix].distance;
            else
                cout <<'#';
        }
        cout << endl;
    }
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> y >> x;
    for (int iy = 0; iy < y; iy++)
    {
        for (int ix = 0; ix < x; ix++)
        {
            cin >> t;
            grids[iy][ix].grid_type = t;

            if(t == 'A')
                a_pos = make_pair(iy, ix);
            else if(t == 'B')
                b_pos = make_pair(iy, ix);
        }
    }

    bfs(a_pos);



//    test_out_vector();
    test_out_vector_distance();
}