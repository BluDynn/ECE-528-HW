
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void){
    //init and title 
    printf("ECE 528/L - Daniel Jeorge Adrayan - HW1\n\n");

    //actual problem

    int n; 
    uint32_t previous = 0;
    uint32_t current = 1; //f(0) 
    uint32_t next = 0;
    
    printf("Enter an integer N (N >= 2): ");

    if (scanf("%d", &n) != 1 || n < 2)
    {
        printf("Error: My brother in christ! Please enter a valid integer greater than or equal to 2.\n");
        return 1;
    }

    for (int i = 2; i <= n; i++)
    {
        next = previous + current;
        previous = current;
        current = next;
    }

    printf(" F(%d) = %u\n", n, current);

    return 0;
}