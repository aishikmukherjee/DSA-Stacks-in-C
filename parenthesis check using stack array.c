//////////////////////////////////////// Array stack is used //////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h> // Added for malloc and free
#include <string.h> // Added for strlen
#define SIZE 100 // Define the maximum size for the stack

// Define the structure of the stack.
typedef struct stack {
    int top;      // Index of the top element in the stack
    int* arr;     // Pointer to the array that holds stack elements
} stack;

// Function prototypes
int isEmpty(stack* ptr); // Check if the stack is empty
void PUSH(stack* ptr);   // Add an element to the stack
int POP(stack* ptr);     // Remove an element from the stack

// Main function to execute the program
int main() {
    char str[100]; // Array to hold the input expression
    printf("\nEnter Expression to check for correct parenthesis: ");
    scanf(" %[^\n]s", str); // Read the input expression

    // Allocate memory for the stack structure
    stack* s = (stack*)malloc(sizeof(stack));
    if (s == NULL) {
        printf("\nStack memory allocation failed...!!!");
        return 1; // Exit if memory allocation fails
    }

    // Allocate memory for the stack array
    s->arr = (int*)malloc(SIZE * sizeof(int));
    if (s->arr == NULL) {
        printf("\nStack memory allocation failed...!!!");
        free(s); // Free the stack structure memory before exiting
        return 1; // Exit if memory allocation fails
    }
    s->top = -1; // Initialize top index to -1 (indicating the stack is empty)

    int len = strlen(str); // Get the length of the input expression

    // Iterate through each character in the input string
    for (int i = 0; i < len; i++) {
        if (str[i] == '(') { // If the character is an opening parenthesis
            PUSH(s); // Push to the stack
        } else if (str[i] == ')') { // If the character is a closing parenthesis
            int flag = POP(s); // Pop from the stack
            if (flag == 100) { // Check if the stack was empty
                printf("\nWrong Parenthesis...!!!");
                free(s->arr); // Free the stack array memory
                free(s); // Free the stack structure memory
                printf("\n\nMemory Released.....!!!\n");
                return 0; // Exit the program
            }
        }
    }

    // After processing the entire expression, check if the stack is empty
    if (isEmpty(s)) {
        printf("\nRight Parenthesis...!!!"); // Valid expression
    } else {
        printf("\nWrong Parenthesis...!!!"); // Invalid expression
    }

    // Free allocated memory before exiting
    free(s->arr); // Free the stack array memory
    free(s); // Free the stack structure memory
    printf("\n\nMemory Released.....!!!\n");
    return 0; // End of the main function
}

// Function to check if the stack is empty
int isEmpty(stack* ptr) {
    return (ptr->top == -1) ? 1 : 0; // Return 1 if empty, otherwise 0
}

// Function to add an element to the stack
void PUSH(stack* ptr) {
    ptr->top++; // Increment the top index
    ptr->arr[ptr->top] = 1; // Push a placeholder value (1) to the stack
}

// Function to remove an element from the stack
int POP(stack* ptr) {
    if (ptr->top == -1) { // Check if the stack is empty
        return 100; // Return a special value indicating underflow
    } else {
        ptr->top--; // Decrement the top index
        return 0; // Return 0 indicating success
    }
}
