
#include <stdio.h>
#include <stdlib.h>

int main(void){
    //init and title 
    printf("ECE 528/L - Daniel Jeorge Adrayan - HW1\n\n");
    int UserNum;
    printf("Please input a number \n\n");
    scanf("%i", &UserNum);
    printf("\n");
    if(UserNum > 0){
        printf("%i is a positive value.\n\n",UserNum);
    }
    else if(UserNum<0)
    {
        printf("%i is a negative value.\n\n",UserNum);
    }
    else{
        printf("%i is zero ... \n rlly bro why 0 thats a lame ass number...\n\n",UserNum);
    }

    printf("The absolute value of your number is %i\n", abs(UserNum));

}