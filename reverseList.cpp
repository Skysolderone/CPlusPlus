#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *reverseList(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *prev = nullptr, *curr = head, *next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
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

    // 反转链表
    ListNode *reversedList = reverseList(&n1);

    // 打印反转后的链表元素
    ListNode *curr = reversedList;
    while (curr)
    {
        std::cout << curr->val << " ";
        curr = curr->next;
    }

    return 0;
}