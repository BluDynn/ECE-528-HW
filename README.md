## Problem 1  
(a) What is the difference between a compiler and an interpreter?  
(b) What is the output of a C program’s main() function by default? 

> A Compiler, as most are familiar with, translates the source code into machine code and then runs the program. An Interpreter translates AND executes the code as the program runs. 
## Problem 2
What are header files in C and what is the purpose of the *#include* directive?

 > Header files are files that contain the function declarations that can be included in different source files. The \#include directive serves a way or a function to let the source file know which header files are to be included and referenced. A small note that I believe is important is the difference between utilizing <> and “”. The former is for system libraries while “” is for local header files.
## Problem 3 
Explain how to declare and define a function in C. What is the purpose of the return statement in a function? Can a function have more than one return statement?

> To define and declare a function in C, you must first include a function prototype at the top prior to the main function, then you are able to create the function definition and what it does at the bottom. The return statement serves as a value carrier, or a value return, when the function is called in a statement, if it is not a `void` function then it will return the value back to the function call. A function *can*  technically have multiple return functions but it can only run it once. The `return` function also serves as a break.

## Problem 4
What is type casting? Provide an example C function that demonstrates explicit type casting from double to int. The function should accept two arguments that are both double and return their sum as an integer. 

> Type casting is a way to convert data types between on and another. 

 ```C
 // I want this value  of an double to become an int
 double NumberOne = 2.0
 int NumberTwo = (int) NumberOne; //because NumberOne is equal to two
 //NumberTwo is now equal to 2 (not 2.0)
 ```
> Oh you wanted as a function…

```C
int ThisPlusThat(double this, double that){
	double sum = this + that; //kept as a doubhle to retain quality 
return (int) sum;
}
```



## Problem 5
Explain the difference between local and global variables. Provide an example of each.

> As the name suggests, local variables can be viewed and called locally within the function it was declared in. If a variable is declared outside a function  it becomes a global variable that can be referenced and viewed in any function. ah... a example.

```C
// to give an example I show a program that should not work and explain why followed up with a program that does work
int GoBALLS = 5;

int ThisFuncitonWillNotWork(int TrustMeBro);

int main(void){
	int localBalls = 0;
	int NewBalls = ThisFunctionWillNotWork(localBalls);
	return NewBalls;
}

int ThisFunctionWillNotWork(int TrustMeBro){
	return localBalls + GloBalls; //this will not work to make it work you should be using the local variable TrustMeBro as localBalls is not defined globally nor locally. GloBalls is globally defined
}
```

```C
// to give an example I show a program that should not work and explain why followed up with a program that does work
int GoBALLS = 5;

int ThisFuncitonWillNotWork(int TrustMeBro);

int main(void){
	int localBalls = 0;
	int NewBalls = ThisFunctionWillNotWork(localBalls);
	return NewBalls;
 } //should return 5

int ThisFunctionWillNotWork(int TrustMeBro){
	return TrustMeBro + GloBalls; //this will work
}
```

## Problem 6 
How are strings declared and initialized in C? What is the role of the null terminator `'\0'`?

```C
//strings are char arrays, there are libraries that help simplify this process but for this case I will only showcase a char array
char str[6] ="stiybt"
/ this char string will have a "terminator" character that pretty much declares the end of the char array. "\0" is the terminator character

## Problem 7
What is a pointer in C? How do you pass a pointer to a function? What advantages are there to passing a pointer instead of a value?

> In C a pointer "points" to the address where a variable may be stored. pass a pointer to a funciton you must dereference the pointer with the '*' operator. Advantages of using pointers instead of values include the ability to directly modify the passed data rather than copying equivalent data, multiple variable "return" allows you to "return" or modify muliple values with a function, and allows you to utilize the dynamic memory. 

## Problem 8
What does the `*` operator and the `&` operator do in the context of pointers?

>In the context of pointers the '*' dereferences the pointer, accessing the data at the address. While '&' access the memory address of the data. 

## Problem 9
What is the difference between `while` and `do...while` loops?

> A while loop checks the condition once before running, as opposed to a do while loop in which checks the condition after loop. 

## Problem 10
What does the `break` statement do? How is it different from the `continue` statement?

>The break statement is used to immediately exit any loops, while the continue statement is used to immediately move to the next iteration of the loop. 

## Problem 11
Explain the use of bitwise operators (i.e. `&`, `|`, `^`, `~`, `<<`, `>>`) in C. Which bitwise operators can be used to set, clear, toggle, or check a specific bit in an integer variable?

> -set 				'|' 
> -clear			'&' paired with a '~'
> -toggle 			'^' 
> -Check bit 		'&' 

## Problem 12
What is the purpose of the `PxSEL0` and `PxSEL1` GPIO registers? Write two statements that select the GPIO function for the pins P1.0 and P1.7.

>The PxSEL0 and PxSEL1 GPIO registers select the different funciton for different peripherals. 

```C
P1SEL0 &= ~(0x81); // 

```

## Problem 13
Write a void function named `P1_1_and_P1_4_Init` that configures P1.1 and P1.4 as GPIO inputs with pull-up resistors enabled.

```C
void P1_1_and_P1_4_Init(void){
	 	P1->SEL0 &= ~(BIT1 | BIT4);
		P1->SEL1 &= ~(BIT1 | BIT4);

		P1->DIR &= ~(BIT1 | BIT4);  // GPIO inputs
		P1->REN |=  (BIT1 | BIT4);  // Enable pull resistors
		P1->OUT |=  (BIT1 | BIT4);  // Select pull-ups
}
```
## Problem 14
Write a void function named `Buttons_Init` that configures the following pins as GPIO inputs with pull-down resistors enabled.

- P3.1
- P3.6
- P5.0
- P5.4


```C
	void Buttons_Init(void){
		P3->SEL0 &= ~(0x42);
		P3->SEL1 &= ~(0x42); //periphs

		P5->SEL0 &= ~(0x09);// periphs 
		P5->SEL1 &= ~(0x09);

		P3->DIR &= ~(0x42);// dir
		P5->DIR &= ~(0x09);

		P3->REN |=  (0x42);
		P5->REN |=  (0x09);// resistor

		P3->OUT &= ~(0x42);  // Pull-downs
		P5->OUT &= ~(0x09);
	}
```

## Problem 15
Write a void function named `LEDs_Init` that configures the following pins as GPIO outputs. Initialize the pins to zero.

- P7.0 to P7.7

```C
void LEDs_Init(void)
{
    P7->SEL0 &= ~0xFF;
    P7->SEL1 &= ~0xFF;

    P7->DIR |= 0xFF;   // P7.0-P7.7 as outputs
    P7->OUT &= ~0xFF;  // Initialize outputs to zero
}
```