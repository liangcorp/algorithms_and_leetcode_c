#include <stdio.h>
#include <stdlib.h>

int reverse(int x)
{
	int is_possitive = 1;
	if (x < 0) {
		is_possitive = 0;
	}

	int no_of_ten = abs(x) % 10;

	char result_array[no_of_ten];
	char str[no_of_ten];

	sprintf(str, "%d", abs(x));

	for (int i = no_of_ten - 1; i >= 0; i--) {
		result_array[no_of_ten - i - 1] = str[i];
	}

	if (is_possitive == 0) {
		return atoi(result_array) * -1;
	}
	return atoi(result_array);
}

int main()
{
	printf("%d\n", reverse(120));
}
