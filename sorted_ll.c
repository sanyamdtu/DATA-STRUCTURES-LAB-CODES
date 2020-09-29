#include <stdio.h>
#include <stdlib.h>
// using namespace std;
struct LL
{
	struct LL *node;
	int num;
};
struct LL *constr(int n)
{
	struct LL *p = (struct LL *)malloc(sizeof(struct LL));
	p->num = n;
	p->node = NULL;
	return p;
}
void show(struct LL *list)
{
	if (list->node == NULL)
	{
		return;
	}
	printf("%d->", list->num);
	show(list->node);
}

void insert(struct LL *list, int n)
{
	struct LL *cp;
	struct LL *temp = constr(n);
	if (list == NULL || list->num >= temp->num)
	{
		temp->node = list;
		list = temp;
	}
	else
	{
		cp = list;
		while (cp->node != NULL && cp->node->num < temp->num)
		{
			cp = cp->node;
		}
		temp->node = cp->node;
		cp->node = temp;
	}
}

void find(struct LL *list, int n, int i)
{
	if (list->node == NULL)
	{
		printf("num Doesn't Exists\n");
		return;
	}
	if (list->num == n)
	{
		printf("Found at%d", i);
		printf("num Exists\n");
	}
	else
	{
		find(list->node, n, i + 1);
	}
}

void dele(struct LL *list, int n)
{
	if (list->node == NULL)
	{
		printf("nothing found\n");
		return;
	}
	else
	{
		if (list->node->num == n)
		{
			list->node = list->node->node;
			return;
		}
		else
		{
			dele(list->node, n);
		}
	}
}

int count(struct LL *list)
{
	if (list->node == NULL)
		return 0;
	return 1 + count(list->node);
}

int main()
{

	struct LL *list = constr(0);

	while (1)
	{

		printf("Ennter 1 to Insert\n");
		printf(" Ennter 2 to dele\n");
		printf("Ennter 3 to count Nodes\n");
		printf(" Ennter 4 to find\n");
		printf("Ennter 5 to Print\n");
		printf("presss any other number to exit Exit\n");
		int q, n, k;
		scanf("%d", &q);
		if (q == 1)
		{
			printf("Enter Number\n");
			scanf("%d", &n);
			insert(list, n);
		}
		else if (q == 2)
		{
			printf("Enter Number \n");
			scanf("%d", &n);
			dele(list, n);
		}
		else if (q == 3)
		{
			int a = count(list);
			printf("count is  %d\n", a);
		}
		else if (q == 4)
		{
			printf("Enter Number\n");
			scanf("%d", &n);
			find(list, n, 0);
		}
		else if (q == 5)
		{
			printf("the order is this \n");
			show(list);
			printf("\n");
		}
		else
			break;
	}
	return 0;
}