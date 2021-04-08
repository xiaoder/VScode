#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
    long num;
    char name[10], sex;
    int age, c;
} Student;
typedef struct node
{
    Student date;
    struct node *next;
} Node;
Node *creat();
void print(Node *head);
Node *del (Node *head);
int main()
{
    Node *head = NULL;
    head = creat();
    print(head);
    head = del (head);
    print(head);
    return 0;
}

Node *creat()
{
    Node *head, *p, *m, *n;
    long num;
    head = p = m = n = NULL;
    printf("student information:");
    scanf("%ld", &num);
    while (num != -1)
    {
        m = head;
        p = (Node *)malloc(sizeof(Node));
        p->date.num = num;
        scanf("%s %c%d%d", p->date.name, &p->date.sex, &p->date.age, &p->date.c);
        p->next = NULL;
        if(head == NULL)
        {
            head = p;
        }
        else
        {
            if (p->date.num < head->date.num)
            {
                p->next = head;
                head = p;
            }
            else
            {
                while (m && m->date.num < p->date.num)
                {
                    n = m;
                    m = m->next;
                }
                p->next = m;
                n->next = p;
            }
        }
        scanf("%ld", &num);
    }
    return head;
}

void print(Node *head)
{
    Node *p;
    p = head;
    while(p)
    {
        printf("%-10ld%-8s%-3c%-5d%-5d\n", p->date.num, p->date.name, p->date.sex, p->date.age, p->date.c);
        p = p->next;
    }
}

Node *del (Node *head)
{
    long num;
    Node *m, *n;
    printf("delete id:");
    scanf("%ld", &num);
    if(head->date.num == num)
    {
        m = head;
        head = head->next;
        free(m);
    }
    else
    {
        m = head->next;
        n = head;
        while(m && m->date.num != num)
        {
            n = m;
            m = m->next;
        }
        if(!m)
        {
            printf("no find\n\n");
        }
        else
        {
            n->next = m->next;
            free(m);
        }
    }
    return head;
}