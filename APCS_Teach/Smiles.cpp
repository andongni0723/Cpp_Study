#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

lint n, t;
vector<lint> vec;
vector<lint> sum_vec;
lint dp[1010][1010] = {0};

lint res;
lint min_res = -1;

lint cost(int i , int j)
{
    if(i == 0)
        return sum_vec[j];
    else
        return sum_vec[j] - sum_vec[i-1];
}

lint f(int i, int j)
{
    if(i == j) return 0;

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    else
    {
        for (int k = i; k < j; k++)
        {
            res = f(i, k) + f(k+1, j);
            cout << res << " ";
            min_res = res < min_res || min_res == -1 ? res : min_res;
        }cout << endl;

        dp[i][j] = min_res + cost(i, j);
//        cout << i << ", "  << j << endl;
        return dp[i][j];
    }
}



int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        vec.emplace_back(t);
    }

    lint c_sum = 0;
    for (int i = 0; i < n; i++)
    {
        c_sum += vec[i];
        sum_vec.emplace_back(c_sum);
    }

    for(auto it : sum_vec)
    {
        cout << it << " ";
    }cout << endl;

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << f(0, (int)n-1);

    
}