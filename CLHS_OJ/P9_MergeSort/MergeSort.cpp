#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

const lint END = 100000000;
void MergeSort(vector<lint> &vec, lint front, lint end)
{
    if(front >= end) return;

    lint mid = (front + end) / 2;

    MergeSort(vec, front, mid);
    MergeSort(vec, mid + 1, end);

    //Merge
    vector<lint> leftVec(vec.begin() + front, vec.begin() + mid + 1),
                 rightVec(vec.begin() + mid + 1, vec.begin() + end + 1);

    leftVec.push_back(END);
    rightVec.push_back(END);

    lint leftIndex = 0, rightIndex = 0;
    for (lint i = front; i <= end; i++)
    {
        if(leftVec[leftIndex] <= rightVec[rightIndex])
        {
            vec[i] = leftVec[leftIndex];
            leftIndex++;
        }
        else
        {
            vec[i] = rightVec[rightIndex];
            rightIndex++;
        }
    }
}

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    vector<lint> vec;
    lint n, t;
    cin >> n;
    for (lint i = 0; i < n ; i++)
    {
        cin >> t;
        vec.push_back(t);
    }

    MergeSort(vec,0, (lint)vec.size() - 1);

    for(auto it : vec)
    {
        cout << it << " ";
    }
}