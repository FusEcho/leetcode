#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode()
        : val(0), next(nullptr)
    {
    }
    ListNode(int x)
        : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x), next(next)
    {
    }
};

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* ptr;
        ListNode* head = new ListNode();
        ptr = head;

        int flag = 0;
        while (nullptr != l1 || nullptr != l2)
        {
            int a = 0, b = 0, c = 0;
            if (nullptr != l1)
            {
                a = l1->val;
                l1 = l1->next;
            }
            if (nullptr != l2)
            {
                b = l2->val;
                l2 = l2->next;
            }
            c = a + b + flag;
            flag = c >= 10 ? 1 : 0;
            ListNode* tmp = new ListNode(c % 10);
            ptr->next = tmp;
            ptr = ptr->next;
        }

        if (flag != 0)
        {
            ListNode* end = new ListNode(1);
            ptr->next = end;
        }

        return head->next;
    }
};

int main()
{
    Solution solution;

    ListNode *l1, *l2;
    ListNode a6(9);
    ListNode a5(9, &a6);
    ListNode a4(9, &a5);
    ListNode a3(9, &a4);
    ListNode a2(9, &a3);
    ListNode a1(9, &a2);
    ListNode a0(9, &a1);
    l1 = &a0;

    ListNode b3(9);
    ListNode b2(9, &b3);
    ListNode b1(9, &b2);
    ListNode b0(9, &b1);
    l2 = &b0;

    ListNode* ptr = solution.addTwoNumbers(l1, l2);
    while (nullptr != ptr)
    {
        cout << ptr->val << endl;
        ListNode* tmp = ptr;
        ptr = ptr->next;
        delete tmp;
    }

    return 0;
}