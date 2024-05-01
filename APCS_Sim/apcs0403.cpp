#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";


lint n, max_happy, result = 0;
lint w_happy, m_happy, l_happy;
lint w_time, m_time, l_time;
vector<char> vec;
vector<lint> diff((int)2e5 + 10, 0);
vector<lint> happy_vec;

lint get_happy(char c)
{
    if(c == 'W')
        return w_happy;
    else if(c == 'M')
        return m_happy;
    else if(c == 'L')
        return l_happy;
    else
        return -1;
}

lint get_time(char c)
{
    if(c == 'W')
        return w_time;
    else if(c == 'M')
        return m_time;
    else if(c == 'L')
        return l_time;
    else
        return -1;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> max_happy;

    vec.emplace_back(' ');

    char t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        vec.emplace_back(t);
    }

    cin >> w_happy >> m_happy >> l_happy;
    cin >> w_time >> m_time >> l_time;

    for (int i = 1; i <= n; i++)
    {
        lint current_happy = get_happy(vec[i]);
        lint right_time = i + get_time(vec[i]);

        diff[i] += current_happy;
        diff[min(n, right_time) + 1] -= current_happy;
    }

    happy_vec.emplace_back(0);
    for (int i = 1; i <= n; i++)
    {
        happy_vec.emplace_back(happy_vec[i-1] + diff[i]);
    }

    for(auto it : happy_vec)
    {
        if(it > max_happy)
            result++;
    }

    cout << result;

}