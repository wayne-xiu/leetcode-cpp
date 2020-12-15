// CodeDaily.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// class Solution
// {
// public:
//     ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
//     {
//         ListNode *h1 = l1;
//         ListNode *h2 = l2;
//         int div = (int)(h1->val + h2->val) / 10;
//         int rem = (h1->val + h2->val) % 10;
//         ListNode *sum = new ListNode(rem);
//         ListNode *current = sum;
//         while (h1->next || h2->next)
//         {
//             ListNode *h1next = h1->next;
//             ListNode *h2next = h2->next;
//             if (!h1next)
//             {
//                 rem = (div + h2next->val) % 10;
//                 div = (int)(div + h2next->val) / 10;
//                 current->next = new ListNode(rem);
//                 h2 = h2next;
//             }
//             else if (!h2next)
//             {
//                 rem = (div + h1next->val) % 10;
//                 div = (int)(div + h1next->val) / 10;
//                 current->next = new ListNode(rem);
//                 h1 = h1next;
//             }
//             else
//             {
//                 rem = (div + h1next->val + h2next->val) % 10;
//                 div = (int)(div + h1next->val + h2next->val) / 10;
//                 current->next = new ListNode(rem);
//                 h1 = h1next;
//                 h2 = h2next;
//             }
//             current = current->next;
//         }
//         if (div != 0)
//         {
//             current->next = new ListNode(div);
//         }
//         return sum;
//     }
// };

// the use of for loop and ?: operator is elegant
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(-1); // head node
        int carry = 0;
        ListNode *prev = &dummy;
        for (ListNode *pa = l1, *pb = l2;
             pa != nullptr || pb != nullptr;
             pa = pa == nullptr ? nullptr : pa->next,
                      pb = pb == nullptr ? nullptr : pb->next,
                      prev = prev->next)
        {
            const int ai = pa == nullptr ? 0 : pa->val;
            const int bi = pb == nullptr ? 0 : pb->val;
            const int value = (ai + bi + carry) % 10;
            carry = (ai + bi + carry) / 10;
            prev->next = new ListNode(value);
        }
        if (carry > 0)
            prev->next = new ListNode(carry);
        return dummy.next;
    }
};

int main()
{
    ListNode *L1 = new ListNode(9);
    ListNode *L2 = new ListNode(9);

    L1->next = new ListNode(9);
    L1->next->next = new ListNode(9);
    L1->next->next->next = new ListNode(9);
    L1->next->next->next->next = new ListNode(9);
    L1->next->next->next->next->next = new ListNode(9);
    L1->next->next->next->next->next->next = new ListNode(9);

    L2->next = new ListNode(9);
    L2->next->next = new ListNode(9);
    L2->next->next->next = new ListNode(9);

    Solution solution;
    ListNode *sum = solution.addTwoNumbers(L1, L2);

    ListNode *temp = sum;
    while (temp)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}
