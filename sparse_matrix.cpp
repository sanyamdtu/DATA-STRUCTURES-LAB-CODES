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
	w.nr=a.nr;
	w.nc=w.nc;
	return w;
}
int main()
{
  struct sparse s,q,w;
  read(&s);
  //show(s);
  read(&q);
  //show(q);
  w=add(s,q);
  show(w);
}