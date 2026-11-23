#include <stdio.h>

// Define a constant macro.
#define APP_NAME "Simple Example"
#define SQUARE(value) ((value) * (value))

/*
 * This program demonstrates basic preprocessor macros,
 * a single-line comment, and a multi-line comment.
 */
int main(void)
{
	int number = 5;

	printf("%s\n", APP_NAME);
	printf("The square of %d is %d.\n", number, SQUARE(number));

	return 0;
}
