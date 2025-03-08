#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Add item 
void add_item(){
    printf("\nYou're adding an item");
    printf("\n");

}

// View list of items
void view_item_list(){
    printf("\nYou're viewing the item list");
    printf("\n");
    
}

// Invalid option
void invalid_option(){
    printf("\nInvalid option");
    return;
}



// Manage dashboard
void manage_dashboard(){
    
    // Dashboard
    printf("\nWelcome to the inventory system");

    printf("\n");
    printf("\n1.Add item");
    printf("\n2.View item list");
    printf("\n3.Close application\n");


    int choice;
    bool is_running = true;


    while(is_running){
        printf("\nChoose an option: ");

        // Check for empty input (Enter key) -- Takes one line and reads
        int first_char = getchar();
        
        if (first_char == '\n') {
            printf("You pressed Enter! Try again.\n");
            continue;  // Restart loop
        }
        
        // Put it back if not Enter
        ungetc(first_char, stdin);

        
        if(scanf("%d", &choice) != 1){
            printf("Invalid input! Please enter a number\n");
            while(getchar() != '\n'); // Clear input buffer
            continue; // Restart the loop
        }



        if(choice == 1){
            getchar();
            add_item();
            continue;

        }

        else if(choice == 2){
            getchar();
            view_item_list();
            continue;

        }

        else if(choice == 3){
            getchar();
            printf("\nBye!\n");
            is_running = false;


        }

        else{
            getchar();
            invalid_option();
            continue;
            
        }

        


    }
    

}



// Main program
int main(){
    manage_dashboard();


}