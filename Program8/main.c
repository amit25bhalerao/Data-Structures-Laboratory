#include<stdio.h>
#include<stdlib.h>

struct employee
{
    char name[20];
    char ssn[20];
    char des[20];
    char dep[20];
    char phno[20];
    char sal[20];
    struct employee* llink;
    struct employee* rlink;
};

typedef struct employee* NODE;

NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct employee));

    if(temp==NULL)
    {
        printf("Insufficient Memory\n");
        exit(0);
    }

    printf("Enter The SSN Of The Employee\n");
    scanf("%s",temp->ssn);
    printf("Enter The Name Of The Employee\n");
    scanf("%s",temp->name);
    printf("Enter The Department Of The Employee\n");
    scanf("%s",temp->dep);
    printf("Enter The Designation Of The Employee\n");
    scanf("%s",temp->des);
    printf("Enter The Salary Of The Employee\n");
    scanf("%s",temp->sal);
    printf("Enter The Phone Number Of The Employee\n");
    scanf("%s",temp->phno);

    return temp;
}

NODE insert_front(NODE first)
{
    NODE temp,sec;
    temp=getnode();

    if(first==NULL)
    {
        first=temp;
        printf("Employee Details Inserted Successfully Into The Employee Database\n");
        return first;
    }

    temp->rlink=first;
    first->llink=temp;
    first=temp;
    printf("Employee Details Inserted Successfully Into The Employee Database\n");
    return first;
}

NODE insert_rear(NODE first)
{
    NODE temp,cur;
    temp=getnode();

    if(first==NULL)
    {
        first=temp;
        printf("Employee Details Inserted Successfully Into The Employee Database\n");
        return first;
    }

    if(first->rlink==NULL)
    {
        first->rlink=temp;
        temp->llink=first;
        printf("Employee Details Inserted Successfully Into The Employee Database\n");
        return first;
    }

    cur=first;

    while(cur->rlink!=NULL)
        cur=cur->rlink;

    cur->rlink=temp;
    temp->llink=cur;
    printf("Employee Details Inserted Successfully Into The Employee Database\n");
    return first;
}

NODE delete_front(NODE first)
{
    NODE sec;

    if(first==NULL)
    {
        printf("Employee Database Is Empty\n");
        return first;
    }

    sec=first->rlink;
    printf("Employee Details Deleted Successfully\n");
    free(first);
    first=sec;
    return first;
}

NODE delete_rear(NODE first)
{
    NODE prev,cur;

    if(first==NULL)
    {
        printf("Employee Database Is Empty\n");
        return first;
    }

    cur=first;

    while(cur->rlink!=NULL)
    {
        prev = cur;
        cur = cur->rlink;
    }
    free(cur);
    prev->rlink=NULL;
    printf("Employee Details Deleted Successfull1y\n");
    return first;
}

void display(NODE first)
{
    NODE cur;

    if(first==NULL)
    {
        printf("Employee Database Is Empty\n");
        return;
    }

    cur=first;

    printf("SSN\t\tNAME\t\tDEP\t\tDESG\t\tSAL\t\tPHNO\n");
    while(cur->rlink!=NULL)
    {
        printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",cur->ssn,cur->name,cur->dep,cur->des,cur->sal,cur->phno);
        cur=cur->rlink;
    }
    printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",cur->ssn,cur->name,cur->dep,cur->des,cur->sal,cur->phno);
}

NODE queue(NODE first)
{
    printf("Inserting From Rear End\n");
    first = insert_rear(first);
    printf("Deleting From Front End\n");
    first = delete_front(first);
}

void main()
{
    NODE first = NULL;
    int choice;

    for (;;)
    {
        printf("Enter 1: Display The Employee Database\n");
        printf("Enter 2: Insert Employee Details At Front\n");
        printf("Enter 3: Insert Employee Details At Rear\n");
        printf("Enter 4: Delete Employee Details At Front\n");
        printf("Enter 5: Delete Employee Details At Rear\n");
        printf("Enter 6: Implementation Of DLL As Queue\n");
        printf("Enter 7: Exit\n");

        printf("Enter Your Choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                display(first);
                break;
            case 2:
                printf("Enter The Employee Details\n");
                first = insert_front(first);
                break;
            case 3:
                printf("Enter The Employee Details\n");
                first = insert_rear(first);
                break;
            case 4:
                first = delete_front(first);
                break;
            case 5:
                first = delete_rear(first);
                break;
            case 6:
                first=queue(first);
                break;
            case 7:
                printf("Thank You :)\n");
                exit(0);
            default:
                printf("Invalid Input Entered..Please Try Again\n");
        }
    }
}


