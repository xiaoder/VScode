#include <stdio.h>
#define N 10
struct date
{
    int year, month, day;
};
struct marriedState
{
    struct date marryDay;
    char spouseName[10];
    int children;
};
struct divorceState
{
    struct date divorceDay;
    int children;
};
union marritalState
{
    int single;
    struct marriedState married;
    struct divorceState divorce;
};
struct person
{
    int num;
    char name[10];
    char sex;
    int age;
    union marritalState marital;
    int marryFlag;
};
int main()
{
    int n;
    struct person aa[N];
    printf("������Ա����:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        aa[i].num = i + 1;
        printf("�������%d��Ա�������� �Ա� ����:",i+1);
        scanf("%s %c %d", aa[i].name, &aa[i].sex, &aa[i].age);
        printf("��ѡ���%d��Ա���Ļ���״̬:\n", i + 1);
        printf("1.δ��\n2.�ѻ�\n3.���\n");
        printf("�������%d��Ա���Ļ���״̬��Ӧ�����(1-3):",i+1);
        scanf("%d", &aa[i].marryFlag);
        if(aa[i].marryFlag == 2)
        {
            printf("�������%d��Ա���Ľ������:", i + 1);
            scanf("%d %d %d", &aa[i].marital.married.marryDay.year, &aa[i].marital.married.marryDay.month, &aa[i].marital.married.marryDay.day);
            printf("�������%d��Ա������ż����:", i + 1);
            scanf("%s", aa[i].marital.married.spouseName);
            printf("�������%d��Ա���ĺ�����:", i + 1);
            scanf("%d", &aa[i].marital.married.children);
        }
        if(aa[i].marryFlag == 3)
        {
            printf("�������%d��Ա�����������:", i + 1);
            scanf("%d %d %d", &aa[i].marital.divorce.divorceDay.year, &aa[i].marital.divorce.divorceDay.month, &aa[i].marital.divorce.divorceDay.day);
            printf("�������%d��Ա���ĺ�����:", i + 1);
            scanf("%d", &aa[i].marital.divorce.children);
        }
    }
    printf("Ա�����  ����      �Ա�  ����  ����״̬  �����������  ��ż����  ������\n");
    for (int i = 0; i < n; i++)
    {
        printf("    %-6d%-10s%-6c%-6d", aa[i].num, aa[i].name, aa[i].sex, aa[i].age);
        if(aa[i].marryFlag == 1)
        {
            printf("δ��\n");
        }
        if(aa[i].marryFlag == 2)
        {
            printf("�ѻ�      %d/%02d/%02d      %-10s%d\n", aa[i].marital.married.marryDay.year, aa[i].marital.married.marryDay.month, aa[i].marital.married.marryDay.day, aa[i].marital.married.spouseName, aa[i].marital.married.children);
        }
        if(aa[i].marryFlag == 3)
        {
            printf("���      %d/%02d/%02d                %d\n", aa[i].marital.divorce.divorceDay.year, aa[i].marital.divorce.divorceDay.month, aa[i].marital.divorce.divorceDay.day, aa[i].marital.divorce.children);
        }
    }
    return 0;
}