#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    string lost_string, t;
    vector<int>lost_string_vec;
    vector<int>current_string_vec;
    int n;

//    cout << (int)(' ');
    cin >> lost_string >> n;
    cin.ignore();

    for (int i = 0; i < lost_string.size(); i++)
    {
        lost_string_vec.emplace_back(lost_string[i]);
    }

    int index = 0, find_pos = 0;
    bool is_find = true;
    for (int i = 0; i < n; i++)
    {
//        cin >> t;
        getline(cin, t);
        current_string_vec = {};
        is_find = true;
        index = 0;

        for (int j = 0; j < t.size(); j++)
        {
//            if(t[j] == ' ') continue;

            if(65 <= (int)t[j] && (int)t[j] <= 90)
            {
                current_string_vec.emplace_back((int)t[j] + 32);

                if(current_string_vec[index] != lost_string_vec[index])
                {
                    is_find = false;
                    break;
                }
                index++;
            }
            else if(97 <= (int)t[j] && (int)t[j] <= 122)
            {
                current_string_vec.emplace_back((int)t[j]);

                if(current_string_vec[index] != lost_string_vec[index])
                {
                    is_find = false;
                    break;
                }
                index++;
            }

        }

//        cout << index << " " << lost_string_vec.size()<< endl;
        if(is_find && index == lost_string_vec.size())
        {
            find_pos = i+1;
            break;
        }
    }

    cout << find_pos;
}

//'a' = 97
//'A' = 65
// -) 32

//'z' = 122
//'Z' = 90