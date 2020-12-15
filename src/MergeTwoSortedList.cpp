#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <memory>
#include <chrono>
#include <cassert>
#include <cmath>
#include <stack>
#include <array>

using namespace std;

/*
    https://leetcode.com/problems/merge-two-sorted-lists/
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// recursive solution
// class Solution
// {
// public:
//     ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
//     {
//         if (l1 == nullptr)
//             return l2;
//         if (l2 == nullptr)
//             return l1;
//         if (l1->val < l2->val)
//         {
//             l1->next = mergeTwoLists(l1->next, l2);
//             return l1;
//         }
//         else
//         {
//             l2->next = mergeTwoLists(l1, l2->next);
//             return l2;
//         }
//     }
// };

// non-recursive
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (nullptr == l1)
            return l2;
        if (nullptr == l2)
            return l1;

        ListNode *head = nullptr; // head of the list to return

        // find first element (can use dummy node to put this part inside of the loop)
        if (l1->val < l2->val)
        {
            head = l1;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            l2 = l2->next;
        }

        ListNode *p = head; // pointer to form new list
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        // add the rest of the tail, done!
        if (l1)
            p->next = l1;
        else
            p->next = l2;

        return head;
    }
};

void printListNode(ListNode *head)
{
    if (head == nullptr)
        return;
    ListNode *temp = head;
    while (temp->next)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << temp->val << endl;
}

int main()
{
    vector<int> vec1{1, 2, 4};
    vector<int> vec2{1, 3, 4};
    ListNode *l1 = new ListNode(vec1.at(0));
    ListNode *l2 = new ListNode(vec2.at(0));
    ListNode *temp = l1;
    for (int i = 1; i < vec1.size(); i++)
    {
        temp->next = new ListNode(vec1[i]);
        temp = temp->next;
    }
    temp = l2;
    for (int i = 1; i < vec1.size(); i++)
    {
        temp->next = new ListNode(vec2[i]);
        temp = temp->next;
    }
    printListNode(l1);
    printListNode(l2);

    Solution solution;
    ListNode *mergedHead = solution.mergeTwoLists(l1, l2);
    printListNode(mergedHead);

    return 0;
}