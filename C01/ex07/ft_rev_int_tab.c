#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	size --;
	while (i < size)
	{
		j = tab[i];
		tab[i] = tab[size];
		tab[size] = j;
		i++;
		size--;
	}
}
