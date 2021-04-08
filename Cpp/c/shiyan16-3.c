#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int suiji(int m, int n)
{
    return rand() % (n - m + 1) + m;
}
void shuffle(int Deck[][13])
{
    int row, column;
    memset(*Deck, 0, 52*4);
    for (int i = 1; i <= 52; i++)
    {
        do{
            row = suiji(0, 3);
            column = suiji(0, 12);
        } while (Deck[row][column]);
        Deck[row][column] = i;
    }
}
void deal(int Deck[][13],char *suit[],char *value[])
{
    printf("   Íæ¼Ò1      Íæ¼Ò2      Íæ¼Ò3      Íæ¼Ò4\n");
    for (int i = 1; i <= 52; i++)
    {
        for (int row = 0; row <= 3; row++)
        {
            for (int column = 0; column <= 12; column++)
            {
                if (Deck[row][column] == i)
                {
                    printf("%6s%3s  ", suit[row], value[column]);
                }
            }
        }
        if(i % 4 == 0)
        {
            putchar('\n');
        }
    }
}
int main()
{
    srand(time(NULL));
    int Deck[4][13];
    char *suit[4] = {"ºìÌÒ", "·½¿é", "²Ý»¨", "ºÚÌÒ"};
    char *value[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    shuffle(Deck);
    deal(Deck, suit, value);
    return 0;
}