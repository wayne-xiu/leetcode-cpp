#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <memory>
#include <chrono>
#include <cassert>
#include <cmath>

using namespace std;

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
//     ListNode *removeNthFromEnd(ListNode *head, int n)
//     {
//         if (n <= 0)
//             return head;
//         int sz = 0;
//         ListNode *temp = head;
//         while (temp)
//         {
//             sz++;
//             temp = temp->next;
//         }
//         if (sz < n)
//             return nullptr;
//         if (sz == n)
//             return head->next;
//         temp = head;
//         for (int i = 0; i < sz - n - 1; i++)
//         {
//             temp = temp->next;
//         }
//         temp->next = temp->next->next;
//         return head;
//     }
// };

// use a dummy
// class Solution
// {
// public:
//     ListNode *removeNthFromEnd(ListNode *head, int n)
//     {
//         if (n <= 0)
//             return head;
//         ListNode *dummy = new ListNode();
//         dummy->next = head;
//         int length = 0;
//         ListNode *temp = head;
//         while (temp)
//         {
//             length++;
//             temp = temp->next;
//         }
//         length -= n;
//         temp = dummy;
//         while (length > 0)
//         {
//             length--;
//             temp = temp->next;
//         }
//         temp->next = temp->next->next;
//         return dummy->next;
//     }
// };
/// One-pass algorithm with 2 pointers n apart from each other
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (n <= 0)
            return head;
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *first = dummy;
        ListNode *second = dummy;
        for (int i = 1; i <= n + 1; i++)
            first = first->next;
        while (first != nullptr)
        {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next;
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
    vector<int> vec{1, 2, 3, 4, 5};
    ListNode *head = new ListNode(vec.at(0), nullptr);
    ListNode *temp = head;
    for (int i = 1; i < vec.size(); i++)
    {
        temp->next = new ListNode(vec[i]);
        temp = temp->next;
    }
    printListNode(head);
    Solution solution;
    int pos = 0;
    head = solution.removeNthFromEnd(head, pos);
    printListNode(head);

    return 0;
}