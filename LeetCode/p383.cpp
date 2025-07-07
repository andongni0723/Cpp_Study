#include <bits/stdc++.h>
using namespace std;
#define lint long long;
#define endl "\n"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_multiset<char> r_set;
        for(auto r : ransomNote) r_set.insert(r);

        for(auto m : magazine)
        {
            auto t = r_set.find(m);
            if(t != r_set.end())
                r_set.erase(t);
        }

        return r_set.size() == 0;
    }
};


int main()
{

}
