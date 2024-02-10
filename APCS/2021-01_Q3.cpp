#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n, m, t, sum = 0;
    cin >> n >> m;
    vector<lint> vec;
    vector<lint> pre_sum_vec;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        sum += t;
        vec.emplace_back(t);
        pre_sum_vec.emplace_back(sum);
    }


    lint pos = 0, c_pre_sum = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> t;
        pos++;

        auto index = lower_bound(pre_sum_vec.begin(), pre_sum_vec.end(), t + c_pre_sum) - pre_sum_vec.begin();

        if(index == n) // 走到底了
        {
            auto sec_index = lower_bound(pre_sum_vec.begin(), pre_sum_vec.begin() + pos + 1, t - (pre_sum_vec[index - 1] - c_pre_sum)) - pre_sum_vec.begin();
            pos = sec_index;
        }
        else
        {
            pos = index;
            c_pre_sum = pre_sum_vec[index];
        }
//        cout << pos << " ";
    }
//    cout << endl;


//    cout << "pre-sum: ";
//    for(auto it : pre_sum_vec)
//    {
//        cout<< it << " ";
//    }cout << endl;

    cout << (pos + 1) % n;
}