#include <unistd.h>

char	*ft_strstr(char *str, char *f)
{
	int	i;
	int	j;

	i = 0;
	if (f[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == f[j] && str[i + j] != '\0')
		{
			if (f[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}
