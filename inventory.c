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


    // Add added item to file
    FILE *file = fopen("items_added.txt", "a");

    if(file == NULL){
        printf("Error creating file!\n");

    }

    // Add text to file
    fprintf(file, "%s, %d\n", item -> name, item -> price);

    fclose(file);
    free(item);



}

// View list of items
void display_item_list(){

    // Open file to read items
    FILE *file = fopen("items_added.txt", "r");

    if(file == NULL){
        printf("Error reading file!\n");

    }

    char particular_line[256]; // Bytes to take

    printf("\nList of items");
    printf("\n-------------\n");

    // While characters exist in each line
    while(fgets(particular_line, sizeof(particular_line), file) != NULL){
        printf("%s", particular_line);
    }

    printf("\n");
    printf("Done printing!\n");
    
}


// Delete item
void delete_item(){
    // Display list
    display_item_list();

    char item_to_del[100]; 
    bool getting_input = true;


    // ITEM TO DELETE
    while(getting_input){
        printf("\nEnter item to be deleted: ");

        if(fgets(item_to_del, sizeof(item_to_del), stdin) == NULL){
            printf("Error reading input!\n");
            continue;

        }

        else if(strcmp(item_to_del, "\n") == 0){
            printf("You pressed enter!\n");
            continue;

        }

        else{
            // Open file to read items
            FILE *file = fopen("items_added.txt", "r");
            
            if(file == NULL){
                printf("Error opening file!\n");
                return;

            }

            char each_line[100];

            // Open temporary file
            FILE *temp_file = fopen("temp.txt", "w");

            if(temp_file == NULL){
                printf("Error opening temporary file!\n");
                return;

            }

            // Read each line on the inventory.txt file and print it to the temp file if not a match 
            while(fgets(each_line, sizeof(each_line), file) != NULL){

                item_to_del[strcspn(item_to_del, "\n")] = 0; // Remove newline character

                // If no match
                if(strstr(each_line, item_to_del) == NULL){
                    fprintf(temp_file, "%s", each_line); // Copy to new file

                }

                // Match
                else{
                    printf("Item found and deleted!\n");
                    continue;
                }

            }

            fclose(file);
            fclose(temp_file);

            remove("items_added.txt");
            rename("temp.txt", "items_added.txt");
            getting_input = false;
            
        }

    }
    
    
}

// Search item

void search_item(){
    
    bool read_input = true;
    char item_to_search[200];


    while(read_input){
        printf("\nEnter item to search: ");

        if(fgets(item_to_search, sizeof(item_to_search), stdin) == NULL){
            printf("Error reading input!\n");
            continue;

        }

        else if(strcmp(item_to_search, "\n") == 0){
            printf("You pressed enter!\n");
            continue;

        }

        // Remove new line
        item_to_search[strcspn(item_to_search, "\n")] = 0;

        // Open file to search item
        FILE *file = fopen("items_added.txt", "r");
            
        if(file == NULL){
            printf("Error opening file! Retrying...\n");
            continue;

        }

        else{

            char line_by_line[256]; // Horizontal bytes
            int num_of_lines = 1;
            
            printf("\nSearching list...\n");
            
            // While char exists read line by line
            while(fgets(line_by_line, sizeof(line_by_line), file) != NULL){
                
                // If found
                if(strstr(line_by_line, item_to_search) != NULL){
                    
                    printf("Match found in line, %d!\n", num_of_lines);
                    read_input = false;
                    break;

                }


                else{
                    printf("No match found in line, %d!\n", num_of_lines);
                    num_of_lines++;
                    continue;
                }

                


            }
            
        }



    }
    


}

// Invalid option
void invalid_option(){
    printf("Invalid option");
    printf("\n");
    return;
}

void close_application(){
    printf("See you later\n");

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
    printf("\n3.Delete item");
    printf("\n4.Search item");
    printf("\n5.Close application\n");


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
            delete_item();
            continue;

        }

        else if(choice == 4){
            getchar();
            search_item();
            continue;

        }

        else if(choice == 5){
            getchar();
            close_application();
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