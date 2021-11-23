#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int	d;

	d = 0;
	while (str[d] != '\0')
	{
		if ((str[d] < 32) || (str[d] > 126))
			return (0);
		d++;
	}
	return (1);
}
