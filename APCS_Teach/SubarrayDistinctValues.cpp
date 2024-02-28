#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

lint n, k, t,que_diff_num = 0,  counter = 0, result = 0;
queue<lint> que;
unordered_map<lint, lint> hash_map;
vector<lint> count_vec(500000, 0);


void check_and_process_queue(int check_target)
{
    if(count_vec[t] == 0) // que not have t
    {
        if(que_diff_num + 1 > k) // bomb
        {

            count_vec[que.front()]--;
            if(count_vec[que.front()] <= 0)
                que_diff_num--;

            result += que.size();
            que.pop();

            check_and_process_queue(check_target);
        }
        else
        {
            count_vec[t]++;
            que_diff_num++;
            que.emplace(t);

        }
    }
    else
    {
        count_vec[t]++;
        que.emplace(t);

    }
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> t;

        if(hash_map.find(t) == hash_map.end()) // not found
        {
            hash_map[t] = counter;
            counter++;
        }
        t = hash_map[t];

        check_and_process_queue(t);


        if(i == n - 1) // last
        {
            result += (1 + que.size()) * que.size() / 2;
        }
    }

    cout << result;
}