/*图形输出*/
#include<stdio.h>
void main()
{
    int n,i,j;
    char ch;
    ch=getchar();
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<(n-1-i); j++)
            printf(" ");
        for(j=0; j<(2*i+1); j++)
            printf("%c",ch);
        printf("\n");
    }
}