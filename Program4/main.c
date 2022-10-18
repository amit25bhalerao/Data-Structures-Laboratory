#include <stdio.h>
#include <stdlib.h>

int f(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-': return 2;

        case '*':
        case '/': return 4;

        case '^':
        case '$': return 5;

        case '(': return 0;
        case '#': return -1;

        default:  return 8;
    }
}

int g(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-': return 1;

        case '*':
        case '/': return 3;

        case '^':
        case '$': return 6;

        case '(': return 9;
        case ')': return 0;

        default:  return 7;
    }
}

void infix_postfix(char infix[],char postfix[])
{
    int i,top,k;
    k=0;top=-1;
    char symbol,stack[100];

    stack[++top]='#';

    for(i=0;infix[i]!='\0';i++)
    {
        symbol=infix[i];

        while (f(stack[top])>g(symbol))
        {
            postfix[k++]=stack[top--];
        }

        if(f(stack[top])!=g(symbol))
            stack[++top]=symbol;
        else
            top--;
    }

    while(stack[top]!='#')
        postfix[k++]=stack[top--];

    postfix[k]='\0';
}


void main()
{
    char infix[100],postfix[100];

    printf("Enter The Infix Expression\n");
    scanf("%s",infix);
    infix_postfix(infix,postfix);
    printf("The Postfix Expression Is %s\n",postfix);
    exit(0);
}