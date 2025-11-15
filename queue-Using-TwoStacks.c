#include<stdio.h>

#define size 5

int stack1[size];
int stack2[size];

int top1= -1;
int top2= -1;

int count= 0;

void push1(int data){ //stack1 push

    if(top1==size-1){
        printf("the queue is full: overload condition");
        return;
    }
    else{
        top1++;
        stack1[top1]= data;
        count++; 
        return;
    }
}

void push2(int data){  // stack2 push
     
    if(top2==size-1){
        printf("the stack2 is full: overload condition");
        return;
    }
    else{
        top2++;
        stack2[top2]= data;
        return;
    }
}

void pop1(){  //stack1 pop --> move all stack1 items to stack2

    if(top1==-1){
        printf("the queue is empty");
        return;
    } 
    else{
        while(top1 != -1){
            push2(stack1[top1]);
            top1--;
        }
    }
}

void pop2(){ //stack2 pop --> remove one item from stack2, then move others back

    if(top2 == -1){
        printf("the queue is empty");
        return;
    }

    // remove front element
    top2--;

    // move remaining elements back to stack1
    while(top2 != -1){
        push1(stack2[top2]);
        top2--;
    }
}

void enqueue(){

    int num;
    printf("Enter a number to push: ");
    scanf("%d",&num);

    push1(num);
}

void dequeue(){

    pop1();
    pop2();
}

void peek(){
    if(top1==-1){
        printf("The queue is empty");
        return;
    }
    printf("%d",stack1[0]);  // front element is at index 0
}

void display(){

    if(top1==-1){
        printf("the queue is empty");
        return;
    }
    for(int k= 0; k<=top1; k++){
        printf("%d ",stack1[k]);
    }
    return;
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
