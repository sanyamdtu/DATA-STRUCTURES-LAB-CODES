#include<stdio.h>
#define sz 30
struct sparse
{
	int nr,nc,nz,r[sz],c[sz],val[sz];
};
void read(struct sparse *s)
{
	scanf("%d%d%d",&s->nr,&s->nc,&s->nz);
	int i=0;
	while(i<s->nz)
	{
		scanf("%d%d%d",&s->r[i],&s->c[i],&s->val[i]);
		i++;
	}
}
void show(struct sparse s)
{
	int i=0;
	while(i<s.nz)
	{
		printf("%d %d %d\n",s.r[i],s.c[i],s.val[i]);
		i++;
	}
}
struct sparse transpose(struct sparse s)
{
	struct sparse q;
	int t[sz]={},f[sz]={};
	int i=0;
	while(i<s.nz)
	{
		f[s.c[i]]++;
		i++;
	}
	i=0;
	while(i<s.nc)
	{
		t[i+1]=t[i]+f[i];
		i++;
	}
	i=0;
	while(i<s.nz)
	{
		q.r[t[s.c[i]]]=s.c[i];
		q.c[t[s.c[i]]]=s.r[i];
		q.val[t[s.c[i]]]=s.val[i];
		t[s.c[i]]++;
		i++;
	}
	q.nz=s.nz;
	q.nr=s.nc;
	q.nc=s.nr;
	return q;
}
struct sparse add(struct sparse a,struct sparse b)
{
	struct sparse w;
	int i=0,j=0,k=0;
	while(i<a.nz&&j<b.nz)
	{
		if(a.r[i]==b.r[j]&&a.c[i]==b.c[j]&&a.val[i]+b.val[j])
		{
			printf("%d\n",k);
			w.r[k]=a.r[i];
			w.c[k]=a.c[i];
			w.val[k]=a.val[i]+b.val[j];
			i++;
			j++;
			k++;
		}
		else if(a.r[i]==b.r[j]&&a.c[i]==b.c[j]&&a.val[i]+b.val[j]==0)
		{
			i++;
			j++;
		}
		else if(a.r[i]<b.r[j]||(a.r[i]==b.r[j]&&a.c[i]<b.c[j]))
		{
			w.r[k]=a.r[i];
			w.c[k]=a.c[i];
			w.val[k]=a.val[i];
			i++;
			k++;
		}
		else
		{
			w.r[k]=b.r[j];
			w.c[k]=b.c[j];
			w.val[k]=b.val[j];
			j++;
			k++;
		}
	}
	while(i<a.nz)
	{
			w.r[k]=a.r[i];
			w.c[k]=a.c[i];
			w.val[k]=a.val[i];
			i++;
			k++;
	}
	while(j<b.nz)
	{
			w.r[k]=b.r[j];
			w.c[k]=b.c[j];
			w.val[k]=b.val[j];
			j++;
			k++;
	}
	w.nz=k;
	w.nr=a.nc;
	w.nc=w.nr;
	return w;
}
void multiply(struct sparse a,struct sparse m)
{
	struct sparse b=transpose(m);
	int res[sz][sz]={};
	int i=0,j;
	while(i<a.nz)
	{
		j=0;
		while(j<b.nz)
		{
			if(a.c[i]==b.c[j])
				res[a.r[i]][b.r[j]]+=a.val[i]*b.val[j];
			j++;
		}
		i++;
	}
	i=0;
	while(i<a.nr)
	{
		j=0;
		while(j<m.nr)
		{
			printf("%d ",res[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
int main()
{
  struct sparse s,q,w;
  read(&s);
  read(&q);
  multiply(s,q);
}