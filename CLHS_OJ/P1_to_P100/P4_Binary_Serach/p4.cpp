#include <bits/stdc++.h>
#include <cstdio>
#include <unordered_set>
using namespace std;
using lint = long long int;
#define endl "\n"

int main()
{
    int n, q;
    vector<int> vec;
    scanf("%d %d", &n, &q);

    int t;
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d", &t);
        vec.emplace_back(t);
    }

    for(int i = 0 ; i < q ; i++)
    {
        scanf("%d", &t);

        //search
        int L = 0, R = n;
        bool isFind = false;
        while(L+1 < R)
        {
            // cout << "L:" << L << " R: " << R << endl;
            int mid = (L+R) / 2;
            if(vec[mid] == t || vec[0] == t)
            {
                printf("%s \n", "Yes");
                isFind = true;
                break;
            }
            else if(vec[mid] < t)
                L = mid;
            else
                R = mid;
        }
        if(isFind) continue;
        printf("%s \n", (L == t ? "Yes" : "No" ));
    }
}
