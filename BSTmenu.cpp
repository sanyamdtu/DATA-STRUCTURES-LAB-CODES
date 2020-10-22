#include<stdio.h>
#include<stdlib.h>

void display_menu()
{
    printf("\n1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Preorder\n");
    printf("5. Inorder\n");
    printf("6. Postorder\n");
    printf("7. CountNodes\n");
    printf("8. Height\n");
    printf("9. Exit\n");
    return;
}

struct Node
{
 struct Node *lchild;
 int data;
 struct Node *rchild;
};

int count(struct Node *root)
{
 if(root)
 return count(root->lchild)+count(root->rchild)+1;
 return 0;
}

int Height(struct Node *p)
{
 int x,y;
 if(p==NULL)return 0;
 x=Height(p->lchild);
 y=Height(p->rchild);
 return x>y?x+1:y+1;
}

struct Node* Insert(struct Node* root,int key)
{
 struct Node *r=NULL,*p;

 if(root==NULL)
 {
 p=(struct Node *)malloc(sizeof(struct Node));
 p->data=key;
 p->lchild=p->rchild=NULL;
 root=p;
 return root;
 }
 r=root;
 while(r!=NULL)
 {
 if(key<r->data)
 {
 	if(r->lchild==NULL)
 	break;
 	else
 	r=r->lchild;
 }
 else
 {
 	if(r->rchild==NULL)
 	break;
 	else
 	r=r->rchild;
 }
 }
 
 p=(struct Node *)malloc(sizeof(struct Node));
 p->data=key;
 p->lchild=p->rchild=NULL;
 if(key<r->data) r->lchild=p;
 else r->rchild=p;
 return root;
}

struct Node *InPre(struct Node *p)
{
 while(p && p->rchild!=NULL)
 p=p->rchild;
 return p;
}

struct Node *InSucc(struct Node *p)
{
 while(p && p->lchild!=NULL)
 p=p->lchild;
 return p;
}

struct Node *Delete(struct Node *root,int key)
{
 struct Node *q;
 struct Node *p=root;

 if(p==NULL)
 return NULL;
 if(p->lchild==NULL && p->rchild==NULL)
 {
 if(p==root)
 root=NULL;
 free(p);
 return NULL;
 }

 if(key < p->data)
 p->lchild=Delete(p->lchild,key);
 else if(key > p->data)
 p->rchild=Delete(p->rchild,key);
 else
 {
 if(Height(p->lchild)>Height(p->rchild))
 {
 q=InPre(p->lchild);
 p->data=q->data;
 p->lchild=Delete(p->lchild,q->data);
 }
 else
 {
 q=InSucc(p->rchild);
 p->data=q->data;
 p->rchild=Delete(p->rchild,q->data);
 }
 }
}

struct Node * Search(struct Node *root,int key)
{
 struct Node *t=root;

 while(t!=NULL)
 {
 if(key==t->data)
 return t;
 else if(key<t->data)
 t=t->lchild;
 else
 t=t->rchild;
 }
 return NULL;
}

void Preorder(struct Node *p)
{
 if(p!=NULL)
 {
 	printf("%d ",p->data);
	Preorder(p->lchild);
	Preorder(p->rchild);
 }
}

void Inorder(struct Node *p)
{
 if(p!=NULL)
 {
 	Inorder(p->lchild);
 	printf("%d ",p->data);
 	Inorder(p->rchild);
 }
}

void Postorder(struct Node *p)
{
 if(p!=NULL)
 {
 	Postorder(p->lchild);
 	Postorder(p->rchild);
 	printf("%d ",p->data);
 }
}

int main()
{	struct Node* root=NULL;
	struct Node* temp=NULL;
	while(1)
	{
        display_menu();
        printf("Enter the option\n");
        int o;
        scanf("%d", &o);
        switch(o)
		{
            case 1:
                printf("Enter the value : ");
                int x;
                scanf("%d", &x);
                root = Insert(root, x);
                break;
            case 2:
                printf("Enter the value to be deleted : ");
                scanf("%d", &x);
                Delete(root, x);
		 		printf("element %d is deleted\n",x);
                break;
            case 3:
                printf("Enter the value to search : ");
                scanf("%d", &x);
                temp = Search(root, x);
                if(temp!=NULL)
		 		printf("element %d is found\n",temp->data);
 				else
 				printf("element is not found\n");
                break;
            case 4: Preorder(root);
                break;
            case 5: Inorder(root);
                break;
            case 6: Postorder(root);
                break;
            case 7: int y;
					y=count(root);
            		printf("Number of Nodes: %d",y);
                break;
            case 8: int z;
					z=Height(root);
            		printf("Height of the tree: %d",z);
               	break;
            case 9: exit(0);
            	break;
        }
    }
    return 0;
}
