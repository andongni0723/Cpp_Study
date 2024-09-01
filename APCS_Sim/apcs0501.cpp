#include <bits/stdc++.h>
using namespace std;
#define lint long long

int main()
{
    vector<char> vec;

    lint result = 0;
    string s;
    cin >> s;

    for(auto it : s)
    {
        if(it == '0')
            result += 6;
        else if(it == '1')
            result += 2;
        else if(it == '2')
            result += 5;
        else if(it == '3')
            result += 5;
        else if(it == '4')
            result += 4;
        else if(it == '5')
            result += 5;
        else if(it == '6')
            result += 6;
        else if(it == '7')
            result += 4;
        else if(it == '8')
            result += 7;
        else if(it == '9')
            result += 6;
    }

    cout << result;

}

