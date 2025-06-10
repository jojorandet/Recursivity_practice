
#include <stdio.h>

int	array_sum(int *array, int len)
{
	if (len == 0)
		return (0);
	else
		return (*array + array_sum(array + 1, len - 1));
}


int main()
{
	int	array[6] = {0, 1, 2, 3, 4, 5};
	int len = sizeof(array) / sizeof(array[0]);
	printf("the sum of the array is %d\n", array_sum(array, len));
	return (0);
}
