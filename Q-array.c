#include <stdio.h>
#include <stdlib.h>   

//Declared globally for usage across all functions
int front;      
int rear;

//Function Prototypes
void enqueue(int num, int qSize, int *queue);
void dequeue(int *queue, int qSize);
void display(int *queue);
void clearScreen(void);

int main(){
    front = -1;     //starting value is -1 to define that it still doesnt exist in the queue
    rear = -1;

    int qSize;
    int value;
    int choice;
    int *queue;     //array declaration is a pointer since we will be allocating memory using malloc

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
                    display(queue);
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

for(int i = 0; i < qSize; i++){
    printf("Enter the value you wish to add in the queue: ");
    scanf("%d", &value);
    enqueue(value, qSize, queue);      //function call
}
    
   return 0;
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

void display(int *queue){
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