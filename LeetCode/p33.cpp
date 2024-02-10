#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

class Solution
{
public :
    int search(vector<int> nums, int target)
    {
        int L = 0, R = nums.size() - 1;
        int mid;
        int stop = 0;


        while (L < R)
        {
            mid = (L + R) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                stop = mid + 1;
                break;
            }

            if (nums[mid] >= nums[L])
            {
                //R = mid - 1;
                L = mid + 1;
            } else
            {
                R = mid - 1;
                //L = mid + 1;
            }
        }
        //if(nums[mid] > nums[mid + 1]) stop = mid + 1;

        if (target >= nums[0]) // left
        {
            L = 0, R = stop - 1;
        } else // right
        {
            L = stop, R = nums.size() - 1;
        }

        cout << L << " " << R << endl;
        auto index = lower_bound(nums.begin() + L, nums.begin() + R + 1, target) - nums.begin();
        //int index = 0;
        cout << index;
        if  (index == R+1 || nums[index] != target) index = -1;
        return index;
    }
};

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    //int n = search({1, 2}, 2);
}