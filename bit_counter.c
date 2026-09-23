
#include <stdio.h>
#include <stdlib.h>
//#include <stdint.h>

void PissedMeOff(int UserIn, int NumOcc); 

int main(void){
    int UserInput;
    int PissingMeOffCounter = 0;
    //prompt and get user input 
    while(PissingMeOffCounter != -1){
        printf("Input User Integer From 0-255: \n");
        scanf("%u", &UserInput);

        if(UserInput >= 0 && UserInput <=255){
            PissingMeOffCounter = -1;
            break;
        }
        else{
            PissedMeOff(UserInput,PissingMeOffCounter);
            PissingMeOffCounter++;
        }

    }
    // The actual bit counter portion
    // use modulo possibly to count bits

    //MSB 
    int NumBits = 0;

    while (UserInput > 0)
    {
        NumBits += UserInput % 2;  // Adds 1 if the lowest bit is 1
        UserInput /= 2;          // Shift right by one bit
    }

    printf("your number has %d bits\n",NumBits);
}

/*
* @brief a simple cgpt response style that gives my programs a bit of quirk, essentially a mini program that picks a "random" set of phrases that 
* grill the user for not being able to follow the simple format of putting an integer between 0 and 255, its not the main focus of the a

*/
void PissedMeOff(int UserIn, int NumOcc)
{
    const char *messages[] =
    {
        "Please read the instructions. They are doing their best.",
        "0 through 255. Not 9000. Not a phone number. 0 through 255.",
        "This is becoming less of an input problem and more of a lifestyle choice.",
        "The computer is disappointed, and honestly, so am I.",
        "You have successfully entered the wrong number multiple times.",
        "At this point, I admire your commitment to being incorrect."
    };

    int messageCount = sizeof(messages) / sizeof(messages[0]);
    int messageIndex = NumOcc;

    if (messageIndex >= messageCount)
    {
        messageIndex = messageCount - 1;
    }

    if (UserIn == 420)
    {
        printf("420? Blaze it? you think youre so funny huh. This program requires an integer from 0-255.\n\n");
    }

    else if (UserIn == 6767)
    {
        printf("6767? HAHAHAH SIX SEVEN YOURE SO FUNNY... grow up dude.\n\n");
    }
    else if (UserIn < 0)
    {
        printf("Negative numbers are not invited to this party.\n\n");
    }
    else
    {
        printf("Error: %d is invalid. %s\n\n",
               UserIn,
               messages[messageIndex]);
    }
}