#include <stdlib.h>
//#include <string.h>
//#include <stdio.h>

int	ft_str_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;
	char	*d;

	i = 0;
	d = ((dest = (char *)malloc(ft_str_length(src) * sizeof(char) + 1)));
	if (!d)
	{
		return (0);
	}
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int		main(void)
{
	char	*str;
	char	*tahsis;

	str = "Abdullah Karaca için yer ayır.";
	printf("ilk çıktı : %s\n", str);
	tahsis = ft_strdup(str);
	printf("kopyaladıktan sonra tahsis ettiği yer : %s\n", tahsis);
}*/
