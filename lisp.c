#include <stdio.h>
#include <stdlib.h>

// operations to be used in expressions

#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'
#define PROP ':'
#define EQU '='
#define PER '%'
#define WHAT '?'
#define SUM '{'

// to loop the lisp calculator until user quits.

#define YES 1
#define NO 0


// lisp calc function.
int lisp_calc(char op, float a, float b);

int main() {
	int quit = NO;
	char user_operator = '\0';   		  // operator.
	float a, b = 0;  					 // numerical values.
	int res = 0;  						// response from user.


	while (quit == NO) {
		
		printf("Enter the expression: \n");
		scanf("%c %f %f", &user_operator, &a, &b);
		fflush(stdin);  // flush newline out.

		lisp_calc(user_operator, a, b);
	
		printf("Do you want to quit? 1 or 0: \n");
		scanf("%d", &res);
		fflush(stdin);  // used as above.

		if (res == 1) {
			quit = YES;
		} else {
			quit = NO;
		}

		// clean up
		user_operator = '\0';
		a = b = 0;
		res = 0;


	}
	
	return 0;
}

int lisp_calc(char op, float a, float b) {
	float result = 0;      // to store the answer.
	float item, value = 0;
	float item2, value2 = 0;
	float factor = 0;       
	char item_unit[5], val_unit[5];    // 62-65: for proportion part. 
	
	float percent, discount = 0;   // calculating percent and discount.
 

	// 72-156 instructions for the lisp calculator.

	switch (op) {
		case ADD:
		{
			result = a+b;
			printf("result = %.1f\n", result);
			break;
		}

		case SUB:
		{
			result = a-b;
			printf("result = %.1f\n", result);
			break;
		}
 
		case MUL:
		{
			result = a*b;
			printf("result = %.1f\n", result);
			break;
		}

		case DIV:
		{
			result = a/b;
			printf("result = %.1f\n", result);
			break;
		}

		case EQU:
		{
			if (a == b) {
				printf("%.1f = %.1f\n", a, b);
			} else {
				printf("%.1f != %.1f\n", a, b);
			}
			break;
		}

		case WHAT:
		{
			if (a > b) {
				printf("%.1f must be subtracted from %.1f to get %.1f.\n", (a - b), a, b);
			} else if (a < b) {
				printf("%.1f must be added to %.1f to get %1f.\n", (b - a), a, b);
			}
			break;
		}

		case PROP:
		{
			item = a;
			value = b;
			printf("\nEnter the unit for item and value: \n");
			scanf("%s %s", item_unit, val_unit);
			printf("%.1f %s : %.1f %s\n", a, item_unit, b, val_unit);
			factor = value / item;

			printf("\n1 %s: %.1f %s\n", item_unit, factor, val_unit);
			printf("\nEnter for which you want to find the value: \n");
			scanf("%f", &item2);

			
			value2 = factor * item2;

			result = value2;
			printf("\nresult = %.1f %s\n", result, val_unit);

			break;

		}

		case PER:
		{
			percent = ((a / 100) * b);
			discount = b - percent;
			printf("price to be deducted = %.1f\n", percent);
			printf("discount = %.1f\n", discount);

			break;
		}
		case SUM:
		{
			for (int k = a; k <= b; k++)
				result += k;
			printf("Summation: %.1f\n", result);
			break;
		}
		 
		default:
	   printf("Invalid operator please input +, -, *, / ") ;
	}

	return 0;
}
