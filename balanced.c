#include<stdio.h>
#include<ctype.h>

typedef struct stack
{
   char a[30];
   int top;
}stack;

void push(stack *s,char c)
{
	if(s->top>29)
	{
		printf("stack is full");
		return;
	}
	s->top++;
	s->a[s->top]=c;
}

	

char pop(stack *s)
{
	if(s->top==-1)
	{
		printf("stack is empty");
	return 0;
	}
	else
	{
		char data=s->a[s->top--];
		return data;
	}
}

int isMatchingpair(char left,char right)
{
	switch(left)
	{
		case '(':if(right==')')
		         return 1;
		         else 
		         return 0;
		case '[':if(right==']')
		         return 1;
		         else
		         return 0;
		case '{':if(right=='}')
		         return 1;
		         else
		         return 0;
		default:	 
				return 0;
	}

}

void checkcontinuity (char exp[])
{
	int i;
	char c;
	stack s;
	s.top=-1;
	for(i=0;exp[i]!='\0';i++)
	{
		 if(exp[i]=='('||exp[i]=='['||exp[i]=='{')
			push(&s,exp[i]);
		 else
		 {
			 if(s.top!=-1)
				c=pop(&s);
			 else{
				printf("invalid expression");
				return;
			}
			if(isMatchingpair(c,exp[i]))
			continue;
			else
			printf("invalid expression");
	 }
	}
		if(s.top==-1)
		printf("expression is valid");
		else
		printf("expression is invalid");
		return ;
}
	
	
			
int main()

{
	char exp[30];
	printf("\nEnter an  expression containing only parenthesis\n");
	scanf("%s",exp);
	checkcontinuity(exp);
	return 0;
	
}
	

