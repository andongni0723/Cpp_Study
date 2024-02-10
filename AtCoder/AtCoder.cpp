#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

class People
{
public:
    string name;
    int attack;
    string say;

    People(string _name, int _attack, string _say);
};

People::People(std::string _name, int _attack, std::string _say)
{
    name = _name;
    attack = _attack;
    say = _say;
}

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    People p1("AA", 30, "Hi");
    People p2("BB", 20, "Fuck");
    People p3("CC", 100, "Fuck You"); // New
    People current_people("", 0, "");

    int n, t1;
    string t2;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t1 >> t2;

       if(t1 == 1)
           current_people = p1;
       else if(t1 == 2)
           current_people = p2;
       else if(t1 == 3)          // New
           current_people = p3;  // New

       if(t2 == "name")
           cout << current_people.name << endl;
       else if(t2 == "attack")
           cout << current_people.attack << endl;
       else if(t2 == "say")
           cout << current_people.say << endl;
    }

}