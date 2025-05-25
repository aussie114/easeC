#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_STACK 100

typedef enum { NUMBER, OPERATOR, PAREN_OPEN, PAREN_CLOSE } TokenType;

typedef struct {
    TokenType type;
    double value;
    char op;
} Token;

typedef struct {
    Token items[MAX_STACK];
    int top;
} Stack;

// Stack functions
void push(Stack *s, Token t) 
{
    if (s->top < MAX_STACK)
        s->items[s->top++] = t;
}

Token pop(Stack *s) 
{
    return s->items[--s->top];
}

Token peek(Stack *s) 
{
    return s->items[s->top - 1];
}

int is_empty(Stack *s) 
{
    return s->top == 0;
}

// Operator precedence
int precedence(char op) 
{
    switch (op) 
	{
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return 0;
}

// Tokenizer
int tokenize(const char *expr, Token *tokens) 
{
    int i = 0, n = 0;
    while (expr[i]) 
	{
        if (isspace(expr[i])) 
		{
            i++;
        } 
		else if (isdigit(expr[i]) || expr[i] == '.') 
		{
            char numbuf[32];
            int j = 0;
            while (isdigit(expr[i]) || expr[i] == '.')
                numbuf[j++] = expr[i++];
            numbuf[j] = '\0';
            tokens[n].type = NUMBER;
            tokens[n].value = atof(numbuf);
            n++;
        } 
		else if (strchr("+-*/", expr[i])) 
		{
            tokens[n].type = OPERATOR;
            tokens[n].op = expr[i++];
            n++;
        } 
		else if (expr[i] == '(') 
		{
            tokens[n].type = PAREN_OPEN;
            i++; n++;
        } 
		else if (expr[i] == ')') 
		{
            tokens[n].type = PAREN_CLOSE;
            i++; n++;
        } 
		else 
		{
            printf("Unknown character: %c\n", expr[i]);
            exit(1);
        }
    }
    return n;
}

// Shunting Yard (infix to postfix)
int to_postfix(Token *infix, int len, Token *postfix) 
{
    Stack op_stack = { .top = 0 };
    int j = 0;
    for (int i = 0; i < len; i++) 
	{
        Token t = infix[i];
        if (t.type == NUMBER) 
		{
            postfix[j++] = t;
        } 
		else if (t.type == OPERATOR) 
		{
            while (!is_empty(&op_stack)) 
			{
                Token top = peek(&op_stack);
                if (top.type == OPERATOR &&
                    ((precedence(t.op) < precedence(top.op)) ||
                     (precedence(t.op) == precedence(top.op)))) 
				{
                    postfix[j++] = pop(&op_stack);
                } else break;
            }
            push(&op_stack, t);
        } 
		else if (t.type == PAREN_OPEN) 
		{
            push(&op_stack, t);
        } 
		else if (t.type == PAREN_CLOSE) 
		{
            while (!is_empty(&op_stack) && peek(&op_stack).type != PAREN_OPEN)
                postfix[j++] = pop(&op_stack);
            if (is_empty(&op_stack)) 
			{
                printf("Mismatched parentheses\n");
                exit(1);
            }
            pop(&op_stack); // discard '('
        }
    }
    while (!is_empty(&op_stack)) {
        Token top = pop(&op_stack);
        if (top.type == PAREN_OPEN || top.type == PAREN_CLOSE) {
            printf("Mismatched parentheses\n");
            exit(1);
        }
        postfix[j++] = top;
    }
    return j;
}

// Evaluate postfix expression
double evaluate_postfix(Token *postfix, int len) 
{
    Stack val_stack = { .top = 0 };
    for (int i = 0; i < len; i++) 
	{
        Token t = postfix[i];
        if (t.type == NUMBER) 
		{
            push(&val_stack, t);
        } 
		else if (t.type == OPERATOR) 
		{
            Token b = pop(&val_stack);
            Token a = pop(&val_stack);
            double result = 0;
            switch (t.op) 
			{
                case '+': result = a.value + b.value; break;
                case '-': result = a.value - b.value; break;
                case '*': result = a.value * b.value; break;
                case '/': result = a.value / b.value; break;
            }
            Token res = { .type = NUMBER, .value = result };
            push(&val_stack, res);
        }
    }
    return pop(&val_stack).value;
}

// Wrapper
double eval(const char *expr) 
{
    Token tokens[MAX_TOKENS], postfix[MAX_TOKENS];
    int n = tokenize(expr, tokens);
    int m = to_postfix(tokens, n, postfix);
    return evaluate_postfix(postfix, m);
}
