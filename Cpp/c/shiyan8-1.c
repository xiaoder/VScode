#include <stdio.h>
void menu();
void luru (float *p,long *q);
float pingjun(float (*p)[5]);
void bujige (float *p, long *q);
void haohaizi (float *p, long *q);
int main()
{
    int flag = 1;
    int x;
    float aa[10][5];
    long bb[10];
    while (flag)
    {
        menu();
        scanf("%d",&x);
        switch (x)
        {
        case 1:
            luru (*aa,bb);
            break;
        case 2:
            printf("第一门课的平均分是%.2f\n",pingjun(aa));
            break;
            case 3:
            bujige(*aa,bb);
            break;
            case 4:
            haohaizi(*aa,bb);
        default:
            flag = 0;
            break;
        }
    }
    
    return 0;
}

void menu ()
{
    printf("****************************************************************\n\
(1) 录入每个学生的学号和成绩;\n\
(2) 求第一门课的平均分;\n\
(3) 找出有 2 门以上课程不及格的学生，输出他们的学号、全部课程成绩、平均成绩;\n\
(4) 找出平均成绩 90 分以上或全部课成绩在 85 分以上的学生。\n\
(5) 退出\n\
****************************************************************\n");
}

void luru (float *p,long *q)
{
    int i, j;
    long *k = q;
    for (i = 0; i < 5; i++,q++)
    {
        printf("请输入第%d名学生学号:",i + 1);
        scanf("%ld",q);
    }
    for ( i = 0; i < 5; i++,k++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("请输入学号为%ld的学生的第%d门课程成绩",*k,j+1);
            scanf("%f",p+5*i+j);
        }
        
    }
    
}

float pingjun(float (*p)[5])
{
    float m = 0;
    int i;
    for (i = 0;i < 5; i++,p++)
    {
        m += **p;
    }
    return m / i;
}

void bujige (float *p, long *q)
{
    int i, j, k;
    float m = 0;
    for (i = 0; i < 5; i++, q++)
    {
        k = 0;
        for (j = 0; j < 3; j++)
        {
            if (*(p+5*i+j) < 60)
                k++;
        }
        if (k >= 2)
        {
            printf("%ld\t",*q);
            for (j = 0; j < 3; j++)
        {
            printf ("%.2f ",*(p+5*i+j));
            m += *(p + 5 * i + j);
        }
        printf("\t%f\n",m/3);
        }
    }
}

void haohaizi (float *p, long *q)
{
    int i, j, k;
    float m = 0;
    for (i = 0; i < 5; i++, q++)
    {
        k = 0;
        for (j = 0; j < 3; j++)
        {
            if (*(p+5*i+j) >= 85)
                k++;
            m += *(p + 5 * i + j);
        }
        if (k == 3 || m / 3 >= 90)
        {
            printf("%ld\n",*q);
        }
    }
}