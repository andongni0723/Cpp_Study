#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> answerVector = {
            "vector<string> simple;", // 把引號中的文字替換成答案
            "simple.push_back(341);", // 把引號中的文字替換成答案
            "secVec.pop_back();", // 把引號中的文字替換成答案
    };

    int no;
    cin >> no;
    cout << answerVector[no - 1];
}
