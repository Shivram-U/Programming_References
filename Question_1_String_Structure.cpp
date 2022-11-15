#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*
Input:
      PAYPALISHIRING 3
*/
int str_l(char* a)
{
    int i=0;
    while(a[i]!='\0')
        i++;
    return i;
}

int main() 
{
    char a[30];
    int m,n,n1,k=0,o=0;
    scanf("%s %d",&a,&n);
    m = str_l(a);
    n1 = m/n;
    n1+=(n1+(n/2));
    char **mat = (char**)malloc(n*8);
    
    for(int i=0;i<n;i++)
        mat[i] = (char*)malloc(sizeof(char)*n1);
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(k>=m)
                break;
            if(i == o)
            {
                printf("[%c]",a[k]);
                mat[j][i] = a[k++];
                if(j == n-1)
                    o+=n/2+1;
            }
            else
                mat[j][i] = '*';
            printf("%d %d ",j,i);
        }
        printf("\n");
        if(k>=m)
            break;
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n1;j++)
        {
            printf("%c ",mat[i][j]);
        }
        printf("\n");
    }
    
    /*
    m = s;
    for(int i=0;i<n;i++)
    {
        if(k>=n)
        {
            j=0;
            while(j<n && a[j]=='#')
                j++;
            k = j;
            s-=2;
        }
        if(a[k]!='#')
        {
            printf("%c ",a[k]);
            a[k] = '#';
            k+=(s+(m-2));
        }
    }
    j=0;
    while(j<n)
    {
        if(a[j]!='#')
            printf("%c ",a[j]);
        j++;
    }*/
}
