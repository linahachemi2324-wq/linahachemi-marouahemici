#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int data;
    struct node *next;
}Node;
typedef struct stack
{
    Node *top;
}Stack;
void initStack(Stack *s)
{
    s->top = NULL;
}
int isEmpty(Stack *s)
{
    return s->top == NULL;
}
void push(Stack *s, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}
char pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return -1; 
    }
    Node *temp = s->top;
    int poppedValue = temp->data;
    s->top = s->top->next;
    free(temp);
    return poppedValue;
}
char peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return -1; 
    }
    return s->top->data;
}
int postfix(char *exp)
    {
        Stack s;
        initStack(&s);
        for(int i=0;exp[i]!='\0';i++)
        {
            if(exp[i]>='0' && exp[i]<='9')
            {
                push(&s,exp[i]-'0');
            }
            else
            {
                int x1=pop(&s);
                int x2=pop(&s);
                switch(exp[i])
                {
                    case '+':
                        push(&s,x2+x1);
                        break;
                    case '-':
                        push(&s,x2-x1);
                        break;
                    case '*':
                        push(&s,x2*x1);
                        break;
                    case '/':
                        push(&s,x2/x1);
                        break;
                }
            }
        }
        return pop(&s);
    }

 int main()
    {
        Stack s;
        initStack(&s);
        push(&s,10);
        push(&s,22);
        push(&s,33);
        printf("%d\n",peek(&s));
        printf("%d\n",pop(&s));
        printf("%d\n",peek(&s));
          char expr[] = "63+2*4/"; 
        printf("Postfix result: %d\n", postfix(expr));
        return 0;

    }