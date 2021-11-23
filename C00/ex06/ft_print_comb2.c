#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	ascii(char n, int digit)
{
	char	d;

	if (digit == 1)
	{
		d = n / 10 + '0';
	}
	else
	{
		d = n % 10 + '0';
	}
	return (d);
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;

	a = -1;
	while (a++ < 99)
	{
		b = a;
		while (b++ < 99)
		{
			if (!(a == 0 && b == 1))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			ft_putchar(ascii(a, 1));
			ft_putchar(ascii(a, 0));
			ft_putchar(' ');
			ft_putchar(ascii(b, 1));
			ft_putchar(ascii(b, 0));
		}
	}
}
