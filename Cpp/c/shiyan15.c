#include <stdio.h>
#include <stdlib.h>
typedef struct PNode
{
    float coef;
    int expn;
    struct PNode *next;
} PNode;
PNode *createPoly(int n);
PNode *addPoly(PNode *headA, PNode *headB);
void output(PNode *head);
int main()
{
    PNode *headA, *headB;
    int n;
    printf("���������ʽA������:");
    scanf("%d", &n);
    printf("���������ʽA�����ϵ����ָ��:");
    headA = createPoly(n);
    printf("�������ʽA:\n");
    output(headA);
    printf("���������ʽB������:");
    scanf("%d", &n);
    printf("���������ʽB�����ϵ����ָ��:");
    headB = createPoly(n);
    printf("�������ʽB:\n");
    output(headB);
    headA = addPoly(headA, headB);
    printf("�����������ʽ��Ӻ�Ľ������ʽA:\n");
    output(headA);
    return 0;
}
PNode *createPoly(int n)
{
    PNode *head, *p, *qq, *q;
    head = NULL;
    for (int i = 0; i < n; i++)
    {
        p = (PNode *)malloc(sizeof(PNode));
        p->next = NULL;
        scanf("%f%d", &p->coef, &p->expn);
        if(head == NULL)
        {
            head = p;
        }
        else
        {
            if (p->expn < head->expn)
            {
                p->next = head;
                head = p;
            }
            else
            {
                qq = head;
                q = head->next;
                while(qq && p->expn > qq->expn)
                {
                    q = qq;
                    qq = q->next;
                }
                p->next = qq;
                q->next = p;
            }
        }
    }
    return head;
}
PNode *addPoly(PNode *headA, PNode *headB)
{
    PNode *pA, *pB, *q, *qq;
    pA = headA;
    pB = headB;
    q = NULL;
    qq = NULL;
    while(pA && pB)
    {
        if(pA->expn < pB->expn)
        {
            q = pA;
            pA = pA->next;
        }
        else if (pA->expn > pB->expn)
        {
            if(q)
            {
                qq = pB;
                pB = pB->next;
                qq->next = pA;
                q->next = qq;
                q = qq;
            }
            else
            {
                headA = headB;
                pB = pB->next;
                headA->next = pA;
                q = headA;
            }
        }
        else
        {
            pA->coef += pB->coef;
            qq = pB;
            pB = pB->next;
            free(qq);
            if(!pA->coef)
            {
                qq = pA;
                q->next = pA->next;
                pA = pA->next;
                free(qq);
            }
            else
            {
                q = pA;
                pA = pA->next;
            }
        }
    }
    if(!pA)
    {
        q->next = pB;
    }
    return headA;
}
void output(PNode *head)
{
    PNode *p = head;
    while(p)
    {
        printf("%.2f %d, ", p->coef, p->expn);
        p = p->next;
    }
    putchar('\n');
}