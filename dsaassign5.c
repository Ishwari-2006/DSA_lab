#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node for stack (char)
struct Node {
    char data;
    struct Node *next;
};

// Push
void push(struct Node **top, char val) {
    struct Node *newNode = (struct Node*)calloc(1,sizeof(struct Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Pop
char pop(struct Node **top) {
    if (*top == NULL) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    struct Node *temp = *top;
    char val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

// Peek
char peek(struct Node *top) {
    if (top == NULL) return '\0';
    return top->data;
}

// IsEmpty
int isEmpty(struct Node *top) {
    return top == NULL;
}

// Precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Infix → Postfix
void infixToPostfix(char infix[], char postfix[]) {
    struct Node *stack = NULL;
    int i, k = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if ((ch >= '0' && ch <= '9') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z')) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(&stack, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack); // remove '('
        }
        else {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(ch)) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }
    while (!isEmpty(stack)) {
        postfix[k++] = pop(&stack);
    }
    postfix[k] = '\0';
}

// Reverse a string
void reverse(char str[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Infix → Prefix
void infixToPrefix(char infix[], char prefix[]) {
    char revInfix[50], revPostfix[50];
    int i;

    // Copy infix into revInfix manually (instead of strcpy)
    for (i = 0; infix[i] != '\0'; i++) {
        revInfix[i] = infix[i];
    }
    revInfix[i] = '\0'; // terminate string

    // Step 1: Reverse
    reverse(revInfix);

    // Step 2: Swap parentheses
    for (i = 0; revInfix[i] != '\0'; i++) {
        if (revInfix[i] == '(') revInfix[i] = ')';
        else if (revInfix[i] == ')') revInfix[i] = '(';
    }

    // Step 3: Convert to Postfix
    infixToPostfix(revInfix, revPostfix);

    // Step 4: Reverse postfix to get prefix
    reverse(revPostfix);

    // Copy revPostfix into prefix manually
    for (i = 0; revPostfix[i] != '\0'; i++) {
        prefix[i] = revPostfix[i];
    }
    prefix[i] = '\0'; // terminate string
}


// Postfix Evaluation (separate int stack)
struct IntNode {
    int data;
    struct IntNode *next;
};

void pushInt(struct IntNode **top, int val) {
    struct IntNode *newNode = (struct IntNode*)calloc(1,sizeof(struct IntNode));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int popInt(struct IntNode **top) {
    if (*top == NULL) return 0;
    struct IntNode *temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int evalPostfix(char postfix[]) {
    struct IntNode *stack = NULL;
    int i, op1, op2;

    for (i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (ch >= '0' && ch <= '9') {
            pushInt(&stack, ch - '0');
        } else {
            op2 = popInt(&stack);
            op1 = popInt(&stack);

            if (ch == '+') pushInt(&stack, op1 + op2);
            else if (ch == '-') pushInt(&stack, op1 - op2);
            else if (ch == '*') pushInt(&stack, op1 * op2);
            else if (ch == '/') pushInt(&stack, op1 / op2);
        }
    }
    return popInt(&stack);
}

// Main
int main() {
    int choice;
    char infix[50], postfix[50], prefix[50];
    struct Node *stack = NULL;  // for testing Push, Pop, etc.

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push (char)\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. Display Top\n");
        printf("5. Infix to Postfix\n");
        printf("6. Infix to Prefix\n");
        printf("7. Postfix Evaluation\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char val;
                printf("Enter character to push: ");
                scanf(" %c", &val);
                push(&stack, val);
                break;
            }
            case 2: {
                char val = pop(&stack);
                if (val != '\0') printf("Popped: %c\n", val);
                break;
            }
            case 3:
                if (isEmpty(stack)) printf("Stack is empty\n");
                else printf("Stack is not empty\n");
                break;

            case 4:
                if (isEmpty(stack)) printf("Stack is empty\n");
                else printf("Top element: %c\n", peek(stack));
                break;

            case 5:
                printf("Enter Infix: ");
                scanf("%s", infix);
                infixToPostfix(infix, postfix);
                printf("Postfix: %s\n", postfix);
                break;

            case 6:
                printf("Enter Infix: ");
                scanf("%s", infix);
                infixToPrefix(infix, prefix);
                printf("Prefix: %s\n", prefix);
                break;

            case 7:
                printf("Enter Postfix: ");
                scanf("%s", postfix);
                printf("Evaluation = %d\n", evalPostfix(postfix));
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}




