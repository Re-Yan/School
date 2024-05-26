#include <stdio.h>
#include <stdlib.h>

//Declared Globally for usage among all Functions
int top, bottom, front, rear;

//Stack Function Prototypes
void stackFunction(void);
void push(int num, int stkSize, int *stack);
void pop(int stkSize, int *stack);
void display(int *stack);
void clearScreen(void);

//Queue Function Prototypes
void queueFunction(void);
void enqueue(int num, int qSize, int *queue);
void dequeue(int *queue, int qSize);
void displayQueue(int *queue);
void clearScreen(void);

int main(){
    int dataStructure;

    while(1){
        printf("\n\n1. STACK \n");
        printf("2. QUEUE\n\n");
        printf("Choose Which Data Structure to use: ");
        scanf("%d", &dataStructure);

        switch (dataStructure)
        {
        case 1:
            stackFunction();
            break;
        case 2:
            queueFunction();
            break;
        default:
            clearScreen();
            printf("Invalid Choice. Please select an option from 1 to 2:");
            break;
        }
    }

    return 0;
}


        //Stack Function Declarations


void stackFunction(void){
    int stkSize;
    int option;
    int num;
    top = -1;
    bottom = -1;

    clearScreen();
    printf("Enter the size of the Stack: ");
    scanf("%d", &stkSize);

    int *stack = (int*)malloc(stkSize * sizeof(int));       //array implementation is a pointer since we will use malloc

    while(1){
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. Display\n");
        printf("5. IsEmpty\n");
        printf("6. Exit\n");
        printf("\nChoose which operation to use (TYPE THE NUMBER): ");
        scanf("%d", &option);
    
        switch (option)
        {
        case 1:
            clearScreen();
            printf("Enter the value you wish to add in the Stack: ");
            scanf("%d", &num);
            push(num, stkSize, stack);
            break;
        case 2:
            clearScreen();
            pop(stkSize, stack);
            break;
        case 3:
            clearScreen();
            printf("\nValue at the Top Stack: %d \n\n", stack[top]);
            break;
        case 4:
            clearScreen();
            display(stack);
            break;
        case 5:
            clearScreen();
            if(top < 0 && bottom < 0){      //Empty Stack
                printf("\nThe stack is EMPTY");
            }else{
                printf("\nThe Stack is NOT EMPTY\n");
                printf("It currently has %d/%d entries in the Stack", top+1, stkSize);
            }
            break;
        case 6:
            clearScreen();
            exit(1);
        default:
            clearScreen();
            printf("\nERROR: Invalid Choice. Please select a valid number from 1 - 6:\n");
            break;
        }
    }
}

void push(int num, int stkSize, int *stack){
    if(top == (stkSize-1)){     //if stack is full
        printf("\nSTACK OVERFLOW: Cannot push a FULL stack\n");
        printf("Select (2)Pop from the Operations Menu to delete an entry from the Stack\n\n");
    }else if(top < 0 && bottom < 0){    //if stack is empty
        top = 0;
        bottom = 0;
        stack[top] = num;
    }else{          //if stack has content but is not full
        top++;
        stack[top] = num;
    }
}

void pop(int stkSize, int *stack){
    if(top < 0 && bottom < 0){     // if stack is empty
        printf("\n\nSTACK UNDERFLOW: Cannot pop from an empty Stack\n");
        printf("Select (1)Push from the Operations Menu to insert an entry into the Stack\n\n");
    }else if(top == bottom){        //if the stack has only 1 entry
        stack[top] = stack[0];
        top = -1;                    // no more existing entries in the stack. STACK IS NOW EMPTY
        bottom = -1;
        printf("\nPopped Last Entry. STACK IS NOW EMPTY\n\n");
    }else{                          //if stack has more than 1 entry
        stack[top] = stack[top-1];
        top--;
        printf("\nAn Entry Has been Removed\n");
        printf("Current Entries in the Stack: %d/%d \n\n", (top+1), stkSize);
    }
}

void display(int *stack){
    if(top < 0 && bottom < 0){
        printf("\nStack is currently EMPTY. No values to DISPLAY\n\n");
    }else{
    printf("\nAll Values Currently in the Stack: \n\n");
    for(int i = top; i >= bottom; i--){
        printf("\n\t%d", stack[i]); printf("\n\n\tv\n"); 
    } 
    }
}


        //Queue Function Declarations

void queueFunction(void){
    front = -1;     //starting value is -1 to define that it still doesnt exist in the queue
    rear = -1;

    int qSize;
    int value;
    int choice;
    int *queue;     //array declaration is a pointer since we will be allocating memory using malloc

    clearScreen();
    printf("Enter the size of the Queue: ");
    scanf("%d", &qSize);

    queue = (int*)malloc(qSize * sizeof(int));      //dynamically allocates memory based on the user's input (qSize)

    while(1){
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek \n");
        printf("5. IsEmpty\n");
        printf("6. IsFull\n");
        printf("7. Exit \n");
        printf("\nChoose which operation to use (TYPE THE NUMBER): ");
        scanf("%d", &choice);
        
        switch (choice){
            case 1:
                clearScreen();
                printf("Enter the value you wish to add in the queue: ");
                scanf("%d", &value);
                enqueue(value, qSize, queue);
                break;
            case 2:
                clearScreen();
                dequeue(queue, qSize);
                break;
            case 3:
                clearScreen();
                if(front == -1 && rear == -1){
                    printf("\nQueue is currently EMPTY. Please add a value first\n");
                    break;
                }else {
                    displayQueue(queue);
                    break;
                }
            case 4:
                clearScreen();
                if(front < 0 && rear < 0){
                    printf("Queue is EMPTY. FRONT and REAR values currently does not exist.");
                } 
                else{
                    printf("\n   Front: %d\n   Rear: %d\n", queue[front], queue[rear]);
                } 
                break;
            case 5:
                clearScreen();
                if(front == -1 && rear == -1){
                    printf("\nThe Queue is currently EMPTY\n");
                } 
                else{
                    printf("\nThe Queue is NOT EMPTY. It currently has %d/%d entries in Queue\n", rear+1, qSize);
                } 
                break;
            case 6:
                clearScreen();
                if(rear == (qSize-1)) {
                    printf("\nThe Queue is FULL\n");
                    printf("Entries Inside the Queue: %d/%d\n\n", rear+1, qSize);
                }
                else{
                    printf("\nThe Queue is NOT FULL\n");
                    printf("Entries Inside the Queue: %d/%d\n\n", rear+1, qSize);
                } 
                break;
            case 7:
                clearScreen();
                exit(1);
            default:
                clearScreen();
                printf("\nERROR: Invalid Choice. Please select a valid number from 1 - 7:\n");
        }

    }
}

void enqueue(int num, int qSize, int *queue){
    if(rear == (qSize-1)){      //if queue is full
        clearScreen();
        printf("\nQUEUE OVERFLOW: Cannot enqueue to a FULL queue\n");
        printf("Select (2)Dequeue from the Operations Menu to delete an entry from the Queue\n\n");
    }else if(rear < 0 && front < 0){    //if queue is empty
        front = 0;
        rear = 0;
        queue[rear] = num;
    }else {         //if queue has content but is not full
        rear++;
        queue[rear] = num;
    }
}

void dequeue(int *queue, int qSize){
    if(front < 0 && rear < 0){      //if queue is empty
        printf("\n\nQUEUE UNDERFLOW: Cannot dequeue from an EMPTY queue\n");
        printf("Select (1)Enqueue from the Operations Menu to insert an entry into the Queue\n\n");
    }else if(front == rear){            //if queue only has 1 entry
        queue[front] = queue[front+1]; 
        front = -1;         //declare that there are no existing entries in the queue. QUEUE IS NOW EMPTY
        rear = -1;
        printf("\nDeleted Last Entry. Queue is now EMPTY\n\n");
    }else{      //if queue has more than 1 entry
        queue[front] = queue[front+1];
        front++;
        printf("\nAn Entry Has been Removed.\n");
        printf("Current Entries in the Queue :%d/%d \n\n", qSize-front,qSize);
    }
}

void displayQueue(int *queue){
    printf("\nAll Values Currently in Queue: \n\n");
    for(int i = front; i <= rear; i++){
        printf(" %d <-- ", queue[i]);
    }
    printf("\n");
}

void clearScreen(void){
    //POSIX Compatible (For Linux Terminals)
    printf("\e[1;1H\e[2J");
}