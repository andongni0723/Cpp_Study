#include <bits/stdc++.h>
using namespace std;
#define lint long long;
#define endl "\n"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, nullptr);

        int size = 0;
        auto temp = head;
        while(temp)
        {
            size++;
            temp = temp->next;
        }

        int normal = size / k;
        int more_idx = size % k - 1;

        auto current = head;
        for(int i = 0 ; i < k ; ++i)
        {
            result[i] = current;
            int count = i <= more_idx ? normal + 1 : normal;

            ListNode* node = current;

            // run
            for(int j = 0; j < count - 1; ++j)
                if(node) node = node->next;

            // cut
            if (node)
            {
                ListNode* nextRound = node->next;
                node->next = nullptr;
                current = nextRound;
            }
            else
                current = nullptr;
        }

        return result;
    }
};