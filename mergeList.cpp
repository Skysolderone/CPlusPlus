#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
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

int main()
{
    // 创建两个有序链表 1 -> 2 -> 4 和 1 -> 3 -> 4
    ListNode n1(1);
    ListNode n2(2);
    ListNode n4_1(4);

    n1.next = &n2;
    n2.next = &n4_1;

    ListNode n3(3);
    ListNode n4_2(4);

    n3.next = &n4_2;

    // 合并两个有序链表
    ListNode *mergedList = mergeTwoLists(&n1, &n3);

    // 打印合并后的链表元素
    ListNode *curr = mergedList;
    while (curr)
    {
        std::cout << curr->val << " ";
        curr = curr->next;
    }

    return 0;
}