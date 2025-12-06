#include <stdio.h>
#include <string.h>
#define MAX 100
char undoStack[MAX][100];
char redoStack[MAX][100];
int undoTop = -1, redoTop = -1;
// Push text state onto a stack
void push(char stack[][100], int *top, char text[]) {
 if(*top < MAX - 1) {
 (*top)++;
 strcpy(stack[*top], text);
 }
}
// Pop text from a stack
void pop(char stack[][100], int *top, char text[]) {
 if(*top >= 0) {
 strcpy(text, stack[*top]);
 (*top)--;
 }
}
int main() {
char text[100] = ""; // current text
 char temp[100];
 int choice;
 while(1) {
 printf("\n--- TEXT EDITOR (STACK Simulation: Undo / Redo) ---\n");
 printf("Current Text: \"%s\"\n", text);
 printf("1. Type New Text\n");
 printf("2. Undo\n");
 printf("3. Redo\n");
 printf("4. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 getchar(); // flush newline
 if(choice == 1) {
 push(undoStack, &undoTop, text); // Save current before typing
 printf("Enter new text: ");
 fgets(text, sizeof(text), stdin);
 text[strcspn(text, "\n")] = '\0';
 redoTop = -1; // Clear redo stack after new editing
 } else if(choice == 2) {
 if(undoTop == -1) {
 printf("Nothing to UNDO!\n");
 } else {
push(redoStack, &redoTop, text); // Save for Redo
 pop(undoStack, &undoTop, text); // Undo
 }
 } else if(choice == 3) {
 if(redoTop == -1) {
 printf("Nothing to REDO!\n");
 } else {
 push(undoStack, &undoTop, text); // Save for Undo
 pop(redoStack, &redoTop, text); // Redo
 }
 } else if(choice == 4) {
 printf("Exiting Program...\n");
 break;
 } else {
 printf("Invalid choice!\n");
 }
 }
return 0;
}
