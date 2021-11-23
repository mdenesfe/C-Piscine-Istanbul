#include <unistd.h>

void	ft_is_negative(int n)
{
	char	b;

	if (n >= 0)
	{
		b = 'P';
	}
	else
	{
		b = 'N';
	}
	write(1, &b, sizeof(b));
}
