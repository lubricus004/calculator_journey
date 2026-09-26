#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	//added = { 0 } so it eliminates previous junk data from previous memory users
	char num1[20] = { 0 }; 
	char middle[20] = { 0 };
	char num2[20] = { 0 };
	double running = 1;
	char input[20] = { 0 };
	//added input so fget can use it to store user input it field
	int field = 0;
	// added field to put sscanf_s inside it to be able to count how many inputs it got so we can prevent error
	//by telling the program not to continue if the inputs are not up to

	while (running == 1) {

		num1[0] = '\0'; 
		//re-added num1[0] = '\0' so that whatever user previously typed is removed from memory so that 
		//fgets doesn't reuse old data from previous calculations cos it resets the memory box to \0

		middle[0] = '\0';

		num2[0] = '\0';
		
		printf("\nCalculator initiated!!\n");

		fgets(input, sizeof(input),stdin); 
		//used fget because it reads everything at a given address even spaces and new line and even \0 
		//unlike scanf_s that stops at space.

		if (strchr(input, 'q') != NULL) {
			running = 0;
			break;
		}//checks every single box to see if it contains the letter 'q'. 

		field = sscanf_s(input,"%s %s %s", num1, (unsigned)sizeof(num1), middle, (unsigned)sizeof(middle), num2, (unsigned)sizeof(num2));
		//put sscanf_s to count how many inputs split with space it recorded
		//im using sscanf with ( 3 %S ) because sscanf auto splits with space so it auto share the user inputs
		// into the three distinct fields i left ( num1,middle,num2)

		if (field < 3) {
			printf("Incomplete please enter at least 3 inputs");
			continue;
		}
		//this rule helps the program not to  crash because someone typing only two inputs will 
		// make the program not work so adding the <3 since we need three firlds to calculate

			double value1 = atof(num1); //convets the strings into double using atof command.
			double value2 = atof(num2);
			double result; 

			if (middle[0] == '+') {
				result = value1 + value2;
				printf("%f", result);
			}

			else if (middle[0] == '-') {
				result = value1 - value2;
				printf("%f", result);
			}
			else if (middle[0] == '*') {
				result = value1 * value2;
				printf("%f", result);
			}
			else if (middle[0] == '/') {
				if (value2 != 0) {
					result = value1 / value2;
					printf("%f", result);
				}
				else {
					printf("not divisible by zero");
				}
			}
		
	}

}