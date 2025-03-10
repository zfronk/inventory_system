#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// SCRIPT ON WORKING WITH FILES

// Struct to user details
struct USER{
    char user_name[300];
    char user_password[300];
};

// Open users file
void create_file(){
    // Append mode -> Creates or edits existing files
    FILE *users_file = fopen("user_details.txt", "a+");

    // Kick out if error
    if(users_file == NULL){
        printf("\nError occured while opening file");
        return;

    }

    else{

        printf("File created succesfully");
        printf("\n");
        fclose(users_file); // Close file 
        
    }
}

// Login user
void login_user(){
    
    // Pointer to struct // Allocate memory
    struct USER *current_user = (struct USER*)malloc(sizeof(struct USER));

    if(current_user == NULL){
        printf("\nMemory allocation failed");
        return;

    }

    bool asking_name = true;

    //  Get name
    while(asking_name){
        printf("\nEnter name: ");

        // If crashed
        if(fgets(current_user -> user_name, sizeof(current_user -> user_name), stdin) == NULL){
            printf("\nError occured while reading input. Try again");
            continue;

        }


        // If enter
        if(strcmp(current_user -> user_name, "\n") == 0){
            printf("You pressed enter no input!");
            printf("\n");
            continue;

        }

        // OK
        else{
            current_user -> user_name[strcspn(current_user -> user_name, "\n")] = 0; // Remove newline
            printf("Username added!");
            printf("\n");
            asking_name = false;

        }


    }


    bool creating_password = true;


    while(creating_password){
        printf("\nEnter password: ");


        // If crashed

        if(fgets(current_user -> user_password, sizeof(current_user -> user_password), stdin) == NULL){
            printf("Error occured while getting input");
            continue;
        }

        // If enter
        if(strcmp(current_user -> user_password, "\n") == 0){
            printf("\nPlease don't press enter without inputting anything");
            continue;

        }

        // OK
        else{
            current_user -> user_password[strcspn(current_user -> user_password, "\n")] = 0;
            printf("Password added!");
            printf("\n");

            creating_password = false;

            
            }

            
            
            
        

    }

    // Open file to add data
    FILE *user_file = fopen("user_details.txt", "a");

    if(user_file == NULL){
        printf("\nError opening file");
        free(current_user);
        return;
    }


    else{
        fprintf(user_file, "%s: %s\n", current_user -> user_name, current_user -> user_password);

    
        printf("\nData added to file!");
        printf("\n");

        fclose(user_file);
        free(current_user);
    }
}

int main(){
    create_file();
    login_user();
    return 0;
}