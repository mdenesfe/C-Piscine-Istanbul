#include <unistd.h>
#include <stdlib.h>
#include "tools.h"
#include "map.h"
#define BUFF_SIZE 8192

char	*g_buff;
char	*g_tmp;
char	*g_input;
int		g_len;

char	*ft_read_until(int fd, char c)
{
	g_buff = malloc(sizeof(*g_buff));
	if (!g_buff)
		return (0);
	g_input = malloc(sizeof(*g_input));
	if (!(g_input))
		return (0);
	g_input[0] = '\0';
	g_len = 0;
	while (read(fd, g_buff, 1) > 0 && *g_buff != c)
	{
		g_len++;
		g_tmp = g_input;
		g_input = malloc(sizeof(*g_input) * (++g_len + 1));
		if (!g_input)
			return (0);
		g_input[0] = '\0';
		ft_strcat(g_input, g_tmp);
		ft_strncat(g_input, g_buff, 1);
		free(g_tmp);
	}
	g_input[g_len] = '\0';
	return (g_input);
}

int	ft_complete_map(t_map_params *map, char *params)
{
	int		i;
	int		len;
	char	*lines;

	len = 0;
	while (params[len] != '\0')
		len++;
	lines = (char *)malloc(sizeof(char) * (len - 3 + 1));
	if (!lines)
		return (0);
	i = 0;
	while (params[i + 3] != '\0')
	{
		lines[i] = params[i];
		i++;
	}
	lines[i] = '\0';
	map->lines = ft_atoi(lines);
	map->empty = params[i++];
	map->obstacles = params[i++];
	map->fill = params[i];
	return (1);
}

char	*g_str;

char	*ft_read_file(int fd, t_map_params *map)
{
	int		i;
	char	*tmp;

	ft_complete_map(map, ft_read_until(fd, '\n'));
	tmp = ft_read_until(fd, '\n');
	map->columns = ft_strlen(tmp) + 1;
	if (map->lines <= 0)
		return (0);
	g_str = (char *)malloc(sizeof(*g_str) * (map->lines * map->columns));
	if (!(g_str))
		return (0);
	g_str[0] = '\0';
	ft_strcat(g_str, tmp);
	g_str[map->columns - 1] = '\n';
	g_str += map->columns;
	i = read(fd, g_str, (map->lines - 1) * map->columns);
	if (i < 0)
		return (0);
	if (i != (map->lines - 1) * map->columns)
		return (0);
	g_str -= map->columns;
	if (read(fd, tmp, 1) > 0 || g_str[map->lines * map->columns - 1] != '\n')
		return (0);
	g_str[map->lines * map->columns - 1] = '\0';
	return (g_str);
}
