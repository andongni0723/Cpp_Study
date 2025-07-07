#include <bits/stdc++.h>
using namespace std;
#define lint long long;
#define endl "\n"

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string temp;
        int r = 0;
        for(auto c : to_string(num))
        {
            if (temp.size() != k) // temp 不到 k 位
                temp += c;
            else
                temp = temp.substr(1) + c; // temp 丟頭，加尾

            if (temp.size() == k)
            {
                if (stoi(temp) == 0) // 除數不為 0
                    continue;
                if (num % stoi(temp) == 0) // 整除
                    r++;
            }
        }

        return r;
    }
};

int main()
{
    Solution s = Solution();
    s.divisorSubstrings(1, 1);
}