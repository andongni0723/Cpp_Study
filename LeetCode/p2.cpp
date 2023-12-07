#include <bits/stdc++.h>
using namespace std;
int main() {}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *resultListNode = new ListNode(0);
        ListNode *currentResultListNode = resultListNode;

        int plusNum, carry = 0;
        int n1, n2;

        while (l1 || l2)
        {
            // Check next NodeList is NULL
            n1 = l1 ? l1->val : 0;
            n2 = l2 ? l2->val : 0;

            plusNum = n1 + n2 + carry;

            // Check can Carry
            if (plusNum >= 10)
            {
                plusNum -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            // Out to result ListNode
            currentResultListNode->next = new ListNode(plusNum);

            // Set Next Node
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;

            currentResultListNode = currentResultListNode->next;
        }

        if (carry != 0)
            currentResultListNode->next = new ListNode(1);

        return resultListNode->next;
    }
};
