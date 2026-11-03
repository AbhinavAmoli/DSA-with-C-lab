
#include <stdio.h>
#include <string.h>

char stack[1000];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int precedence(char ch)
{
    if(ch == '^')
        return 3;

    if(ch == '*' || ch == '/')
        return 2;

    if(ch == '+' || ch == '-')
        return 1;

    return 0;
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' ||
            ch == '*' || ch == '/' || ch == '^');
}

void infixToPostfix(char infix[])
{
    int i;

    top = -1;

    for(i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        // If operand, print directly
        if((ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9'))
        {
            printf("%c", ch);
        }

        // If opening bracket
        else if(ch == '(')
        {
            push(ch);
        }

        // If closing bracket
        else if(ch == ')')
        {
            while(top != -1 && stack[top] != '(')
            {
                printf("%c", pop());
            }

            if(top != -1)
                pop();
        }

        // If operator
        else if(isOperator(ch))
        {
            while(top != -1 && stack[top] != '(' &&
                 (precedence(stack[top]) > precedence(ch) ||
                 (precedence(stack[top]) == precedence(ch)
                  && ch != '^')))
            {
                printf("%c", pop());
            }

            push(ch);
        }
    }

    // Pop remaining operators
    while(top != -1)
    {
        printf("%c", pop());
    }
}

int main()
{
    int t;
    char infix[1000];

    scanf("%d", &t);

    while(t--)
    {
        scanf("%s", infix);

        infixToPostfix(infix);

        printf("\n");
    }

    return 0;
}
