#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head)
{
    if (!head || !head->next)
        return false;

    ListNode *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main()
{
    // 创建链表 1 -> 2 -> 3 -> 4
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    // 添加环形链接
    n4.next = &n2;

    bool hasCycleResult = hasCycle(&n1);
    std::cout << "Has Cycle: " << (hasCycleResult ? "Yes" : "No") << std::endl;

    return 0;
}