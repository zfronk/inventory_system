#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create file
void create_and_write(){
    
    // Append mode
    FILE *file = fopen("demo.txt", "a");
    
    if(file == NULL){
        printf("\nError opening file");
        return;
    }

    fclose(file);

    printf("\nFile created succesfully!");
    printf("\n");


}

// Read file
void read_file(){
    FILE *file = fopen("demo.txt", "r");

    if(file == NULL){
        printf("\nError openning file!");
        return;
    }

    // Read lines
    else{
        printf("\nReading file data...");
        printf("\n");
        
        char line[256];

        // Read each line

        printf("\nData");
        printf("\n----");
        printf("\n");
        while(fgets(line,sizeof(line), file )){
            printf("%s", line);

        }

        printf("\n");
        printf("\nDone reading file");
        printf("\n");
        fclose(file);

    }

}


// Count lines written
void count_written_lines(){
    FILE *file = fopen("demo.txt", "r");

    printf("\n");

    if(file == NULL){
        
        printf("\nError occured while opening file");

    }


    else{

        int number_of_lines = 0;
        char line[256];

        while(fgets(line, sizeof(line), file)){
            number_of_lines++;

        }

       
        printf("Number of written lines in file: %d", number_of_lines);
        printf("\n");


    }

}


// Search string 
void search_string(char *string_to_be_found){
    FILE *file = fopen("demo.txt", "r");
    
    printf("\n");

    // If error
    if(file == NULL){
        printf("\nError occured while openning file");

    }

    char line[256];

    int line_number = 0;

    while(fgets(line, sizeof(line), file)){

        line_number++;
        
        char *found = strstr(line, string_to_be_found);

        if(found != NULL){
            printf("%s, has been found at position %ld, line number %d!", string_to_be_found, (long int)(found - line), line_number);
            printf("\n");
            return;
           
        }

    }

    printf("\n");

}

// Entry point
int main(){

    //create_and_write();
    read_file();
    count_written_lines();
    search_string("Boke");
    
    return 0;
}