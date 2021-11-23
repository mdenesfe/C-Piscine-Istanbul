#include <stdlib.h>
#include <stdio.h>

int	check(int min, int max, int **range)
{
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	return (1);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	bound;
	int	index;
	int	*buffer;
	int	*d;

	if (check(min, max, range) == 0)
		return (0);
	bound = max - min;
	(buffer = malloc(bound * sizeof(int)));
	d = buffer;
	if (!d)
	{
		*range = 0;
		return (-1);
	}
	*range = buffer;
	index = 0;
	while (index < bound)
	{
		buffer[index] = min + index;
		index++;
	}
	return (bound);
}
/*
int		main(void)
{
	int	min;
	int	max;
	int	*tab;
	int	size;
	int	i = 0;

	min = 2003;
	max = 2011;
	size = ft_ultimate_range(&tab, min, max);
	while(i < size)
	{
		printf("%d, ", tab[i]);
		i++;
	}

}*/
