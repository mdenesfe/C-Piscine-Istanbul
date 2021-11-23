#include "ft.h"

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (count_total(tab[i]) > count_total(tab[j]))
			{
				temp = tab[j];
				tab[j] = tab[i];
				tab[i] = temp;
			}
			j++;
		}
		i++;
	}
}

int	count_lines(int fd)
{
	int		count;
	char	buf[2];
	int		ret;

	count = 0;
	ret = 1;
	while (ret)
	{
		(ret = read(fd, buf, 1));
		if (buf[0] == '\n')
			count++;
	}
	return (count);
}

void	malloc_tab(char **tab, int fd)
{
	int		i;
	int		count;
	char	buf[2];
	int		ret;

	i = 0;
	count = 0;
	ret = 1;
	while (ret)
	{
		(ret = read(fd, buf, 1));
		i++;
		if (buf[0] == '\n')
		{
			(tab[count] = malloc(sizeof(char *) * (i + 1)));
			if (!tab[count])
				return ;
			i = 0;
			count++;
		}
	}
	tab[count] = NULL;
}

void	read_and_fill(char **tab, int fd)
{
	int		i;
	int		count;
	char	buf[2];
	int		ret;

	i = 0;
	count = 0;
	ret = 1;
	(ret = read(fd, buf, 1));
	while (ret)
	{
		tab[count][i] = buf[0];
		tab[count][i + 1] = '\0';
		i++;
		if (buf[0] == '\n')
		{
			i = 0;
			count++;
		}
		(ret = read(fd, buf, 1));
	}
	tab[count] = NULL;
}
char	**g_tab;
int		g_fd;

char	**parse_dictionary(void)
{
	int	i;

	g_fd = open(DICT_FILE_E, O_RDONLY);
	g_tab = malloc(sizeof(char *) * (count_lines(g_fd) + 1));
	if ((g_fd) == -1 || !(g_tab)
		|| close(g_fd) == -1)
		ft_putstr(DICT_ERROR);
	g_fd = open(DICT_FILE_E, O_RDONLY);
	if ((g_fd) == -1)
		return (g_tab);
	malloc_tab(g_tab, g_fd);
	if (close(g_fd) == -1)
		ft_putstr(DICT_ERROR);
	g_fd = open(DICT_FILE_E, O_RDONLY);
	if (g_fd == -1)
		return (g_tab);
	read_and_fill(g_tab, g_fd);
	ft_sort_string_tab(g_tab);
	if (close(g_fd) == -1)
		ft_putstr(DICT_ERROR);
	i = -1;
	while (g_tab[++i])
		ft_split(g_tab[i]);
	return (g_tab);
}
