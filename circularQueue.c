#include<stdio.h>

#define size 5

int queue[size];
int front= -1;
int rear= -1;

void enqueue(){

    int num;
    printf("Enter a number to push: ");
    scanf("%d", &num);

    if(front== -1  && rear== -1){ // first enqueue;
        front++;
        rear++; 

        queue[rear]= num;
    }

    else if((rear+1)%size == front){  // important condition to remember
        printf("queue is full");
    }
    else{
        rear= (rear+1)%size;
        queue[rear]= num;
    }
}

void dequeue(){

    if(rear== -1 && front== -1){
        printf("queue is empty");
        return;
    }

    else if(front==rear){

        front= (front+1)%size ;
        return;
    }

    else {
        printf("the pop element is %d",queue[front]);
        front= (front+1)%size ;
     return;
    }

}

void peek(){

   if(front== -1 && rear== -1){
    printf("the queue is empty");
    return;
   }

   else{ 
    printf("the front is %d", queue[front]);
  return;
   }
}

void display(){

   if(front== -1 && rear== -1){
    printf("the queue is empty");
    return;
   }
   else{

    int i= 0;
    while(i!=rear){
        printf("%d ",queue[i]);

       i= (i+1)%size;
    }
    printf("%d", queue[rear]);
   }
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
