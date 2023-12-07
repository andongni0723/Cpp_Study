#include <bits/stdc++.h>

using namespace std;


int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, b, vec_sum = 0;
    vector<int> vec;

    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        vec_sum += t;
        vec.push_back(t);
    }

    for (int i = 0; i < q; ++i) {
        cin >> b;

        if(b < vec_sum)
        {
            vec.push_back(b);
            vec_sum += b;
        }
    }

    for(auto it : vec)
    {
        cout << it << endl;
    }

}