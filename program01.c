#include<stdio.h>
#include<stdlib.h>
# define max 20

int top=-1,a[max];
void push (int n)
{
	if (top == max -1)
	{
		printf("stack is overflown");
		return;
	}
	else 
	{
		top++;
		a[top] = n;
		//printf("%d",top);
	}
	//printf("%d",top);
}
void pop ()
{
	int del;
	if (top == -1)
	{
		printf("stack is underflown");
		return ;
	}
	else 
	{
		del = a[top];
		top--;
	}
}
void display()
{
	int i;
	if (top == -1)
		printf("stack underflown");
	else
		for (i=0;i<=top;i++)
		printf("\t%d",a[i]);
}

int main ()
{
	//define variables
	int ch,n;
	do
	{
		printf("\nenter choice : \n");
		printf("1. push\n");
		printf("2. pop\n");
		printf("3. display\n");
		printf("4. exit\n");
		printf("enter choice :\n");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1:
			{
				printf("enter number : ");
				scanf("%d",&n);
				push(n);
				break ;
			}
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
		}
	}
	while (1);
	return 0;
}