#include <stdio.h>
#include <stdlib.h>

# define MAX 5

int stack[MAX],top=-1,count=0;

void push()
{
    int item;

    if(top==MAX-1)
    {
        printf("stack Overflow\n");
        return;
    }

    printf("Enter The Item To Be Inserted\n");
    scanf("%d",&item);
    ++count;
    stack[++top]=item;

    printf("%d Inserted Successfully\n",item);
}

void pop()
{
    if(top==-1)
    {
        printf("stack Underflow\n");
        return;
    }
    count--;
    printf("%d Deleted Successfully\n",stack[top--]);
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack Is Empty\n");
        return;
    }

    printf("%d Contents Of Stack Are Displayed Below\n",count);

    for(i=top;i>=0;i--)
        printf("%d\n",stack[i]);
}

void isitpal()
{
    char str[30],*stack1,elem;
    int i,top1,k=0;
    top1=-1;

    printf("Enter The String\n");
    scanf("%s",str);

    for(i=0;str[i]!='\0';i++)
        ++k;

    stack1=(char*)malloc(k* sizeof(char));

    for(i=0;str[i]!='\0';i++)
    {
        elem=str[i];
        stack1[++top1]=elem;
    }

    for(i=0;i<=top1;i++)
    {
        if(stack1[top1--]!=stack1[i])
        {
            printf("String Is Not Palindrome\n");
            return;
        }
    }

    printf("String Is Palindrome\n");
}

void main()
{
    int choice;

    for(;;)
    {
        printf("Enter 1: Push\nEnter 2: Pop\nEnter 3: Traverse\nEnter 4: Palindrome Check\nEnter 5: Exit\n");
        printf("Enter Your Choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                isitpal();
                break;
            case 5:
                printf("Thank You :)\n");
                exit(0);
            default:
                printf("Invalid Input Entered..Please Try Again\n");
        }
    }
}

