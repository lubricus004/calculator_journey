#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//for this new calculator version, i update it so that the user can do multiple calculations at one
	//like 2 * 2 + 4 etc

int main() {
	
	//we only need one input field since were using tokenizing
	char input[50] = { 0 };
	
	//the for loop which lets tokenizer loops untill there is no more word or number after \0 (delimeter)
	// since that is a stop sign and tokenizing changes  what you used as the delimeter to \0 and that is what tells
	// c to stop so if therse anything after \0 c keeps it in memory and tagged NULL.
	//
	for (int i = 0; ;i++) {

		printf("%d:ON!!\n", i + 1);

		fgets(input, sizeof(input), stdin);

		char* token = strtok(input, " ");// calling the first token.
		if (token == NULL) break;  //check if token is empty and and breaking cos we dont want unneccesary memory usage;
		double result = atof(token); //changing the first token into a float
		
		while (token != NULL) {  //The guard to keep the loop going as long as token is not empty and stop if its empty

			// calling the operatoe (+-*/) so its always called after a batch of token since its always after a token 
			// like ( 987 + 4 + 0) so the op is always in the middle of 2 tokens
			char* op = strtok(NULL, " ");
			if (op == NULL) break; //also a guard brake


			// calling the second or next token so its always called after an operator since its always after an operator
			// like ( + 4) 0r   ( * 256) so the next is always after operator as long as the loop continues
			char* next = strtok(NULL, " ");
			if (next == NULL) break; //also a guard break

			if (op[0] == '+') {
				result += atof(next);//  added atof so it transform the string into float on the fly
			}
			else if (op[0] == '*') {
				result *= atof(next);
			}
			else if (op[0] == '-') {
				result -= atof(next);
			}
			else if (op[0] == '/') {

				double val = atof(next);
				// checks if therse 0 in the token (next) and 
				if (val == 0.0) {
					printf("Not devisivle by zero\n");
				}else{
					result /= val;
				}
			}
		}
		
		printf("%f\n", result);
		

	}




	



}