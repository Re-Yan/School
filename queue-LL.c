#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// creating the NODE
typedef struct Node{
    
    int value;
    struct Node *next;

} Node;

// global pointers in order for all functions to access
Node *front = NULL;
Node *rear = NULL;

// Function Prototype
void enqueue(int num);
void dequeue(void);
void display(Node *front);
void clearScreen(void);

int main(void){
    int choice;
    int value;

    while(1){
            printf("\n1. Enqueue\n");
            printf("2. Dequeue\n");
            printf("3. Display\n");
            printf("4. Peek \n");
            printf("5. IsEmpty\n");
            printf("6. Exit \n");
            printf("\nChoose which operation to use (TYPE THE NUMBER): ");
            scanf("%d", &choice);
            
            switch (choice){
                case 1:
                    clearScreen();
                    printf("\n\nEnter the value you wish to add in the Queue: ");
                    scanf("%d", &value);
                    enqueue(value);
                    break;
                case 2:
                    clearScreen();
                    dequeue();
                    break;
                case 3:
                    clearScreen();
                    display(front);
                    break;
                case 4:
                    clearScreen();
                    printf("\n\nFirst Element: %d\n", front->value);
                    printf("Last Element: %d\n\n", rear->value);
                    break;
                case 5:
                    clearScreen();
                    if(front == NULL && rear == NULL){
                        printf("\n\nQUEUE IS EMPTY\n\n");
                    }else{
                        printf("\n\nQUEUE IS NOT EMPTY \n\n");
                    }
                    break;
                case 6:
                    clearScreen();
                    exit(1);
                default:
                    clearScreen();
                    printf("\nERROR\n\n");
            }
        }

    return 0;
}

void enqueue(int num){
    Node *temp = (Node*)malloc(sizeof(Node*));
    temp->value = num;
    temp->next = NULL;
    
    if(front == NULL && rear == NULL){ //if queue is empty
        front = rear = temp;    
    }else { // if queue is not empty
        rear->next = temp;
        rear = temp;
    }

}

void dequeue(void){
    Node *temp = front;

    if(front == NULL && rear == NULL){      // if queue is empty
        printf("ERROR: cannot dequeue from an empty Queue");
    }else if(front == rear){        // if there is only 1 node remaining
        front = NULL;
        rear = NULL;
    }else{          // if there are 2 or more nodes in the queue
        front = front->next;
    }
    
    free(temp);     //the actual deletion of a node
    printf("\nA NODE has been deleted\n\n");
}

void display(Node *front){
    if(front == NULL && rear == NULL){
        printf("\nEMPTY QUEUE: Nothing to Display \n\n");
    }else{
        Node *temp = front;

        printf("\n\n");
        while (temp->next != NULL){
            printf("%d \t", temp->value);
            temp = temp->next;
        }

        printf("%d \t", rear->value);
        printf("\n\n");
    }
}

void clearScreen(void){
    //POSIX Compatible (For Linux Terminals)
    printf("\e[1;1H\e[2J");
}