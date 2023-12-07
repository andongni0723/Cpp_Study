#include <bits/stdc++.h>
using namespace std;

const* int c;


void f(int *_p)
{
    *_p += 2;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int i = 10;
    int j = 5;

    c = 4;



    f(&i);
    f(&j);

    cout << i << " " << j;
}
