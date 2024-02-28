#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream out("/Users/andongni/Documents/Myself_Folder/03_Program_Study/Cpp_Study/CLHS_OJ/P65_VectorTeach_3_Sort/Data/6.in");

    if(!out.good()){
        cout << "output file opening failed";
        exit(1);
    }

    srand((unsigned) time(nullptr));

    int n = 100 + (rand() % 10000);

    out << n << endl;

    for (int i = 0; i < n; i++)
    {
        int ai = rand() % 100000000;
        out << ai << endl;
    }
    out << endl;
    out.close();
}