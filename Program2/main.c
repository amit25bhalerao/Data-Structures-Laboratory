#include <stdio.h>
#include <stdlib.h>

char t[100],p[100],r[100],f[100];

void create()
{
    printf("Enter The Text String\n");
    gets(t);

    printf("Enter The Pattern String\n");
    gets(p);

    printf("Enter The Replace String\n");
    gets(r);
}

int pattern_replace(char t[], char p[], char r[], char f[])
{
    int i,j,k,l,pi,flag=0;

    for(i=j=k=0;t[i]!='\0';j=0)
    {
        if(t[i]!=p[j])
        {
            f[k++]=t[i++];
            continue;
        }

        pi=i;
        while((p[j]!='\0')&&(t[i]==p[j]))
        {
            i++;
            j++;
        }

        if(p[j]!='\0')
        {
            i=pi;
            f[k++]=t[i++];
            continue;
        }

        l=0;
        while(r[l]!='\0')
            f[k++]=r[l++];

        flag=1;
    }

    f[k]='\0';
    return flag;
}


void main()
{
    int res;
    create();
    res=pattern_replace(t,p,r,f);

    if(res==1)
    {
        printf("The Resultant String Is Displayed Below\n");
        puts(f);
    }
    else
        printf("Pattern Not Found\n");

}

