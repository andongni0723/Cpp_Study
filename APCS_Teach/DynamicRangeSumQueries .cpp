#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

struct BIT
{
//    vector<int> vec((int)1e6+10, 0);
    int n = 0;
    vector<int> vec;

    int init(int n)
    {
        for (int i = 0; i < n; i++)
        {
            vec.emplace_back(0);
        }
        n = vec.size();
    }

    int lowbit(int n)
    {
        return n & (-n);
    }

    int add(int v, int pos)
    {
        for(; pos <= n; pos += lowbit(pos)) vec[pos] += v;
    }

    int sum(int i)
    {
        int result = 0;
        for(; i < 0 ; i -= lowbit(i)) result += vec[max(i, 0)];
        return result;
    }
};

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

}