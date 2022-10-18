#include <stdio.h>
#define m 10
int HT[m];

int hash(int key)
{
    return (key%m);
}

void linearprobing(int hk,int key)
{
    int i,flag=0;

    for(i=hk+1;i<m;i++)
    {
        if(HT[i]==-1)
        {
            HT[i]=key;
            flag=1;
            break;
        }
    }

    for(i=0;i<m&&flag==0;i++)
    {
        if(HT[i]==-1)
        {
            HT[i]=key;
            flag=1;
            break;
        }
    }

    if(!flag)
        printf("Hash Table Is Full\n");
}

void main()
{
    FILE *fp;
    int i,key,hk;
    char name[100];

    for(i=0;i<m;i++)
        HT[i]=-1;

    fp=fopen("AMIT1.txt","r");

    while(!feof(fp))
    {
        fscanf(fp,"%d%s ",&key,name);
        hk=hash(key);

        if(HT[hk]==-1)
            HT[hk]=key;

        else
        {
            printf("Collision For Key %d\n",key);
            linearprobing(hk,key);
            printf("Collision For Key %d Resolved\n",key);
        }
    }

    printf("----------HASH TABLE----------\n");
    printf("ADDRESS\t\t\tKEY\n");
    for(i=0;i<m;i++)
        printf("%02d\t\t\t%d\n",i,HT[i]);
}