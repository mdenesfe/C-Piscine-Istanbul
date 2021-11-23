#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	fuck;
	int	index;

	if (nb < 0)
		return (0);
	fuck = 1;
	index = 1;
	while (index < nb + 1)
		fuck = fuck * index++;
	return (fuck);
}
