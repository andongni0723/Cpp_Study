#include <bits/stdc++.h>
using namespace std;

string str;
int cur_ind = 0;

int det()
{
    vector<int> nums(5);
    for (int i = 0; i < 4; i++)
    {
        cur_ind++;
        nums[i] = str[cur_ind] == '#' ? det() : str[cur_ind] - '0';
    }
    // cout << "Det: " << ( nums[0] * nums[3] - nums[1] * nums[2]) << endl;
    return nums[0] * nums[3] - nums[1] * nums[2];
}

int calc()
{
    stack<int> num;
    char op = 0;
    for (cur_ind = 0; cur_ind < str.size(); cur_ind++)
    {
        if(str[cur_ind] == '+') op = '+';
        else if (str[cur_ind] == '#') op = '#';
        else num.emplace(str[cur_ind] - '0');

        if (op == '#')
            num.emplace(det());
        if (num.size() == 2 && op == '+' || cur_ind == str.size()-1 && num.size() == 2)
        {
            int a = num.top();
            num.pop();
            // cout << "Add(1): " << a << endl;
            // cout << "Add(2): " << num.top() << endl;
            a = a + num.top();
            num.pop();
            num.emplace(a);
        }

        // cout << "--Size: " << num.size() << endl;
    }


    // if (num.size() == 2)
    // {
    //     int a = num.top();
    //     num.pop();
    //     // cout << "Add(1): " << a << endl;
    //     // cout << "Add(2): " << num.top() << endl;
    //     a = a + num.top();
    //     num.pop();
    //     num.emplace(a);
    // }

    return num.top();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> str;
    cout << calc();
}


// const vector tests = {"1+2", "1+2+3", "#1234", "##2#43#2176#4321#435#7651#2314#435#5763#4#475667#12#34567+7+8", "##0#23002#430#2000#9#04039#3040#51#11161#5#1115#61114"};
// const vector ans = {3, 6, -2, -15384, 0};
// for(int i = 0; i <= tests.size() ; i++)
// {
//     str = tests[i];
//     cout << "> " << ((calc() == ans[i]) ? "true": "false") << endl;
//     cout << "> " << calc() << " " << ans[i] << endl;
// }
//#45##845697#8453#5673+9+5+4+2+#3546+#8456+##534255#9437