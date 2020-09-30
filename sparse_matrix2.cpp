#include <iostream>
#include <stdio.h>
#define sz 11
struct m
{
	int nr, nc, nz, r[sz], c[sz], val[sz];
};
void read(struct m *s)
{
	scanf("%d%d%d", &s->nr, &s->nc, &s->nz);
	int i = 0;
	printf("Enter row column no. order respctively\n");
	while (i < s->nz)
	{
		scanf("%d%d%d", &s->r[i], &s->c[i], &s->val[i]);
		if (s->r[i] > s->nr || s->c[i] > s->nc)
		{
			printf("Enter Coreectly \n");
			scanf("%d%d%d", &s->r[i], &s->c[i], &s->val[i]);
		}
		i++;
	}
}
void show(struct m s)
{
	int i = 0;
	while (i < s.nz)
	{
		printf(" %d %d %d \n", s.r[i], s.c[i], s.val[i]);
		i++;
	}
}
struct m tra(struct m s)
{
	struct m extre;
	int t[sz] = {}, f[sz] = {};
	int i = 0;
	while (i < s.nz)
	{
		f[s.c[i]]++;
		i++;
	}
	i = 0;
	while (i < s.nc)
	{
		t[i + 1] = t[i] + f[i];
		i++;
	}
	i = 0;
	while (i < s.nz)
	{
		extre.r[t[s.c[i]]] = s.c[i];
		extre.c[t[s.c[i]]] = s.r[i];
		extre.val[t[s.c[i]]] = s.val[i];
		t[s.c[i]]++;
		i++;
	}
	extre.nz = s.nz;
	extre.nr = s.nc;
	extre.nc = s.nr;
	return extre;
}

void multiply(struct m a, struct m m)
{
	struct m matrix2 = tra(m);
	int res[sz][sz] = {};
	int i = 0, j;
	while (i < a.nz)
	{
		j = 0;
		while (j < matrix2.nz)
		{
			if (a.c[i] == matrix2.c[j])
				res[a.r[i]][matrix2.r[j]] += a.val[i] * matrix2.val[j];
			j++;
		}
		i++;
	}
	i = 0;
	while (i < a.nr)
	{
		j = 0;
		while (j < m.nc)
		{
			printf("%d ", res[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
int main()
{
	struct m s, extre, w;
	printf(" no. of rows,col and num of 1 m.\n");
	read(&s);
	printf(" no. of rows,col and num of 2 m.\n");
	read(&extre);
	w = tra(s);
	printf(" transpos 1 is : \n");
	show(w);
	w = tra(extre);
	printf("transpos  1 is : \n");
	show(w);
	printf("answer (m1 X m2) is : \n");
	multiply(s, extre);
}