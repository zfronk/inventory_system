#include <stdio.h>
#include <string.h>


int main(){

    int number;
    printf("\nEnter a number: ");


    int get_char = getchar();

    if(get_char == '\n'){
        printf("You pressed enter!");
        printf("\n");

    }

    printf("\nEnter a number: ");

    // Check data type
    if(scanf("%d", &number) != 1){
        printf("\nInvalid data type!");
        printf("\n");
        while(getchar() != '\n'); // Clear input stored in the buffer

    }

    printf("\nInput a new number: ");

    scanf("%d", &number);


   

    return 0;
}