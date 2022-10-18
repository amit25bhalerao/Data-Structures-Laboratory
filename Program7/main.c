#include <stdio.h>
#include <stdlib.h>

struct student
{
    char usn[30];
    char name[30];
    char sem[30];
    char branch[30];
    char phno[30];
    struct student* link;
};

typedef struct student* NODE;

NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct student));

    if(temp==NULL)
    {
        printf("Insufficient Memory\n");
        exit(0);
    }

    printf("Enter The Usn Of The Student\n");
    scanf("%s",temp->usn);
    printf("Enter The Name Of The Student\n");
    scanf("%s",temp->name);
    printf("Enter The Semester In Which Student Is Studying\n");
    scanf("%s",temp->sem);
    printf("Enter The Branch In Which Student Is Studying\n");
    scanf("%s",temp->branch);
    printf("Enter The Phone Number Of The Student\n");
    scanf("%s",temp->phno);
    temp->link=NULL;
    return temp;
}

NODE insert_front(NODE first)
{
    NODE temp;
    temp=getnode();

    if(first==NULL)
    {
        first=temp;
        printf("Student Details Entered Successfully\n");
        return first;
    }
    temp->link=first;
    first=temp;
    printf("Student Details Entered Successfully\n");
    return first;
}

NODE insert_rear(NODE first)
{
    NODE temp,cur;
    temp=getnode();

    if(first==NULL)
    {
        first=temp;
        printf("Student Details Entered Successfully\n");
        return first;
    }

    if(first->link==NULL)
    {
        first->link=temp;
        printf("Student Details Entered Successfully\n");
        return first;
    }

    cur=first;

    while(cur->link!=NULL)
        cur=cur->link;

    cur->link=temp;
    printf("Student Details Entered Successfully\n");
    return first;
}

NODE delete_front(NODE first)
{
    NODE sec;

    if(first==NULL)
    {
        printf("Student Database Is Empty\n");
        return first;
    }

    if(first->link==NULL)
    {
        free(first);
        printf("Student Details Deleted Successfully\n");
        return NULL;
    }

    sec=first->link;
    free(first);
    first=sec;
    printf("Student Details Deleted Successfully\n");
    return first;
}

NODE delete_rear(NODE first)
{
    NODE cur,prev;

    if(first==NULL)
    {
        printf("Student Database Is Empty\n");
        return first;
    }

    if(first->link==NULL)
    {
        free(first);
        printf("Student Details Deleted Successfully\n");
        return NULL;
    }

    cur=first;

    while(cur->link!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }

    prev->link=NULL;
    free(cur);
    printf("Student Details Deleted Successfully\n");
    return first;
}

void display(NODE first)
{
    NODE cur;
    if(first==NULL)
    {
        printf("Student Database Is Empty\n");
        return;
    }
    cur=first;

    printf("USN\t\tNAME\t\tSEM\t\tBNC\t\tPHNO\n");
    while(cur->link!=NULL)
    {
        printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n",cur->usn,cur->name,cur->sem,cur->branch,cur->phno);
        cur=cur->link;
    }
    printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n",cur->usn,cur->name,cur->sem,cur->branch,cur->phno);
}

void main()
{
    NODE first;
    first=NULL;
    int choice;

    while (1)
    {
        printf("Enter 1: Display\n");
        printf("Enter 2: Insert Student Details At Front\n");
        printf("Enter 3: Insert Student Details At Rear\n");
        printf("Enter 4: Delete Student Detail At Front\n");
        printf("Enter 5: Delete Student Detail At Rear\n");
        printf("Enter 6: Exit\n");
        printf("Enter Your Choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                display(first);
                break;
            case 2:
                printf("Enter The Student Details\n");
                first=insert_front(first);
                break;
            case 3:
                printf("Enter The Student Details\n");
                first=insert_rear(first);
                break;
            case 4:
                first=delete_front(first);
                break;
            case 5:
                first=delete_rear(first);
                break;
            case 6:
                printf("Thank you :) :)\n");
                exit(0);
            default:
                printf("Invalid Input..Please Try Again :( :( \n");
        }
    }
}

