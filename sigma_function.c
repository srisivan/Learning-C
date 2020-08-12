#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float sigma(float start, float end, char operator, float num);

int main()
{
	float start, end = 0;
	float num = 0;
	char operator;
	float result = 0;

	printf("\nEnter the start and the end of the sigma function:\n");
	scanf("%f %f", &start, &end);
	fflush(stdin);

	printf("\n+ - * / ^.\n");
	printf("Enter the operator for the condition: \n");
	scanf(" %c", &operator);
	fflush(stdin);

	printf("\nEnter the number to be operated on in the condition (to add only numbers, 0): \n");
	scanf("%f", &num);
	fflush(stdin);

	result = sigma(start, end, operator, num);

	printf("\nThe result of sigma function is: %.2f\n", result);

	return 0;
}


float sigma(float start, float end, char operator, float num)
{
	int n = 0;
	float element = 0;
	float result = 0;

	printf("\nNumbers to be added: \n\n");
	for (n = start; n <= end; n++)
	{
		switch (operator)
		{
			
			case '+':
			{
				element = n + num;
				break;
			}
			case '-':
			{
				element = n - num;
				break;
			}
			case '*':
			{
				element = n * num;
				break;
			}
			case '/':
			{
				element = n / num;
				break;
			}
			case '^':
			{
				element = pow(n, num);
				break;
			}
			default:
			{
				break;
			}
		}
		printf(" %.2f\n", element);
		result += element;
	}

	return result;
}
