#include <stdio.h>
typedef struct student
{
    long num;
    char name[10], sex;
    int year, month, day;
    int c, gs , xd;
    float ave;
    int mc;
}Student;
void menu();
void f1(Student *p);
void f2(Student *p);
void f3(Student *p);
int main()
{
    Student *p;
    p = (Student *)malloc(10*sizeof(Student));
    int flag = 1, n;
    while(flag)
    {
        menu();
        scanf("%d",&n);
        switch (n)
        {
            case 1:
            f1(p);
            break;
            case 2:
            f2(p);
            break;
            case 3:
            f3(p);
            break;
            default:
            flag = 0;
            break;
        }
    }


}

void menu()
{
    printf("��1��Ҫ����һ���ṹ����������������ѧ������Ϣ�� \n\
��2������ѧ���Ļ�����Ϣ�Լ����ſγ̵ĳɼ��� \n\
��3�����ÿ��ѧ�����ſγ̵�ƽ���ֲ��������Ҫ�󲻽����ƽ���֣�\n\
��4���� 10 ��ѧ������ƽ���ֽ����Ŷӡ� ����ÿ��ѧ����������Ϣ��Ҫ�����\n\
��5�����ÿ�ſγ̳ɼ���ߵ�ͬѧ����Ϣ��\n\
");
}
void f1(Student *p)
{
    for(int i = 0;i < 10; i++)
    {
        scanf("%ld%s %c%d%d%d%d%d%d",&(p+i)->num,(p+i)->name,&(p+i)->sex,&(p+i)->year,&(p+i)->month,&(p+i)->day,&(p+i)->c,&(p+i)->gs,&(p+i)->xd);
    }
}

void f2(Student *p)
{
    for(int i = 0; i < 10; i++)
    {
        (p+i)->ave = ((p+i)->c + (p+i)->gs + (p+i)->xd) / 3.0;
    }
    Student x;
    for(int i = 0; i < 9; i++)
    {
        for (int j = i+1; j < 10; j++)
        {
            if((p+i)->ave<(p+j)->ave)
            {
                x = *(p+i);
                *(p+i) = *(p+j);
                *(p+j) = x;
            }
        }
    }
    for(int i = 0; i < 10; i++)
    {
        (p+i)->mc = i+1;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%10ld %10s %c %5d %02d %02d %3d %3d %3d %5.2f\n",(p+i)->num,(p+i)->name,(p+i)->sex,(p+i)->year,(p+i)->month,(p+i)->day,(p+i)->c,(p+i)->gs,(p+i)->xd,(p+i)->ave);
    }
}

void f3(Student *p)
{
    int c = 0, gs = 0, xd = 0;
    for(int i = 0; i < 10; i++)
    {
        if((p+c)->c < (p+i)->c)
        {
            c = i;
        }
        if((p+gs)->gs < (p+i)->gs)
        {
            gs = i;
        }
        if((p+xd)->xd < (p+i)->xd)
        {
            xd = i;
        }
    }
    printf("%10ld %10s %c %5d %02d %02d %3d %3d %3d %5.2f\n",(p+c)->num,(p+c)->name,(p+c)->sex,(p+c)->year,(p+c)->month,(p+c)->day,(p+c)->c,(p+c)->gs,(p+c)->xd,(p+c)->ave);
    for(int i = 0; i < 10; i++)
    {
        if((p+c)->c == (p+i)->c&&i!=c)
            printf("%10ld %10s %c %5d %02d %02d %3d %3d %3d %5.2f\n",(p+i)->num,(p+i)->name,(p+i)->sex,(p+i)->year,(p+i)->month,(p+i)->day,(p+i)->c,(p+i)->gs,(p+i)->xd,(p+i)->ave);
    }
    printf(("\n"));
    printf("%10ld %10s %c %5d %02d %02d %3d %3d %3d %5.2f\n",(p+gs)->num,(p+gs)->name,(p+gs)->sex,(p+gs)->year,(p+gs)->month,(p+gs)->day,(p+gs)->c,(p+gs)->gs,(p+gs)->xd,(p+gs)->ave);
    for(int i = 0; i < 10; i++)
    {
        if((p+gs)->gs == (p+i)->gs&&i!=gs)
            printf("%10ld %10s %c %5d %02d %02d %3d %3d %3d %5.2f\n",(p+i)->num,(p+i)->name,(p+i)->sex,(p+i)->year,(p+i)->month,(p+i)->day,(p+i)->c,(p+i)->gs,(p+i)->xd,(p+i)->ave);
    }
    printf(("\n"));
    printf("%10ld %10s %c %5d %02d %02d %3d %3d %3d %5.2f\n",(p+xd)->num,(p+xd)->name,(p+xd)->sex,(p+xd)->year,(p+xd)->month,(p+xd)->day,(p+xd)->c,(p+xd)->gs,(p+xd)->xd,(p+xd)->ave);
    for(int i = 0; i < 10; i++)
    {
        if((p+xd)->xd == (p+i)->xd&&i!=xd)
            printf("%10ld %10s %c %5d %02d %02d %3d %3d %3d %5.2f\n",(p+i)->num,(p+i)->name,(p+i)->sex,(p+i)->year,(p+i)->month,(p+i)->day,(p+i)->c,(p+i)->gs,(p+i)->xd,(p+i)->ave);
    }
    printf(("\n"));
}
