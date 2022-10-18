#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double postfix_evaluation(char postfix[])
{
    double op1,op2,stack[100];
    int i,top=-1;
    char symbol;

    for(i=0;postfix[i]!='\0';i++)
    {
        symbol=postfix[i];

        switch(symbol)
        {
            case '+':
                op2=stack[top--];
                op1=stack[top--];
                stack[++top]=op1+op2;
                break;
            case '-':
                op2=stack[top--];
                op1=stack[top--];
                stack[++top]=op1-op2;
                break;
            case '*':
                op2=stack[top--];
                op1=stack[top--];
                stack[++top]=op1*op2;
                break;
            case '/':
                op2=stack[top--];
                op1=stack[top--];
                stack[++top]=op1/op2;
                break;
            case '^':
            case '$':
                op2=stack[top--];
                op1=stack[top--];
                stack[++top]=pow(op1,op2);
                break;
            default:
                stack[++top]=symbol-48;
        }
    }
    return stack[top];
}

void tower(int n, char source, char temp, char dest)
{
    if(n==0)
        return;
    tower(n-1,source,dest,temp);
    printf("Move %d From %c To %c\n",n,source,dest);
    tower(n-1,temp,source,dest);
}

void main()
{
    double res=0;
    char postfix[100];
    int choice,n;

    for(;;)
    {
        printf("Enter 1: Postfix Evaluation\n");
        printf("Enter 2: Tower Of Hanoi\n");
        printf("Enter 3: Exit\n");
        printf("Enter Your Choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter The Postfix Expression\n");
                scanf("%s",postfix);
                res=postfix_evaluation(postfix);
                printf("The Postfix Expression Evaluation Results In %lf\n",res);
                break;
            case 2:
                printf("Enter The Total Number Of Disks\n");
                scanf("%d",&n);
                if(n==0)
                {
                    printf("No Disks Available For Operation\n");
                    break;
                }
                tower(n,'A','B','C');
                break;
            case 3:
                printf("Thank You:)\n");
                exit(0);
            default:
                printf("Invalid Input Entered..Please Try Again\n");
        }
    }
}