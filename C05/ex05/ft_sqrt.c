#include <unistd.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		return (0);
	while (i * i < (unsigned int) nb)
		i++;
	if (i * i == (unsigned int) nb)
		return (i);
	return (0);
}
