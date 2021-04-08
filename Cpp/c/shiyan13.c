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
    printf("请输入员工数:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        aa[i].num = i + 1;
        printf("请输入第%d个员工的姓名 性别 年龄:",i+1);
        scanf("%s %c %d", aa[i].name, &aa[i].sex, &aa[i].age);
        printf("请选择第%d个员工的婚姻状态:\n", i + 1);
        printf("1.未婚\n2.已婚\n3.离婚\n");
        printf("请输入第%d个员工的婚姻状态对应的序号(1-3):",i+1);
        scanf("%d", &aa[i].marryFlag);
        if(aa[i].marryFlag == 2)
        {
            printf("请输入第%d个员工的结婚日期:", i + 1);
            scanf("%d %d %d", &aa[i].marital.married.marryDay.year, &aa[i].marital.married.marryDay.month, &aa[i].marital.married.marryDay.day);
            printf("请输入第%d个员工的配偶姓名:", i + 1);
            scanf("%s", aa[i].marital.married.spouseName);
            printf("请输入第%d个员工的孩子数:", i + 1);
            scanf("%d", &aa[i].marital.married.children);
        }
        if(aa[i].marryFlag == 3)
        {
            printf("请输入第%d个员工的离婚日期:", i + 1);
            scanf("%d %d %d", &aa[i].marital.divorce.divorceDay.year, &aa[i].marital.divorce.divorceDay.month, &aa[i].marital.divorce.divorceDay.day);
            printf("请输入第%d个员工的孩子数:", i + 1);
            scanf("%d", &aa[i].marital.divorce.children);
        }
    }
    printf("员工编号  姓名      性别  年龄  婚姻状态  结婚或离婚日期  配偶姓名  孩子数\n");
    for (int i = 0; i < n; i++)
    {
        printf("    %-6d%-10s%-6c%-6d", aa[i].num, aa[i].name, aa[i].sex, aa[i].age);
        if(aa[i].marryFlag == 1)
        {
            printf("未婚\n");
        }
        if(aa[i].marryFlag == 2)
        {
            printf("已婚      %d/%02d/%02d      %-10s%d\n", aa[i].marital.married.marryDay.year, aa[i].marital.married.marryDay.month, aa[i].marital.married.marryDay.day, aa[i].marital.married.spouseName, aa[i].marital.married.children);
        }
        if(aa[i].marryFlag == 3)
        {
            printf("离婚      %d/%02d/%02d                %d\n", aa[i].marital.divorce.divorceDay.year, aa[i].marital.divorce.divorceDay.month, aa[i].marital.divorce.divorceDay.day, aa[i].marital.divorce.children);
        }
    }
    return 0;
}