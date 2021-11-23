#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	huso;

	huso = *a;
	*a = *b;
	*b = huso;
}
