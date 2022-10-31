#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 50
int top = -1;
char stack[Max];
void push (char);
char pop ();
int isEmpty ();
int isFull ();
int check_blance (char *);
int match_char (char, char);
int main () 
{
    char string[Max];
    int balanced;
    printf ("enter your algebric experssion: ");
    gets (string);
    balanced = check_balance (string);
    if (balanced == 1)
    printf ("The experssion is valid.");
    else
    printf ("The experssion is invalid");
    return 0;
}

int check_balance (char *s) 
{
    char temp;
    int i;
    for (i = 0; i < strlen (s); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        push (s[i]);
      
        if (s[i] == ')' || s[i] == '}' || s[i] == ']')
	    {
	  
            if (isEmpty ())
	        {
	            printf ("Right brackets are more than left brackets\n");
                return 1;
	        }
	        else
	        {
                temp = pop ();
                if (!match_char (temp, s[i]))
		        {
                    printf ("Mismatched brackets\n");
                    return 0;
		        }
            }
	        
	    }
    }
    if (isEmpty ())
    {
        printf ("brackets are well balanced\n");
        return 1;
    }
    else
    {
        printf ("Left brackets are more than right brackets\n");
        return 0;
    }

}

void
push (char s) 
{
    if (isFull ())
    {
        printf ("stack overflow\n");
        exit (1);
    }
    top++;
    stack[top] = s;
}

char pop () 
{
    char c;
    if (isEmpty ())
    {
        printf ("stack underflow");
        exit (1);
    }
    c = stack[top];
    top--;
    return c;
}

int isEmpty () 
{
    if (top == -1)
    return 1;
    else
    return 0;
}

int isFull () 
{
    if (top == Max - 1)
    return 1;
    else
    return 0;
}

int match_char (char a, char b) 
{
    if (a == '(' && b == ')')
    return 1;
    if (a == '{' && b == '}')
    return 1;
    if (a == '[' && b == ']')
    return 1;
    else
    return 0;
}

