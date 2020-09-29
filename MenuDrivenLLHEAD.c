#include<stdio.h>
struct node
{
    int val;
    struct node* next;
};
struct head
{
    struct node* start;
    struct node* end;
};
void InsertAtEnd(struct head* hd,int x)
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->val=x;
    temp->next=NULL;
    if(hd->start==NULL)
    {
        hd->start=temp;
        hd->end=temp;
    }
    else
        hd->end->next=temp;
}
void InsertAtFront(struct head* hd,int x)
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->val=x;
    temp->next=NULL;
    if(hd->start==NULL)
    {
        hd->start=temp;
        hd->end=temp;
    }
    else
        {
            temp->next=hd->start;
            hd->start=temp;
        }
}
void InsertAfter(struct head* hd,int x,int a)
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->val=x;
    temp->next=NULL;
    struct node *h=hd->start;
    while(h->val!=a)
        h=h->next;
    temp->next=h->next;
    h->next=temp;
}
int search(struct head h,int x)
{
    while(h.start!=NULL)
    {
        if(h.start->val==x)
            return 1;
        h.start=h.start->next;
    }
    return 0;
}
void delete(struct head* hd,int x)
{
    struct node* t=hd->start;
    if(t->val==x)
        hd->start=t->next;
    else
    {
        struct node *p=t;
        t=t->next;
        while(t->val!=x)
        {
            t=t->next;
            p=p->next;
        }
        p->next=t->next;
        free(t);
    }
}
int count(struct head h)
{
    int ans=0;
    while(h.start!=NULL)
    {
        h.start=h.start->next;
        ans++;
    }
    return ans;
}
int main()
{
    struct head hd;
    hd.start=hd.end=NULL;
    int c,x,f;
    printf("1. Insert at end\n2. Insert at front\n3. Insert after\n4.Search\n5. Delete\n6. Count\n7. Exit");
    while(1)
    {
        scanf("%d",&c);
        if(c==1)
        {
            scanf("%d",&x);
            InsertAtEnd(&hd,x);
        }
        if(c==2)
        {
            scanf("%d",&x);
            InsertAtFront(&hd,x);
        }
        if(c==3)
        {
            scanf("%d%d",&x,&f);
            InsertAfter(&hd,x,f);
        }
        if(c==4)
        {
            scanf("%d",&x);
            if(search(hd,x)>0)
                printf("Found\n");
            else
                printf("Not Found\n");
        }
        if(c==5)
        {
            scanf("%d",&x);
            delete(&hd,x);
        }
        if(c==6)
        {
            x=count(hd);
            printf("%d\n",x);
        }
        if(c==7)
            return 0;
    }
}
