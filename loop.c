#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Buffer clearance
void clear_buffer(){
    while(getchar() != '\n'){

    } 
}

void ask_question(){

    int age;
    
    bool is_running = true;
    

    while(is_running){
        printf("\nInput age: ");

        int first_char = getchar();

        if(first_char == '\n'){
            printf("You pressed enter!");
            printf("\n");
            continue;

        }


        // Check for non - interger
        if(scanf("%d", &age) != 1){
            printf("Try again. Invalid data type!");
            printf("\n");
            
            // clear the buffer input space
            clear_buffer();

        }


        // If interger
        else{

            if(age > 0 ){
                clear_buffer();
                printf("\nYou are %d years old", age);
                printf("\n");
                is_running = false;

            }
        }

        
    }


    printf("\n");
    
}


int main(){
    ask_question();
    return 0;
}