#include <unistd.h>

int	ft_is_prime(int nb)
{
	int	asal;

	asal = 2;
	if (nb < 2)
		return (0);
	while (asal <= nb / 2)
	{
		if (nb % asal == 0)
			return (0);
		asal++;
	}
	return (1);
}
