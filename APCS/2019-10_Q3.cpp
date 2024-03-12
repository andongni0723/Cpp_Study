#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";


//2 ≤ n ≤ 10^6
//0 ≤ P ≤ n-1.txt
//1.txt ≤ L,R ≤ n/2
int n, p, l, r, t;
vector<int> vec;
vector<bool> visited((int)1e6 + 10);
vector<int> distances((int)1e6 + 10, -1);

void bfs(int i)
{
    queue<int> que;
    int target_point = 0;
    int current_point = 0;
    int current_distance = 0;
    que.emplace(i);
    visited[i] = true;
    distances[target_point] = current_distance;


    while(!que.empty())
    {
        current_point = vec[que.front()];
        que.pop();
        current_distance++;

        for (int j = 0; j < 2; j++)
        {
            if(j == 0) // L
            {
                if(current_point - l < 0) continue;
                if(vec[current_point - l] < 0 || vec[current_point - l] >= n) continue;
                target_point = current_point - l;
            }
            else // R
            {
                if(current_point + r >= n) continue;
                if(vec[current_point + r] < 0 || vec[current_point + r] >= n) continue;
                target_point = current_point + r;
            }

            if(!visited[target_point])
            {
                que.emplace(target_point);
                visited[target_point] = true;
                distances[target_point] = current_distance;
            }
            //que.push j
            //j is visited
        }
    }
}

void out_distance()
{
    for (int i = 0; i < n; i++)
    {
        cout << distances[i] << " ";
    }
}
int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> p >> l >> r;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        vec.emplace_back(t);
    }

    bfs(0);

//    out_distance();
    cout << endl;
    cout << distances[p];
}