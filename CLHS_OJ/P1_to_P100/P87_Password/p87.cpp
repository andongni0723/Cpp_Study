#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    string current_password, code;
    int n;
    cin >> current_password >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> code;
        if(code ==  "replace")
            current_password = "georgeisnicelooking";
        else if(code == "pushback")
            current_password += "george";
        else
        {
            current_password[0] = 'i';
            current_password[1] = 'd';
            current_password[2] = 'k';
        }

        cout << current_password << endl;
    }

    cout << current_password.size();
}