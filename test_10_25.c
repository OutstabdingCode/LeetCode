#include <stdio.h>
struct ListNode 
{
    int val;
    struct ListNode* next;
    
};
//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点
struct ListNode* removeElements(struct ListNode* head, int val) {
    //建立带哨兵位的新链表
    struct ListNode* newHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    newHead->next = NULL;
    struct ListNode* newTail = newHead;
    struct ListNode* cur = head;
    while (cur)
    {
        //遍历原链表
        struct ListNode* next = cur->next;
        if (cur->val != val)
        {
            //尾插结点
            newTail->next = cur;
            cur->next = NULL;
            newTail = cur;
        }
        cur = next;
    }
    return newHead->next;
}