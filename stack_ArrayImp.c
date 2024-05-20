#include <stdio.h>
#include <stdlib.h>

//Declared globally for usage across all functions
int top;
int bottom;

//Function Prototypes
void push(int num, int stkSize, int *stack);
void pop(int stkSize, int *stack);
void display(int *stack);
void clearScreen(void);

int main(){
    int stkSize;
    int option;
    int num;
    top = -1;
    bottom = -1;

    printf("Enter the size of the Stack: ");
    scanf("%d", &stkSize);

    int *stack = (int*)malloc(stkSize * sizeof(int));

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

    return 0;
}

        //Function Declarations
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
        printf("Current Entries in the Stack: %d/%d \n\n", top+1, stkSize);
    }
}

void display(int *stack){
    printf("\nAll Values Currently in the Stack: \n\n");
    for(int i = top; i >= bottom; i--){
        printf("\n\t%d", stack[i]); printf("\n\n\tv\n"); 
    } 
}

void clearScreen(void){
    //POSIX Compatible (For Linux Terminals)
    printf("\e[1;1H\e[2J");
}