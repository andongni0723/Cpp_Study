#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

void draw(string draw_char, int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << draw_char;
    }
}

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> draw_count_vec;
    int n, max_odd_count, max_star_count;
    cin >> n;

    max_odd_count = n % 2 == 1 ? n+2 : n-1+2;

    //Input
    for (int i = 1; i <= max_odd_count; i+=2)
    {
        draw_count_vec.emplace_back(n % 2 == 1 ? i : i+1);
    }
    for(int i = max_odd_count - 2 ; i > 0 ; i-=2)
    {
        draw_count_vec.emplace_back(n % 2 == 1 ? i : i+1);
    }

    max_star_count = n % 2 == 0 ? max_odd_count+1 : max_odd_count;

    //Output
    for(auto it : draw_count_vec)
    {
        draw(" ", (max_star_count-it)/2);
        draw("*", it);
        cout << endl;
    }
}