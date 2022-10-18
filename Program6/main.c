#include<stdio.h>
#include<stdlib.h>
# define MAX 10
int count,f,r;
char q[MAX];

void insert()
{
    char ch;
    if(count==MAX)
    {
        printf("Queue Is Full\n");
        return;
    }
    printf("Enter The Character To Be Inserted\n");
    scanf(" %c",&ch);
    r=(r+1)%MAX;
    q[r]=ch;
    printf("%c Inserted Successfully\n",q[r]);
    ++count;
}

void delete()
{
    if(count==0)
    {
        printf("Queue Is Empty\n");
        return;
    }

    printf("%c Deleted Successfully\n",q[f]);
    f=(f+1)%MAX;
    count--;
}

void display()
{
    int i;

    if(count==0)
    {
        printf("Queue Is Empty\n");
        return;
    }

    printf("Contents Of Circular Queue Are Displayed Below\n");
    if(f<r)
    {
        for(i=f;i<=r;i++)
            printf("%c ",q[i]);
    }
    else
    {
        for(i=f;i<=MAX-1;i++)
            printf("%c ",q[i]);
    }
    printf("\n");
}

void main()
{
    f=0;r=-1;
    int choice;

    for(;;)
    {
        printf("Enter 1: Insert Item Into Queue\nEnter 2: Delete Item From Queue\nEnter 3: Display Queue\nEnter 4: Exit\n");
        printf("Enter Your Choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Thank You :)\n");
                exit(0);
            default:
                printf("Invalid Input Entered..Please Try Again\n");
        }
    }
}