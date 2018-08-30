#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

struct stack {
    char *arr;
    int capacity;
    int top; //top index
};

struct stack* create_stack(int capacity) {
    struct stack *stack_ins = (struct stack*) malloc (sizeof(struct stack));
    if (!stack_ins) {
        return NULL;
    }
    stack_ins->arr = (char *) malloc (sizeof(char) * capacity);
    if (!stack_ins->arr) {
        return NULL;
    }
    stack_ins->capacity = capacity;
    stack_ins->top = -1; //no items   
    return stack_ins;
}

bool is_empty(struct stack *stack_ins) {
    if (stack_ins->top == -1)
        return true;
    return false;
}

bool is_full(struct stack *stack_ins) {
    if (stack_ins->top == (stack_ins->capacity - 1))
        return true;
    return false;
}

struct stack* resize_stack(struct stack *stack_ins, int capacity) {
    stack_ins->arr = (char *) realloc (stack_ins->arr, sizeof(char) * capacity);
    if (!stack_ins->arr) {           
        return NULL;
    }
    stack_ins->capacity = capacity;
    return stack_ins;
}

void push(struct stack *stack_ins, char data) {
    if (is_full(stack_ins)) { //reached MAX capacity, resize or could return error
        stack_ins = resize_stack(stack_ins, stack_ins->capacity*2);
        if (!stack_ins)
            return;
    }
    stack_ins->top++;
    stack_ins->arr[stack_ins->top] = data;
}

char pop (struct stack *stack_ins) {
    char data = CHAR_MIN;
    if (!is_empty(stack_ins)) {
        data = stack_ins->arr[stack_ins->top];
        stack_ins->top--;
    }
    return data;
}

bool is_valid(char *s) {
    if (!s) 
        return true;
    int len = strlen(s);
    if (len == 0) 
        return true;
    
    struct stack *expr_stack = NULL;
    expr_stack = create_stack(len+1);
    if (!expr_stack)
        return false; //something failed

    char c = CHAR_MIN;
    int i = 0;
    for (i = 0; i < len; ++i){
        switch(s[i]) {
            case '(':
                push(expr_stack, s[i]);
                break;
            case '[':
                push(expr_stack, s[i]);
                break;
            case '{':
                push(expr_stack, s[i]);
                break;
            case ')':
                c = pop(expr_stack);
                if (c != '(')
                    return false;
                break;
            case ']':
                c = pop(expr_stack);
                if (c != '[')
                    return false;
                break;
            case '}':
                c = pop(expr_stack);
                if (c != '{')
                    return false;
                break;
        }
    }
    if (is_empty(expr_stack))
        return true;
    else
        return false;
}

int main() {

    bool result;
    result = is_valid("");
    printf("\"\": %s\n", result? "true" : "false");

    result = is_valid("("); 
    printf("(: %s\n", result? "true" : "false");

    result = is_valid("()"); 
    printf("(): %s\n", result? "true" : "false");

    result = is_valid("]("); 
    printf("](: %s\n", result? "true" : "false");

    result = is_valid("(]"); 
    printf("(]: %s\n", result? "true" : "false");

    result = is_valid("(){}[]"); 
    printf("(){}[]: %s\n", result? "true" : "false");

    result = is_valid("(({})){[()]}"); 
    printf("(({})){[()]}: %s\n", result? "true" : "false");
}
