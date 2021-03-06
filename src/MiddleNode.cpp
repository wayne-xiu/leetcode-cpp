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
    https://leetcode.com/problems/linked-list-cycle/
*/

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
    ListNode *middleNode(ListNode *head)
    {
        if (!head || !(head->next))
            return head;
        ListNode *fast = head, *slow = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
    vector<int> vec{1};
    ListNode *list = createListNode(vec);

    Solution solution;
    ListNode *middle = solution.middleNode(list);
    printListNode(middle);

    return 0;
}