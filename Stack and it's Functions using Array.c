#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 5 // Define the maximum size of the stack

// Define the structure of the stack.
typedef struct {
    int top;   // Index of the top element
    int *arr;  // Pointer to the array that holds stack elements
} stack;

// Declaring the function prototypes.
int isEmpty(stack* ptr); // Check if the stack is empty
int isFull(stack* ptr);  // Check if the stack is full
void PEEK(stack* ptr);   // View the top element of the stack without removing it
void PUSH(stack* ptr);   // Add an element to the top of the stack
void POP(stack* ptr);    // Remove the top element from the stack
void shots(stack* s);    // Manage stack operations based on user input
void clearScreen();       // Clear the console screen (Windows-specific)

// Main function to execute the program.
int main() {
    stack *s = (stack*)malloc(sizeof(stack)); // Allocate memory for the stack structure
    s->arr = (int*)malloc(SIZE * sizeof(int)); // Allocate memory for the stack array
    s->top = -1; // Initialize the top index to -1 (indicating the stack is empty)
    printf("\nStack created successfully........!!!\n");

    shots(s); // Start managing stack operations
    free(s->arr); // Free the memory allocated for the stack array
    free(s); // Free the memory allocated for the stack structure
    printf("\nMemory Freed Successfully...!!!\n");
    return 0; // End of the main function
}

// Function to clear the console screen (Windows-specific).
void clearScreen() {
    system("cls"); // Clears the console
}

// Function to manage stack operations based on user input.
void shots(stack* s) {
    int choice; // Variable to store user choice
    while (1) { // Infinite loop until the user decides to exit
        // Display the menu options for stack operations
        printf("\nEnter 1 to PUSH data into the Stack");
        printf("\nEnter 2 to POP data from the Stack");
        printf("\nEnter 3 to PEEK data in the Stack");
        printf("\nEnter 4 to check if the Stack is EMPTY or not");
        printf("\nEnter 5 to check if the Stack is FULL or not");
        printf("\nEnter anything else to end the program and free the computer memory");

        printf("\nEnter Choice: ");
        scanf("%d", &choice); // Get the user's choice

        // Execute the corresponding function based on user choice
        switch (choice) {
            case 1:
                PUSH(s); // Call the PUSH function
                break;
            case 2:
                POP(s); // Call the POP function
                break;
            case 3:
                PEEK(s); // Call the PEEK function
                break;
            case 4:
                isEmpty(s); // Call the isEmpty function
                break;
            case 5:
                isFull(s); // Call the isFull function
                break;
            default:
                printf("\nProgram Killed........!!!\n");
                return; // Exit the function to end the program
        }

        // Ask if the user wants to continue
        int flag;
        printf("\nEnter 1 to continue performing operations on the stack, or anything else to exit: ");
        scanf("%d", &flag); // Get user confirmation to continue
        if (flag != 1) {
            break; // Exit the loop if user does not want to continue
        }
        clearScreen(); // Clear the console screen for better visibility
    }
}

// Function to check if the stack is empty.
int isEmpty(stack* ptr) {
    if (ptr->top == -1) { // Check if top index is -1
        printf("\nStack is Empty.\n"); // Indicate the stack is empty
        return 1; // Return 1 for true (empty)
    } else {
        printf("\nStack is not Empty.\n"); // Indicate the stack is not empty
        return 0; // Return 0 for false (not empty)
    }
}

// Function to check if the stack is full.
int isFull(stack* ptr) {
    if (ptr->top == SIZE - 1) { // Check if top index is at the maximum size
        printf("\nStack is Full.\n"); // Indicate the stack is full
        return 1; // Return 1 for true (full)
    } else {
        printf("\nStack is not Full.\n"); // Indicate the stack is not full
        return 0; // Return 0 for false (not full)
    }
}

// Function to view the top element of the stack without removing it.
void PEEK(stack* ptr) {
    if (isEmpty(ptr)) { // Check if the stack is empty
        printf("\nWarning: Stack Underflow\n"); // Warn about underflow
    } else {
        // Display the topmost element and its position
        printf("\nThe current Top most element: %d", ptr->arr[ptr->top]);
        printf("\nPosition of %d: ", ptr->top + 1);
        printf("\nIndex of %d: ", ptr->top);
    }
}

// Function to add an element to the top of the stack.
void PUSH(stack* ptr) {
    if (isFull(ptr)) { // Check if the stack is full
        printf("\nWarning: Stack Overflow.......!!!\n"); // Warn about overflow
    } else {
        ptr->top++; // Increment the top index
        // Prompt user for data to push
        printf("\nEnter Data to PUSH into the Stack: ");
        scanf("%d", &(ptr->arr[ptr->top])); // Read the input value
        printf("\nPushed %d into the stack.\n", ptr->arr[ptr->top]); // Confirm the push
    }
}

// Function to remove the top element from the stack.
void POP(stack* ptr) {
    if (isEmpty(ptr)) { // Check if the stack is empty
        printf("\nWarning: Stack Underflow....!!!\n"); // Warn about underflow
    } else {
        // Display the popped element and decrement the top index
        printf("\nPopped %d from the stack.\n", ptr->arr[ptr->top]);
        ptr->top--; // Decrement the top index
    }
}
