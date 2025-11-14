#include<stdio.h>

#define size 5

int queue[size];
int front= -1;
int rear= -1;

void enqueue(){

    if(rear == size - 1){
        printf("Queue is full!\n");
        return;
    }

    int num;
    printf("Enter a number to push: ");
    scanf("%d", &num);

    if(front == -1 && rear == -1){
        front = rear = 0;
    }
    else{
        rear++;
    }

    queue[rear] = num;
}

void dequeue(){

    if(front == -1 && rear == -1){
        printf("Underflow condition!\n");
        return;
    }

    // Only 1 element
    if(front == rear){
        printf("Element %d is deleted\n", queue[front]);
        front = rear = -1;
        return;
    }

    // Normal delete
    printf("Element %d is deleted\n", queue[front]);
    front++;
}

void peek(){

    if(front == -1){
        printf("The queue is empty\n");
        return;
    }

    printf("The front element is %d\n", queue[front]);
}

void display(){

    if(front == -1){
        printf("The queue is empty\n");
        return;
    }

    for(int i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(){

    int choose;
    do {
        printf("\nEnter choice:\n1->Enqueue\n2->Dequeue\n3->Peek\n4->Display\n5->Exit\n> ");
        scanf("%d", &choose);

        switch (choose) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}
