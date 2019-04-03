#include<stdio.h>
#include<string.h>

char stack[50];
int top=-1;

void push(char );
int pop();
int print(char);

void main()
{
	int i=0,l,p=0,f,k;
	char inf[20],post[20];
	puts("ENTER=");
	gets(inf);
	l=strlen(inf);
	push('(');
	for(i=0;i<l;i++)
	{
	if (inf[i]=='(' || inf[i]=='*' || inf[i]=='/' || inf[i]=='+' || inf[i]=='-')
	{
		if (inf[i]=='(')
			push('(');
		else
		{
			while (print(stack[top])>=print(inf[i]))
			{
				post[p]=pop();
				p++;
			}
			push(inf[i]);
		}
	}
	else if(inf[i]==')')
	{
		while(stack[top]!='(')
		{
			post[p]=pop();
			p++;
		}
		pop();
	}
	else
	{
		post[p]=inf[i];
		p++;
	}
	}
	k=strlen(post)-1;
	while(k!=0)
	{
		post[p]=pop();
		p++;
	}
	k=strlen(post);
	post[k-1]='\0';
	puts(post);
}

void push(char ch)
{
	top++;
	stack[top]=ch;
}

int pop()
{
	return(stack[top--]);

}

int print(char ch)
{
	if (ch=='*' || ch=='/')
	{
	return(2);
	}
	else if(ch=='+' || ch=='-')
	{
		return(1);
	}
	else if(ch=='(')
	{
		return(0);
	}
}
