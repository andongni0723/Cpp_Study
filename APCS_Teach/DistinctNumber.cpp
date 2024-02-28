#include <bits/stdc++.h>
using namespace std;

struct vector_hasher
{
    auto operator()(long long int const& data) const
    {
        auto ret = 20231125;
        ret ^= data + 0x9e3779b9;
        return ret;
    }
};

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<long long int , vector_hasher> set;
    long long int n, t;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        set.insert(t);
    }

    cout << set.size();
}