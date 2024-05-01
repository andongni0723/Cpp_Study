#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

stack<int> num;
stack<string> op;
stack<int> op_par_count;

int f(int x)
{
    return 2 * x - 3;
}

int g(int x, int y)
{
    return 2 * x + y - 7;
}

int h(int x, int y, int z)
{
    return 3 * x - 2 * y + z;
}

int get_func_par_count_data(string func)
{
    if(func == "f") return 1;
    else if(func == "g") return 2;
    else if(func == "h") return 3;
    return -1;
}

bool check()
{
    if(op.empty() || op_par_count.empty()) return false;
    return get_func_par_count_data(op.top()) == op_par_count.top();
}


int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    string t;
    while(cin >> t)
    {
        if(t == "f" || t == "g" || t == "h") // t is op
        {
            op.push(t);
            op_par_count.push(0);
        }
        else // t is int
        {
            int new_t = stoi(t);
            num.push(new_t);

            int top_func_par_count = op_par_count.top(); op_par_count.pop();
            op_par_count.push(top_func_par_count + 1);

            while(check())  // func par count enough
            {
                int result = 0;
                int x = 0, y = 0, z = 0;

                if(op.top() == "f")
                {
                    x = num.top(); num.pop();
                    result = f(x);
                }
                else if(op.top() == "g")
                {
                    y = num.top(); num.pop();
                    x = num.top(); num.pop();
                    result = g(x, y);
                }
                else if(op.top() == "h")
                {
                    z = num.top(); num.pop();
                    y = num.top(); num.pop();
                    x = num.top(); num.pop();
                    result = h(x, y, z);
                }

                op.pop();
                num.push(result);


                op_par_count.pop();

                // add before func par count
                if(!op_par_count.empty())
                {
                    int b = op_par_count.top(); op_par_count.pop();
                    op_par_count.push(b + 1);
                }
            }
        }
    }

    int ans = num.top();
    cout << ans;
}