#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// WAREHOUSE INVENTORY SYSTEM

// Initialize struct to item
struct ITEM{
    char name[100];
    int price;

};


// Add item 
void add_item(){
    
    // Address to struct where item name, price is stored
    struct ITEM *item = (struct ITEM*)malloc(sizeof(struct ITEM));  // -- > NO segmentation faults 

    if(item == NULL){
        printf("\nMemory allocation failed");
        return;

    }
    
    
    // printf("\nAdding item name...");
    // printf("\n");
    

    // ITEM NAME
    
    bool prompt_item_name = true;
    
    // Keep checking for item - name
    while(prompt_item_name){
        printf("\nEnter item name: ");
        
        // Leaves a newline
        if(fgets(item -> name, sizeof(item -> name), stdin) == NULL){
            printf("\nError occured! Exited function.");
            prompt_item_name = false;

        }

        // If enter
        else if(strcmp(item -> name, "\n") == 0){
            printf("You pressed enter, input is empty!");
            printf("\n");

        }

        else{
            // Remove new line character
            item -> name[strcspn(item -> name, "\n")] = 0;
            printf("Item added!");
            printf("\n");
            //printf("\nInput: %s", item -> name);
            prompt_item_name = false;   
        }

        

    }


    // printf("\nAdding item price...");
    // printf("\n");

    // ITEM PRICE
    bool prompt_item_price = true;
    


    while(prompt_item_price){
        printf("\nEnter item price: ");

        // Pick the first char compare
        char firstchar = getchar();

        // Check for Enter
        if(firstchar == '\n'){
            printf("You pressed enter! Try again");
            printf("\n");
            continue;

        }

        // If not put the char back to stdin
        ungetc(firstchar, stdin);

        

        // Try again if not integer
        if(scanf("%d", &item -> price) != 1){
            printf("Inappropriate data type! Use integers");
            while(getchar() != '\n'); // Flush remaining buffer remove bugs
            printf("\n");
            continue;
        }

        // scanf leaves behind "\n" when user presses enter! // This leaves bugs

        else{
            while(getchar() != '\n'); // Flush remaining buffer remove bugs
            printf("Price added!");
            printf("\n");

            prompt_item_price = false;

        }

        

    }



}

// View list of items
void display_item_list(){
    printf("\nYou're viewing the item list");
    printf("\n");
    
}

// Invalid option
void invalid_option(){
    printf("Invalid option");
    printf("\n");
    return;
}



// Manage dashboard
void manage_dashboard(){
    
    // Dashboard
    printf("\nWAREHOUSE INVENTORY MANAGEMENT SYSTEM");
    printf("\n=====================================");

    printf("\n");
    
    printf("\nDASHBOARD");
    printf("\n=========");
    printf("\n1.Add item");
    printf("\n2.View item list");
    printf("\n3.Close application\n");


    int choice;
    bool is_running = true;


    while(is_running){
        printf("\nChoose an option from the dashboard: ");

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
            display_item_list();
            continue;

        }

        else if(choice == 3){
            getchar();
            printf("\nExited");
            printf("\n\n");
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