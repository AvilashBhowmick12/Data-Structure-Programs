#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct st{
char stack[50];
int top;
};

void push(struct st *,char );
void pop(struct st *);

void main()
{
    struct st s;

    char expr[50];
    int i;
    s.top=-1;
    printf("Enter a String with Parenthesis: ");
    gets(expr);

    for(i=0;expr[i]!='\0';i++)
    {
        if(expr[i]=='[' || expr[i]=='{' || expr[i]=='(')
        push(&s,expr[i]);
        else if(expr[i]==')' && s.stack[s.top]=='(')
        pop(&s);
        else if(expr[i]=='}' && s.stack[s.top]=='{')
        pop(&s);
        else if(expr[i]==']' && s.stack[s.top]=='[')
        pop(&s);
        else
        {
            printf("UnBalanced Expression\n");
            exit(0);
        }
    }
printf("Balanced Expression\n");
}

void push(struct st *ptr,char ch)
{
    ptr->stack[++ptr->top]=ch;
}

void pop(struct st *ptr)
{
    ptr->top--;
}
