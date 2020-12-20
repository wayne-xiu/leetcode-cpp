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

/* Problem link:
    https://leetcode.com/problems/reverse-linked-list/
*/

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
//     ListNode *reverseList(ListNode *head)
//     {
//         if (!head)
//             return nullptr;
//         stack<int> list;
//         ListNode *temp = head;
//         while (temp)
//         {
//             list.push(temp->val);
//             temp = temp->next;
//         }
//         ListNode *reversedHead = new ListNode(list.top());
//         temp = reversedHead;
//         list.pop();
//         while (!list.empty())
//         {
//             temp->next = new ListNode(list.top());
//             temp = temp->next;
//             list.pop();
//         }
//         return reversedHead;
//     }
// };

// iterative solution
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *cur = head;
        while (cur && cur->next)
        {
            ListNode *temp = dummy->next;
            dummy->next = cur->next;
            cur->next = cur->next->next;
            dummy->next->next = temp;
        }
        return dummy->next;
    }
};

// recursive solution
// class Solution
// {
// public:
//     ListNode *reverseList(ListNode *head)
//     {
//         if (!head || !(head->next))
//             return head;
//         ListNode *node = reverseList(head->next);
//         head->next->next = head;
//         head->next = nullptr;
//         return node;
//     }
// };

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

ListNode *createListNode(const vector<int> &vec)
{
    if (vec.empty())
        return nullptr;
    ListNode *head = new ListNode(vec.at(0));
    ListNode *temp = head;
    for (int i = 1; i < vec.size(); i++)
    {
        temp->next = new ListNode(vec[i]);
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 5};
    ListNode *list = createListNode(vec);
    printListNode(list);

    Solution solution;
    ListNode *revList = solution.reverseList(list);
    printListNode(revList);

    return 0;
}