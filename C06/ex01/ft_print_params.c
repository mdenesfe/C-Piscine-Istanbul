#include <unistd.h>

int	main(int ac, char **av)
{
	int	c;
	int	d;

	c = 1;
	d = 0;
	if (ac > 1)
	{
		while (c < ac)
		{
			d = 0;
			while (av[c][d] != '\0')
			{
				write(1, &av[c][d], 1);
				d++;
			}
			write(1, "\n", 1);
			c++;
		}
	}
	return (0);
}
