#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, t, t1, t2, t3;
    vector<int> vec;
    cin >> n >> m;


    for (int i = 0; i < n; i++)
    {
        cin >> t;
        vec.emplace_back(t);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> t;
        switch(t)
        {
            case 1:
                cin >> t1 >> t2 >> t3;
                if (t3 == 0)
                {
                    sort(vec.begin() + t1 - 1, vec.begin() + t2,greater<int>());
                }
                else
                {
                    sort(vec.begin() + t1 - 1, vec.begin() + t2, less<int>());
                }
                cout << "done!" << endl;
                break;

            case 2:
                cin >> t1 >> t2;
                cout << vec[max_element(vec.begin() + t1, vec.begin() + t2+1) - vec.begin()] << endl;
                break;

            case 3:
                for(auto it : vec)
                {
                    cout << it << " ";
                }
                cout << endl;
                break;
        }
    }
}