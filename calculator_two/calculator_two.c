#include<stdio.h>
#include<stdlib.h>

int main() {

	char num1[20];
	char middle[20];
	char num2[20];
	double running = 1;



	while (running == 1) {

		printf("\nEnter digit to begin calculation!!\n");
		scanf_s("%s", num1, (unsigned)sizeof(num1));

		if (num1[0] == 'q') {
			running = 0;
			break;
		}

		printf("\nEnter tool to begin calculation!!\n");
		scanf_s("%s", middle, (unsigned)sizeof(middle));

		if (middle[0] == 'q') {
			running = 0;
			break;
		}
		printf("\nEnter second digit to begin calculation!!\n");
		scanf_s("%s", num2, (unsigned)sizeof(num2));

		if (num2[0] == 'q') {
			running = 0;
			break;
		}

		else {
			double value1 = atof(num1);
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

}