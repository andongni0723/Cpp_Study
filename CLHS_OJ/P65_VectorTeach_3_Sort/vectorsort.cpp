#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    //ifstream in("/Users/andongni/Documents/Myself_Folder/03_Program_Study/Cpp_Study/CLHS_OJ/P65_VectorTeach_3_Sort/Data/6.in");
    //ofstream out("/Users/andongni/Documents/Myself_Folder/03_Program_Study/Cpp_Study/CLHS_OJ/P65_VectorTeach_3_Sort/Data/6.out");

    int n;
    vector<int> vec;

    //in >> n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int t;
        //in >> t;
        cin >> t;
        vec.push_back(t);
    }

    sort(vec.begin(), vec.end());

    for(auto it : vec)
    {
        //out << it << endl;
        cout << it << endl;
    }
}