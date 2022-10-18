#include <stdio.h>
#include <stdlib.h>

int* a,n,pos,item,elem;

void create()
{
    int i;
    printf("Enter The Total Number Of Elements In The Array\n");
    scanf("%d",&n);

    a=(int*)calloc(n, sizeof(int));

    if(a==NULL)
    {
        printf("Insufficient Memory\n");
        exit(0);
    }

    printf("Enter %d Elements Into Array\n",n);

    for(i=0;i<n;i++)
        scanf("%d",(a+i));

    printf("Array Of %d Elements Created Successfully\n",n);
}

void display()
{
    int i;

    if(n==0)
    {
        printf("Array Is Empty\n");
        return;
    }

    printf("The Array Elements Are Displayed Below\n");

    for(i=0;i<n;i++)
        printf("%d\n",*(a+i));
}


void insert()
{
    int i;
    printf("Enter The Position At Which You Wish To Enter The Element\n");
    scanf("%d",&pos);

    if(pos<0||pos>n)
    {
        printf("Invalid Position Entered\n");
        return;
    }

    printf("Enter The Item To Be Inserted\n");
    scanf("%d",&item);

    for(i=n-1;i>=pos;i--)
        a[i+1]=a[i];

    a[pos]=item;
    n=n+1;
    printf("%d Inserted Successfully\n",item);
}

void delete()
{
    int i;
    printf("Enter The Position At Which You Wish To Delete The Element\n");
    scanf("%d",&pos);

    if(pos<0||pos>n)
    {
        printf("Invalid Position Entered\n");
        return;
    }

    elem=a[pos];
    printf("%d Deleted Successfully\n",elem);

    for(i=pos;i<n-1;i++)
        a[i]=a[i+1];

    n=n-1;

}

void main()
{
    int choice;

    for(;;)
    {
        printf("Enter 1: Create\nEnter 2: Display\nEnter 3: Insert At Specified Position\nEnter 4: Delete At Specified Position\nEnter 5: Exit\n");
        printf("Enter Your Choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: create();
                break;
            case 2: display();
                break;
            case 3: insert();
                break;
            case 4: delete();
                break;
            case 5: printf("Thank You :)\n");
                exit(0);
            default: printf("Invalid Input..Please Try Again\n");
        }
    }
}

