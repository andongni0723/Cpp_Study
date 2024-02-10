#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

lint t1, t2;
pair<lint, lint> f_result;

pair<lint, lint> f(lint b, lint c)
{
    vector<lint> vec;
    for (int i = 1; i <= c/2; i++)
    {
        if(c % i == 0)
        {
            vec.emplace_back(i);
        }
    }
    vec.emplace_back(c);

    for (lint i = 0; i < vec.size() / 2; i++)
    {
        if(vec[i] + vec[vec.size() - (i + 1)] == b)
        {
            return make_pair(vec[i], vec[vec.size() - (i + 1)]);
        }
    }
    return make_pair(-1, -1);
}
int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t1 >> t2;
    f_result = f(t1, t2);

    for (lint i = f_result.first; i <= f_result.second; i++)
    {
        cout << i << " ";
    }
}