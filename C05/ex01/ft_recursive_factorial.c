#include <unistd.h>

int	ft_recursive_factorial_recursive(int fucktorial, int num)
{
	fucktorial *= num--;
	if (num > 0)
		return (ft_recursive_factorial_recursive(fucktorial, num));
	return (fucktorial);
}

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	return (ft_recursive_factorial_recursive(1, nb));
}
