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
            printf("��һ�ſε�ƽ������%.2f\n",pingjun(aa));
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
(1) ¼��ÿ��ѧ����ѧ�źͳɼ�;\n\
(2) ���һ�ſε�ƽ����;\n\
(3) �ҳ��� 2 �����Ͽγ̲������ѧ����������ǵ�ѧ�š�ȫ���γ̳ɼ���ƽ���ɼ�;\n\
(4) �ҳ�ƽ���ɼ� 90 �����ϻ�ȫ���γɼ��� 85 �����ϵ�ѧ����\n\
(5) �˳�\n\
****************************************************************\n");
}

void luru (float *p,long *q)
{
    int i, j;
    long *k = q;
    for (i = 0; i < 5; i++,q++)
    {
        printf("�������%d��ѧ��ѧ��:",i + 1);
        scanf("%ld",q);
    }
    for ( i = 0; i < 5; i++,k++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("������ѧ��Ϊ%ld��ѧ���ĵ�%d�ſγ̳ɼ�",*k,j+1);
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