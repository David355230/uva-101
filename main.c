#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void robot(char [],char [],int [][25],int,int,int);
void put(int,int [][25],int,int *,int *);
int search (int,int,int [][25],int);

int main()
{
	int n;
	scanf("%d",&n);
	char str[100],str1[100];
	int stack[n][25];//initial setup
	int i,j,a,b;
	for(i=0;i<n;i++)
	{
		stack[i][0]=i;
		for(j=1;j<n;j++)
		{
			stack[i][j]=-1;
		}
	}
    scanf("%s",&str);
	while(strcmp(str,"quit")!=0)
	{
		scanf("%d",&a);
		scanf("%s",&str1);
		scanf("%d",&b);
		robot(str,str1,stack,n,a,b);
		scanf("%s",&str);
	}
	for(i=0;i<n;i++)
	{
		printf("%d:",i);
		j=0;
		while(stack[i][j]!=-1)
		{
			printf(" ");
			printf("%d",stack[i][j]);
			if(stack[i][j+1]==-1)
			break;
			j++;
		}
		printf("\n");
	}
	return 0;
}

void robot(char str[],char str1[],int stack[][25],int n,int a,int b)
{
	int i,j,k1,k2,k3,k4,temprow,tempcol,temprow1,tempcol1;
	if(search(a,b,stack,n)!=-1)
	{
		if(strcmp(str,"move")==0&&strcmp(str1,"onto")==0)
	{
		put(a,stack,n,&k1,&k2);
		put(b,stack,n,&k3,&k4);
		stack[k1][k2]=-1;//a放到b上 
		stack[k3][k4+1]=a;
	}
	
    if(strcmp(str,"move")==0&&strcmp(str1,"over")==0)
	{
		put(a,stack,n,&k1,&k2);
		stack[k1][k2]=-1;//a放到含有b stack上 
	    for(i=0;i<n;i++)//找b位置 
	    {
		    for(j=0;j<n;j++)
		    {
			   if(stack[i][j]==b)
			   {
				temprow=i;
				tempcol=j;
			   }
		    }
	    }
	    while(stack[temprow][tempcol]!=-1)
	    {
	    	tempcol++;
	    	if(temprow==n||tempcol==n)
	    	break;
		}
	    stack[temprow][tempcol]=a;
	}
	
     if(strcmp(str,"pile")==0&&strcmp(str1,"onto")==0)
	{
		put(b,stack,n,&k1,&k2);
		for(i=0;i<n;i++)//找a位置 
	    {
		    for(j=0;j<n;j++)
		    {
			   if(stack[i][j]==a)
			   {
				temprow=i;
				tempcol=j;
			   }
		    }
	    }
	    while(stack[temprow][tempcol]!=-1)
	    {
	    	stack[k1][k2+1]=stack[temprow][tempcol];
	    	stack[temprow][tempcol]=-1;
	    	k2++;
	    	tempcol++;
	    	if(temprow==n||tempcol==n)
	    	break;
		}
	}
	
    if(strcmp(str,"pile")==0&&strcmp(str1,"over")==0)
	{
		for(i=0;i<n;i++)//找a,b位置 
	    {
		    for(j=0;j<n;j++)
		    {
			   if(stack[i][j]==a)
			   {
				temprow=i;
				tempcol=j;
			   }
			   if(stack[i][j]==b)
			   {
			   	temprow1=i;
				tempcol1=j;
			   }
			   
		    }
	    }
	    
	    while(stack[temprow1][tempcol1]!=-1)
	    {
	    	tempcol1++;
	    	if(temprow1==n||tempcol1==n)
	    	break;
		}
	    
	    while(stack[temprow][tempcol]!=-1)
	    {
	    	stack[temprow1][tempcol1]=stack[temprow][tempcol];
	    	stack[temprow][tempcol]=-1;
	    	tempcol1++;
	    	tempcol++;
	    	if(temprow==n||tempcol==n)
	    	break;
		}
	}

	}
	
}

void put(int num,int stack[][25],int n,int *k1,int *k2)
{
	int temprow,tempcol,temp,i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(stack[i][j]==num)
			{
				temprow=i;
				tempcol=j;
			}
		}
	}
	*k1=temprow;
	*k2=tempcol;
	for(i=tempcol+1;i<n;i++)
	{
	    if(stack[temprow][i]==-1)
	    break;
		else
		{
			j=0;
			temp=stack[temprow][i];
			stack[temprow][i]=-1;
			while(stack[temp][j]!=-1)
			{
				j++;
				if(j==n)
				break;
			}
			stack[temp][j]=temp;
		}
	}
}

int search (int a,int b,int stack [][25],int n)
{
	int i,j,temprow,tempcol,temprow1,tempcol1;
	for(i=0;i<n;i++)//找a,b位置 
	    {
		    for(j=0;j<n;j++)
		    {
			   if(stack[i][j]==a)
			   {
				temprow=i;
				tempcol=j;
			   }
			   if(stack[i][j]==b)
			   {
			   	temprow1=i;
				tempcol1=j;
			   }
			   
		    }
	    }
	if(temprow==temprow1)
	return -1;
	else
	return 1;
}
