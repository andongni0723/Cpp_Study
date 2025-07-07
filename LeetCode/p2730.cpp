#include <bits/stdc++.h>
using namespace std;
#define lint long long;
#define endl "\n"

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int maxSize = 1;
        const int size = s.size();
        int same = 0;
        int L = 0;
        for(int R = 0 ; R < size ; ++R)
        {
            if(R > 0 && s[R] == s[R-1])
                same++;

            while(same > 1)
            {
                if(s[L+1] == s[L] && L + 1 <= R)
                    same--;
                L++;
            }
            maxSize = max(maxSize, R-L+1);
        }

        return maxSize;
    }
};