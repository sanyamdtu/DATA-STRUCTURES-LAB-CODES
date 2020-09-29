#include <iostream>
#include <stdio.h>
#define sz 30
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
struct m transpose(struct m s)
{
	struct m q;
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
		q.r[t[s.c[i]]] = s.c[i];
		q.c[t[s.c[i]]] = s.r[i];
		q.val[t[s.c[i]]] = s.val[i];
		t[s.c[i]]++;
		i++;
	}
	q.nz = s.nz;
	q.nr = s.nc;
	q.nc = s.nr;
	return q;
}
struct m add(struct m matrix1, struct m matrix2)
{
	struct m w;
	int i = 0, j = 0, k = 0;
	while (i < matrix1.nz && j < matrix2.nz)
	{
		if (matrix1.r[i] == matrix2.r[j] && matrix1.c[i] == matrix2.c[j] && matrix1.val[i] + matrix2.val[j])
		{
			printf("%d \n", k);
			w.r[k] = matrix1.r[i];
			w.c[k] = matrix1.c[i];
			w.val[k] = matrix1.val[i] + matrix2.val[j];
			i++;
			j++;
			k++;
		}
		else if (matrix1.r[i] == matrix2.r[j] && matrix1.c[i] == matrix2.c[j] && matrix1.val[i] + matrix2.val[j] == 0)
		{
			i++;
			j++;
		}
		else if (matrix1.r[i] < matrix2.r[j] || (matrix1.r[i] == matrix2.r[j] && matrix1.c[i] < matrix2.c[j]))
		{
			w.r[k] = matrix1.r[i];
			w.c[k] = matrix1.c[i];
			w.val[k] = matrix1.val[i];
			i++;
			k++;
		}
		else
		{
			w.r[k] = matrix2.r[j];
			w.c[k] = matrix2.c[j];
			w.val[k] = matrix2.val[j];
			j++;
			k++;
		}
	}
	while (i < matrix1.nz)
	{
		w.r[k] = matrix1.r[i];
		w.c[k] = matrix1.c[i];
		w.val[k] = matrix1.val[i];
		i++;
		k++;
	}
	while (j < matrix2.nz)
	{
		w.r[k] = matrix2.r[j];
		w.c[k] = matrix2.c[j];
		w.val[k] = matrix2.val[j];
		j++;
		k++;
	}
	w.nz = k;
	w.nr = matrix1.nc;
	w.nc = w.nr;
	return w;
}
void multiply(struct m a, struct m m)
{
	struct m matrix2 = transpose(m);
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
	struct m s, q, w;
	printf("Enter the no. of rows,coloumn and values of 1 matrix.\n");
	read(&s);
	printf("Enter the no. of rows,coloumn and values of 2 matrix.\n");
	read(&q);
	w = transpose(s);
	printf("m1 Transpose  is : \n");
	show(w);
	w = transpose(q);
	printf("m2 Transpose  is : \n");
	show(w);
	printf("Matrix after multiplication : \n");
	multiply(s, q);
}