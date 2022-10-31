#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Max 100

char postfix[Max];
float stack[Max];
int top=-1;
void push(int);
int pop();

int post_eval()
    {
        int i;
        int a,b;
        for(i=0;postfix[i]!='\0';i++)
            {
                if(postfix[i]>='0' && postfix[i]<='9')
                    push(postfix[i]-'0');
                else{
                    b=pop();
                    a=pop();
                    switch(postfix[i])
                        {
                            case '+':
                                push(b+a);
                                break;
                            case '-':
                                push(a-b);
                                break;
                            case '*':
                                push(b*a);
                                break;
                            case '/':
                                push(b/a);
                                break;
                        }
                }
            }
            printf("result: %d",pop());
    }
   
void push(int data)
    {
        if(top==Max-1)
            {
                printf("stack overflow.\n");
                return;
            }
        top++;
        stack[top]=data;
    }
   
int pop()
    {
        int value;
        if(top==-1)
            {
                printf("stack underflow\n");
                exit(1);
            }
        value=stack[top];
        top--;
        return value;
    }
int main()
    {
        printf("enter the postfix expression : \n");
        gets(postfix);
        post_eval();
    }

