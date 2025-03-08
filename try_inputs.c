#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

int main() {
    char gender[15];

    while (1) {
        printf("\nEnter your gender: ");
        fgets(gender, sizeof(gender), stdin);
        gender[strcspn(gender, "\n")] = 0; // Remove newline character

        toLowerCase(gender); // Convert input to lowercase

        if (strcmp(gender, "male") == 0) {
            printf("\nHey there male!\n");
            break;
        } 
        else if (strcmp(gender, "female") == 0) {
            printf("\nHello there female!\n");
            break;
        } 
        else {
            printf("\nChoose either Male or Female!");
        }
    }

    return 0;
}
