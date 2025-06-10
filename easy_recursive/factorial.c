
#include "stdio.h"

/** 
 * the base case of the recursion is if the numnber is equal to 0 or 1, 
 * in both cases you need to return 1.
 * then the recursive call:asm
 * 1. I will plunge inside the recursive using n - 1
 * 2. then when i reach the base case i will go back up by multiplying 
 * by n
 * 3. i will only return once the recursion springs back to the original :)
 */
int	ft_factorial(int n)
{
	if (n == 0 || n == 1)
		return (1);
	return (n * ft_factorial(n - 1));
}

int	main()
{
	int	n;

	n = 5;
	printf("%d\n", ft_factorial(n));
	return (0);
}
