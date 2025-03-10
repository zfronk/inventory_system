#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


// Check for Dupes
bool confirm_duplicates(char *fruit){
    FILE *file = fopen("fruits.txt", "r");

    char line[256];

    // In each loop while it reads files check if the name exists
    while(fgets(line, sizeof(line), file)){

        if(strstr(line, fruit) != NULL){
            return true;

        }

    }



}


// Ask for fruits
void ask_for_fruit(){
    bool asking_fruit = true;
    char fruit[100];
    
    // Loop to take input
    while(asking_fruit){
        printf("\nHello there add a fruit: ");

        // Error in reading input
        if(fgets(fruit, sizeof(fruit), stdin) == NULL){
            printf("Error reading input\n");
            continue;

        }


        // Remove if eneter
        if(strcmp(fruit, "\n") == 0){
            printf("You pressed enter!");
            printf("\n");
            continue;

        }

        // Remove new line char
        fruit[strcspn(fruit, "\n")] = 0;

        // Open file // Append mode
        FILE *file = fopen("fruits.txt", "a");

        if(file == NULL){
            printf("Error opening file\n");
            continue;

        }

        // If dupes kick and prompt again
        if(confirm_duplicates(fruit) == true){
            printf("Fruit already exists!");
            printf("\n");
            continue;
        }

        fprintf( file, "%s\n", fruit); // Write to file
        printf("Fruit added!");
        printf("\n");
        asking_fruit = false;
        

        

    }
}

// Convert case
void convert_case(){
    char character_one = 's';

    // Convert to uppercase
    character_one = toupper(character_one);

    printf("To uppercase: %c", character_one);
    printf("\n");

    char string_one[] = "steve";

    int i = 0;

    // iterate and make uppercase
    while(i < strlen(string_one)){
        string_one[i] = toupper(string_one[i]);
        i++;

    }

    printf("To uppercase: %s\n", string_one);
    printf("\n");

    


}

int main(){

    convert_case();
    return 0;
}