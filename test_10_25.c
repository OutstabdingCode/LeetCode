#include <stdio.h>
struct ListNode 
{
    int val;
    struct ListNode* next;
    
};
//����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ�
struct ListNode* removeElements(struct ListNode* head, int val) {
    //�������ڱ�λ��������
    struct ListNode* newHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    newHead->next = NULL;
    struct ListNode* newTail = newHead;
    struct ListNode* cur = head;
    while (cur)
    {
        //����ԭ����
        struct ListNode* next = cur->next;
        if (cur->val != val)
        {
            //β����
            newTail->next = cur;
            cur->next = NULL;
            newTail = cur;
        }
        cur = next;
    }
    return newHead->next;
}