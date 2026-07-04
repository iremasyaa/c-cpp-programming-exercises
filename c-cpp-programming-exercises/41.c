#include <cstdlib>

#include <cstdio>
#include <cmath>
#include <ctime>
int main()
{
    srand(time(0));
    char admin[20];
    int sum1 = 0;
    int sum2 = 0;
    int kart = 0;
    char devam = 0;
    int win = 0;
    int lost = 0;
    printf("User : ");
    scanf("%s", &admin);
    printf("Successfully registered. Enter to start a game.\n");
    printf("q for contunie, w for break, e for results.\n\n");
    getchar();

    for (int z = 0;; z++)
    {
        scanf("%c", &devam);
        if (devam == 'q')
        {
            kart = rand() % 13 + 1;
            sum1 += kart;
            printf("Card = %d        Total : %d\n", kart, sum1);
            if (sum1 == 21)
            {
                printf("\nBlackJack ! YOU WIN !\n\n\n");
                win++;
                sum1 = 0;
            }
            if (sum1 > 21)
            {
                printf("\nYOU LOST !\n\n\n");
                lost++;
                sum1 = 0;
            }
        }
        else if (devam == 'w')
        {
            kart = rand() % 13 + 1;
            sum1 += kart;
            printf("Card = %d        Total : %d\n", kart, sum1);
            if (sum1 > 21)
            {
                win++;
                printf("\nYOU WIN!\n\n\n");
            }
            else
            {
                lost++;
                printf("\nYOU LOST !\n\n\n");
            }
            sum1 = 0;
        }
        else if (devam == 'e')
            printf("\nHey %s\n#WIN  == %d\n#LOST == %d\n\n", admin, win, lost);
    }
    return 0;
}