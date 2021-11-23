#include "ft.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write (1, str, 1);
		str++;
	}
}

int	zero_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	count_total(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (str[i] == '0' && (!(str[i + 1] >= '0' && str[i + 1] <= '9')))
		return (0);
	while (str[i] != ':' && str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '9')
			count = count + str[i];
		else if (str[i] == '0')
			count += 100;
		i++;
	}
	return (count);
}
