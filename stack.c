#include <stdio.h>
#include <conio.h>

#define size 5   // ✅ no semicolon here

int stack[size];
int top = -1;

// Function to push
void push() {
    if (top == size - 1) {
        printf("Sorry! Stack is full.\n");
        return;
    }

    int num;
    printf("Enter a number to push: ");
    scanf("%d", &num);

    top++;
    stack[top] = num;
    printf("%d pushed to stack.\n", num);
}

// Function to pop
void pop() {
    if (top == -1) {
        printf("Sorry! Stack is empty.\n");
        return;
    }

    printf("%d popped from stack.\n", stack[top]);
    top--;
}

// Function to peek
void peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Top element is: %d\n", stack[top]);
}

// Function to display
void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choose;

    do {
        printf("\n\nEnter choice:\n1->Push\n2->Pop\n3->Peek\n4->Display\n5->Exit\n> ");
        scanf("%d", &choose);

        switch (choose) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}
