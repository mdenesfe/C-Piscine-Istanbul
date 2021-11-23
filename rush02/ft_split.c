#include "ft.h"

int	ft_isspace(char *str)
{
	return (*str == 32 || (*str >= 9 && *str <= 13));
}

char	*ft_split(char *tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i] != ':')
		i++;
	i++;
	while (ft_isspace(&tab[i]) == 1)
		i++;
	while (tab[i] != '\0')
	{
		if (!(ft_isspace(&tab[i]) && ft_isspace(&tab[i + 1])))
		{
			tab[j] = tab[i];
			tab[i] = ' ';
			j++;
		}
		i++;
	}
	tab[j - 1] = '\0';
	return (tab);
}
