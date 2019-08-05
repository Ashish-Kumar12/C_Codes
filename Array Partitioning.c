/*
    Array partitioning so that difference of sum of two sub arrays is minimum
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void swap();
void permute();
void solve();
void print_sol();

int main()
{
    register int i;
    int cnt=0, x, sum=0, n[100];
    char str[100];
    char *token, s[]=" ", a[5];

    printf("Enter the numbers : ");
    gets(str);
    fflush(stdin);

    token = strtok(str, s);
    for(i=0; token != NULL; i++)
    {
        strcpy(a, token);
        x = atoi(a);
        token = strtok (NULL, s);
        n[i] = x;
        sum += x;
    }
    cnt = i;
    x = sum/2;

    for(i=x; i>=1; i--)
    {
        permute(n, 0, cnt-1, i, cnt);
    }

    return 0;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(int *a, int l, int r, int trg, int cnt)
{
   int i;
   if (l == r)
   {
       solve(cnt, a, trg);
   }
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r, trg, cnt);
          swap((a+l), (a+i));
       }
   }
}

void solve(int cnt, int n[cnt], int trg)
{
    register int i;
    int sum=0;
    bool status;

    for(i=0; i<cnt; i++)
    {
        sum += n[i];

        if(sum>trg)
        {
            status = false;
            break;
        }
        else if(sum==trg)
        {
            status = true;
            break;
        }
    }

    if(status)
    {
        print_sol(cnt, n, i);
    }
}

void print_sol(int cnt, int n[cnt], int a)
{
    register int i;
    int sum1=0, sum2=0;

    printf("\n\nFirst Sub Array == >\n\n");
    for(i=0; i<=a; i++)
    {
        printf("%d ", n[i]);
        sum1 += n[i];
    }
    printf("\nSum = %d", sum1);

    printf("\n\nSecond Sub Array == >\n\n");
    for(i=a+1; i<cnt; i++)
    {
        printf("%d ", n[i]);
        sum2 += n[i];
    }
    printf("\nSum = %d", sum2);

    printf("\n\nDifference = %d", abs(sum1-sum2));

    exit(0);
}
