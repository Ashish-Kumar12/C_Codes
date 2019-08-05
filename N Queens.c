// N Queens Problem in C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sol=0;

void print_solution();
bool is_safe();
void mark_queen();
void solve();

int main()
{
    int n;
    printf("Enter your input (>3) : ");
    scanf("%d", &n);

    solve(n);

    if(sol==0)
    {
        printf("\n\nNo solution. " );
    }
    else
    {
        printf("\n\nTotal number of solution(s) found are : %d", sol);
    }

    return 0;
}
void solve(int n)
{
    int board[n][n];
    register int i, j;
    int col=0, row=0;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            board[i][j]=0;
        }
    }

    mark_queen(n, board, col, row);
}
void mark_queen(int n, int board[n][n], int col, int row)
{
    register int i;
    bool res;

    if(row==n)
    {
        print_solution(n, board);
        return ;
    }

    for(i=0; i<n; i++)
    {
        board[row][i]=1;

        res=is_safe(n, board, i, row);

        if(res==true)
        {
            mark_queen(n, board, 0, row+1);
        }

        board[row][i]=0;
    }

}
bool is_safe(int n, int board[n][n], int col, int row)
{
    register int i, j;

    for(i=row+1; i<n; i++)
    {
        if(board[i][col]==1)
            return false;
    }

    for(i=row-1; i>=0; i--)
    {
        if(board[i][col]==1)
            return false;
    }

    for(i=col+1; i<n; i++)
    {
        if(board[row][i]==1)
            return false;
    }

    for(i=col-1; i>=0; i--)
    {
        if(board[row][i]==1)
            return false;
    }

    for(i=row+1, j=col+1; i<n&&j<n; i++, j++)
    {
        if(board[i][j]==1)
            return false;
    }

    for(i=row-1, j=col-1; i>=0&&j>=0; i--, j--)
    {
        if(board[i][j]==1)
            return false;
    }

    for(i=row+1, j=col-1; i<n&&j>=0; i++, j--)
    {
        if(board[i][j]==1)
            return false;
    }

    for(i=row-1, j=col+1; i>=0&&j<n; i--, j++)
    {
        if(board[i][j]==1)
            return false;
    }

    return true;
}
void print_solution(int n, int board[n][n])
{
    register int i, j;
    char str[n][n];

    sol++;

    printf("\n\nSolution NO = %d\n", sol);

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(board[i][j]==0)
            {
                str[i][j]='0';
            }
            else
            {
                str[i][j]='Q';
            }

            printf("%c ", str[i][j]);
        }

        printf("\n");
    }

}
