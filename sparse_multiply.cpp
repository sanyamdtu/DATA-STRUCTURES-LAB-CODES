#include<iostream>
#include<stdio.h>
#define size 50
struct sparse
{
	int nr,nc,nz,r[size],c[size],val[size];
};
void read(struct sparse *s)
{
	scanf("%d%d%d",&s->nr,&s->nc,&s->nz);
	int i=0;
	printf("Enter the elements\n");
	while(i<s->nz)
	{
		scanf("%d%d%d",&s->r[i],&s->c[i],&s->val[i]);
		if(s->r[i]>=s->nr || s->c[i]>=s->nc){
			printf("Wrong row or coloumn. Enter again.\n");
			scanf("%d%d%d",&s->r[i],&s->c[i],&s->val[i]);
		}		
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
	int t[size]={},f[size]={};
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
	int res[size][size]={};
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

void display(struct sparse s)
{ int i,j,k=0;
  

    for(i=0;i<s.nr;i++)
      {
	  for(j=0;j<s.nc;j++)
       { 
          if( s.c[k]==j && s.r[k]==i)
              {
			   printf("%d ",s.val[k]);
               k++;
              }
          else
              printf("0 ");
	   }
	  printf("\n");
  
}
}
int main()
{
  struct sparse s,q,w;
  printf("Enter the number of rows,coloumn and values of 1 matrix.\n");
  read(&s);
  printf("Enter the number of rows,coloumn and values of 2 matrix.\n");
  read(&q);
  w=transpose(s);
  printf("Transpose of 1st matrix is : \n");
  display(w);
  w=transpose(q);
  printf("Transpose of 2nd matrix is : \n");
  display(w);
  printf("Matrix after multiplication : \n");
  multiply(s,q);
}
