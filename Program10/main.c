#include <stdio.h>
#include <stdlib.h>

int item;

struct node
{
    int info;
    struct node* llink;
    struct node* rlink;
};

typedef struct node* NODE;

NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));

    if(temp==NULL)
    {
        printf("Insufficient Memory\n");
        exit(0);
    }

    printf("Enter The Node To Be Inserted\n");
    scanf("%d",&item);
    temp->info=item;

    return temp;
}

void inorder(NODE root)
{
    if(root==NULL)
        return;
    inorder(root->llink);
    printf("%d\n",root->info);
    inorder(root->rlink);
}

void preorder(NODE root)
{
    if(root==NULL)
        return;
    printf("%d\n",root->info);
    inorder(root->llink);
    inorder(root->rlink);
}

void postorder(NODE root)
{
    if(root==NULL)
        return;
    inorder(root->llink);
    inorder(root->rlink);
    printf("%d\n",root->info);
}

NODE create(NODE root)
{
    NODE temp,cur,prev;
    temp=getnode();
    temp->llink=temp->rlink=NULL;

    if(root==NULL)
    {
        root=temp;
        printf("%d Node Created\n",item);
        return root;
    }

    cur=root;

    while(cur)
    {
        prev=cur;
        if(item<cur->info)
            cur=cur->llink;
        else
            cur=cur->rlink;
    }

    if(item<prev->info)
        prev->llink=temp;
    else
        prev->rlink=temp;

    printf("%d Node Created\n",item);

    return root;
}

void search(NODE root)
{
    int se;
    NODE cur;

    printf("Enter The Node To Be Searched\n");
    scanf("%d",&se);

    if(root==NULL)
    {
        printf("%d Node Not Found\n",se);
        return;
    }

    cur=root;

    while(cur)
    {
        if(se==cur->info)
            break;
        if(se<cur->info)
            cur=cur->llink;
        else
            cur=cur->rlink;
    }

    if(cur==NULL)
    {
        printf("%d Node Not Found\n",se);
        return;
    }

    printf("%d Node Found\n",se);
}

void main()
{
    NODE root;
    int choice;
    root=NULL;

    for(;;)
    {
        printf("Enter 1: Insert Node Into Binary Tree\n");
        printf("Enter 2: In Order Display Of Binary Tree\n");
        printf("Enter 3: Pre Order Display Of Binary Tree\n");
        printf("Enter 4: Post Order Display Of Binary Tree\n");
        printf("Enter 5: Search For An Item In The Binary Tree\n");
        printf("Enter 6: Exit\n");

        printf("Enter Your Choice\n");
        scanf("%d",& choice);

        switch(choice)
        {
            case 1:
                root=create(root);
                break;
            case 2:
                if(root==NULL)
                {
                    printf("Empty Tree\n");
                    break;
                }
                inorder(root);
                break;
            case 3:
                if(root==NULL)
                {
                    printf("Empty Tree\n");
                    break;
                }
                preorder(root);
                break;
            case 4:
                if(root==NULL)
                {
                    printf("Empty Tree\n");
                    break;
                }
                postorder(root);
                break;
            case 5:
                search(root);
                break;
            case 6:
                printf("Thank You\n");
                exit(0);
            default:
                printf("Invalid Input Entered...Please Try Again\n");
        }
    }
}

