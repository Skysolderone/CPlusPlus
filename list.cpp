#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *merge(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    ListNode dummy(0);
    ListNode *curr = &dummy;

    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            curr->next = l1;
            l1 = l1->next;
        }
        else
        {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }

    curr->next = (l1 ? l1 : l2);

    return dummy.next;
}

ListNode *sortList(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *slow = head, *fast = head, *prev = nullptr;

    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = nullptr;

    return merge(sortList(head), sortList(slow));
}

int main()
{
    // 创建链表 4 -> 2 -> 1 -> 3
    ListNode n4(4);
    ListNode n2(2);
    ListNode n1(1);
    ListNode n3(3);

    n4.next = &n2;
    n2.next = &n1;
    n1.next = &n3;

    // 排序链表
    ListNode *sortedList = sortList(&n4);

    // 打印排序后的链表元素
    ListNode *curr = sortedList;
    while (curr)
    {
        std::cout << curr->val << " ";
        curr = curr->next;
    }

    return 0;
}