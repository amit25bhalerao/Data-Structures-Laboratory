#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int c,px,py,pz;
    struct node* link;
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

    return temp;
}

void display(NODE head)
{
    NODE cur;

    if(head->link==head)
    {
        printf("There Is Nothing To Display\n");
        return;
    }

    cur=head->link;

    while(cur!=head)
    {
        if(cur->c>=0)
            printf("+%dx^%dy^%dz^%d ",cur->c,cur->px,cur->py,cur->pz);
        else
            printf("%dx^%dy^%dz^%d ",cur->c,cur->px,cur->py,cur->pz);

        cur =cur->link;
    }
    printf("\n");
}

NODE insert_rear(int c, int px, int py, int pz, NODE head)
{
   NODE temp,cur;
   temp=getnode();

   temp->c=c;
   temp->px=px;
   temp->py=py;
   temp->pz=pz;

   cur=head->link;

   while(cur->link!=head)
       cur=cur->link;

   cur->link=temp;
   temp->link=head;
   return head;
}

NODE read_poly(NODE head)
{
    int i,px,py,pz,c,n;

    printf("Enter The Total Terms In The Polynomial\n");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        printf("Enter The Coefficient\n");
        scanf("%d",&c);
        printf("Enter The Power Of X\n");
        scanf("%d",&px);
        printf("Enter The Power Of Y\n");
        scanf("%d",&py);
        printf("Enter The Power Of Z\n");
        scanf("%d",&pz);
        head=insert_rear(c,px,py,pz,head);
    }
    return head;
}

NODE search(int px, int py, int pz, NODE head)
{
    NODE cur;
    cur=head->link;

    if(head->link==head)
        return head;

    while(cur!=head)
    {
        if((cur->px==px)&&(cur->py==py)&&(cur->pz==pz))
            break;
        cur=cur->link;
    }
    return cur;
}

NODE addpoly(NODE h1, NODE h2, NODE h3)
{
    int sum=0;
    NODE c1, c2;
    c1 = h1->link;
    c2 = h2->link;

    while (c1 != h1)
    {
        c2=search(c1->px,c1->py,c1->pz,h2);

        if(c2==h2)
            h3=insert_rear(c1->c,c1->px,c1->py,c1->pz,h3);

        else
        {
            sum=c1->c+c2->c;
            if(sum!=0)
                h3=insert_rear(sum,c1->px,c1->py,c1->pz,h3);

            c2->c=9999;
        }

        c1=c1->link;
    }

    while(c2!=h2)
    {
        if(c2->c!=9999)
            h3=insert_rear(c2->c,c2->px,c2->py,c2->pz,h3);

        c2=c2->link;
    }

    return h3;
}

double eval(NODE head)
{
    int x,y,z;
    NODE cur;
    double sum=0;

    if(head->link==head)
        return 0;

    printf("Enter The Value Of X\n");
    scanf("%d",&x);
    printf("Enter The Value Of Y\n");
    scanf("%d",&y);
    printf("Enter The Value Of Z\n");
    scanf("%d",&z);

    cur=head->link;

    while(cur!=head)
    {
        sum=sum+(cur->c*(pow(x,cur->px))*(pow(y,cur->py))*(pow(z,cur->pz)));
        cur=cur->link;
    }

    return sum;
}

void main()
{
    double res;
    NODE h1,h2,h3;

    h1=getnode();
    h1->link=h1;

    h2=getnode();
    h2->link=h2;

    h3=getnode();
    h3->link=h3;

    printf("Enter First Polynomial\n");
    read_poly(h1);

    printf("Enter Second Polynomial\n");
    read_poly(h2);

    printf("Polynomial One And Polynomial 2 Are Displayed Below\n");
    display(h1);
    display(h2);

    addpoly(h1,h2,h3);

    printf("The Addition Of Above Two Polynomial Results In\n");
    display(h3);

    printf("Evaluation Of Polynomial Results In\n");
    res=eval(h3);
    printf("%lf",res);
}